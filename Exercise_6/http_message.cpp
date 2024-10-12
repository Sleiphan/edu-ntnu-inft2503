#include "http_message.h"
#include <boost/algorithm/string.hpp>

http_header::http_header() {};
http_header::http_header(std::string key, std::string val) : key(key), val(val) {};

http_header http_header_from_string(std::string header_string)
{
  http_header header;

  int val_start = header_string.find(':');

  header.key = header_string.substr(0, val_start);

  while (header_string.at(++val_start) == ' ')
    ;

  header.val = header_string.substr(val_start, header_string.length() - val_start);

  return header;
}

http_message string_to_http(std::string data)
{
  http_message msg;

  int req_end = data.find(" ", 0);
  msg.method = data.substr(0, req_end);

  ++req_end;
  int path_end = data.find(" ", req_end);
  msg.path = data.substr(req_end, path_end - req_end);

  ++path_end;
  int protocol_end = data.find("\r\n", path_end);
  msg.protocol = data.substr(path_end, protocol_end - path_end);

  int header_start = protocol_end + 2;
  int header_end = data.find("\r\n", header_start);

  size_t content_length = 0;

  while (header_end - header_start > 0)
  {
    http_header header = http_header_from_string(data.substr(header_start, header_end - header_start));
    msg.headers.push_back(header);
    header_start = header_end + 2;
    header_end = data.find("\r\n", header_start);

    std::string header_key = boost::to_lower_copy(header.key);
    if (header_key == "content-length")
      content_length = atoi(header.val.c_str());
  }

  header_end += 2;

  size_t body_length = content_length > data.length() - header_end ? content_length : data.length() - header_end;

  msg.body = data.substr(header_end, body_length);

  return msg;
}

std::string http_response_to_string(http_message msg)
{
  std::string ln = "\r\n";
  std::string headers = "";

  for (http_header h : msg.headers)
    headers.append(h.key + ": " + h.val + ln);

  std::string message = msg.protocol + " " + msg.method + ln + headers + ln + msg.body;

  return message;
}