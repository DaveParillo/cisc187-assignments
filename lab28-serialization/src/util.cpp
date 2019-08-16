#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <utility>

#include <json.hpp>

#include "util.h"

using std::string;
using json = nlohmann::json;

string decode(const string& source) {
  // TODO: this would much more efficient if
  // instead of iterating over every character,
  // jump to each % and +
  std::ostringstream dest;
  for (auto it = source.begin(); it != source.end(); ) {
    if (*it == '%') {
      // if 2 or more  chars away from end of string
      if (std::distance(source.begin(), it) < int(source.length() - 2)) {
        char c = from_hex(*(it+1)) << 4 | from_hex (*(it+2));
        dest << c;
        it += 2;
      }
    } else if (*it == '+') {
      dest << ' ';
    } else {
      dest << *it;
    }
    ++it;
  }
  return dest.str();
}

string json_header (StatusCode code) {
  std::ostringstream head;
  head << "Status: " << int(code) << ' ';

  if (code == StatusCode::ok) {
    head << "OK\n";
  } else if (code == StatusCode::bad) {
    head << "Bad Request\n";
  }
  head << "Content-type: application/json\n\n";

  return head.str();
}

