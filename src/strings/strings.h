#ifndef STRINGS_STRINGS_H
#define STRINGS_STRINGS_H

#include <json/document.h>
#include <vector>
#include <string>

namespace strings {

///
/// Strings class.
///
class Strings {
  rapidjson::Document document_;

public:
  Strings(const std::string &json_data);
  Strings(Strings &&copy);
  static Strings fromJsonFile(const std::string &file_path);
  virtual ~Strings() {}
  std::string get_string(const std::string &key, const std::string &default_value = "") const;
  std::vector<std::string> get_strings(const std::string &key) const;

private:
  std::vector<std::string> get_strings(const rapidjson::Value &array) const;
  bool ValidateKey(const std::string &key) const;
};

}

#endif
