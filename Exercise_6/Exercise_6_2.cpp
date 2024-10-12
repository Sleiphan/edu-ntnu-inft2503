#include "http_message.h"
#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer
{
private:
  class Connection
  {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  std::string landing_page;
  std::string another_page;
  std::string not_found;

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection)
  {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n\r\n", [this, connection, read_buffer](const boost::system::error_code &ec, size_t bytes_read)
                     {
      if (!ec)
      {
        boost::asio::streambuf::const_buffers_type bufs = (*read_buffer).data();
        std::string message(boost::asio::buffers_begin(bufs), boost::asio::buffers_begin(bufs) + bytes_read);
        http_message msg = string_to_http(message);

        std::string& response = not_found;
        if (msg.path == "/")
          response = landing_page;
        if (msg.path == "/en_side")
          response = another_page;

        auto write_buffer = make_shared<boost::asio::streambuf>();
        ostream write_stream(write_buffer.get());

        // Add message to be written to client:
        write_stream << response;

        // Write to client
        async_write(connection->socket, *write_buffer, [this, connection, write_buffer](const boost::system::error_code &ec, size_t)
        {
          if (!ec)
            handle_request(connection);
        });
      } });
  }

  void accept()
  {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_service);

    // Accepts a new (client) connection. On connection, immediately start accepting a new connection
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec)
                          {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      } });
  }

public:
  EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint)
  {
    http_message landing_page_msg;
    landing_page_msg.protocol = "HTTP/1.1";
    landing_page_msg.method = "200 OK";
    landing_page_msg.body = "<h1>Dette er hovedsiden</h1>";
    landing_page_msg.headers.push_back(http_header("Content-Length", std::to_string(landing_page_msg.body.length())));
    landing_page_msg.headers.push_back(http_header("Content-Type", "text/html"));

    landing_page = http_response_to_string(landing_page_msg);

    http_message another_page_msg;
    another_page_msg.protocol = "HTTP/1.1";
    another_page_msg.method = "200 OK";
    another_page_msg.body = "<h2>Dette er en side</h2>";
    another_page_msg.headers.push_back(http_header("Content-Length", std::to_string(another_page_msg.body.length())));
    another_page_msg.headers.push_back(http_header("Content-Type", "text/html"));

    another_page = http_response_to_string(another_page_msg);

    http_message not_found_msg;
    not_found_msg.protocol = "HTTP/1.1";
    not_found_msg.method = "404 Not Found";
    not_found_msg.body = "<h1>404 Not Found</h1>";
    not_found_msg.headers.push_back(http_header("Content-Length", std::to_string(not_found_msg.body.length())));
    not_found_msg.headers.push_back(http_header("Content-Type", "text/html"));

    not_found = http_response_to_string(not_found_msg);
  }

  void start()
  {
    accept();

    io_service.run();
  }
};

int main()
{
  EchoServer echo_server;

  cout << "Starting web server on port 8080" << endl;
  cout << "Try connecting to it with a browser! " << endl;
  cout << "Available endpoints: http://127.0.0.1:8080/, http://127.0.0.1:8080/en_side" << endl;

  echo_server.start();
}
