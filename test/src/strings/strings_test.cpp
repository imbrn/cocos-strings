#include <catch.hpp>
#include <strings/strings.h>
#include <cocos2d.h>

using namespace strings;

TEST_CASE("Strings.get_string") {
  Strings strings(cocos2d::FileUtils::getInstance()->getStringFromFile("strings.json"));
  REQUIRE(strings.get_string("name") == "Cocos Strings");
  REQUIRE(strings.get_string("version") == "1.0");
  REQUIRE(strings.get_string("other", "no value") == "no value");
}

TEST_CASE("Strings.get_strings") {
  Strings strings(cocos2d::FileUtils::getInstance()->getStringFromFile("strings.json"));
  REQUIRE(strings.get_strings("values") == std::vector<std::string>({
    "A", "B", "C"
  }));
}
