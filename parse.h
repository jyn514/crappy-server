#include <string>
#include <map>

enum method {
  GET, ERROR
};

struct request_info {
  enum method method;
  std::string url;
};

struct request_info process_request_line(std::string&);
std::map<std::string, std::string> process_headers(std::string&);
