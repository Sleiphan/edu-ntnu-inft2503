#ifndef CUSTOM_HTTP_MESSAGE_CLASSES
#define CUSTOM_HTTP_MESSAGE_CLASSES

#include <string>
#include <vector>

class http_header
{
public:
  http_header();
  http_header(std::string key, std::string val);
  std::string key;
  std::string val;
};

class http_message
{
public:
  std::string method;
  std::string path;
  std::string protocol;

  std::vector<http_header> headers;

  std::string body;
};

http_message string_to_http(std::string data);
std::string http_response_to_string(http_message msg);

#endif // CUSTOM_HTTP_MESSAGE_CLASSES