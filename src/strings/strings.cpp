#include "strings.h"
#include <cocos2d.h>

namespace strings {

Strings::Strings(const std::string &json_data) {
  document_.Parse(json_data.c_str());
}

Strings::Strings(Strings &&copy) {
}

Strings Strings::fromJsonFile(const std::string &file_path) {
  return Strings(cocos2d::FileUtils::getInstance()->getStringFromFile(file_path));
}

std::string Strings::get_string(const std::string &key, const std::string &default_value) const {
  if (ValidateKey(key))
    return document_[key.c_str()].GetString();
  else
    return default_value;
}

std::vector<std::string> Strings::get_strings(const std::string &key) const {
  if (ValidateKey(key))
    return get_strings(document_[key.c_str()]);
  else
    return {};
}

std::vector<std::string> Strings::get_strings(const rapidjson::Value &array) const {
  std::vector<std::string> values;
  for (const auto &next : array.GetArray())
    values.push_back(next.GetString());
  return values;
}

bool Strings::ValidateKey(const std::string &key) const {
  return document_.IsObject() && document_.HasMember(key.c_str());
}

}
