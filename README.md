Cocos Strings
===

[Cocos2d-x](http://cocos2d-x.org/) helping tool to work with strings files.

This tool was developed to provide an easy way to read strings from a file.


## How to use

* Add `cocos2d/external` to include directories.

* Add the project files to your include directories and path.

* Create json:

```json
{
    "name": "My name",
    "other_key": "Other key value",
    "many_strings": ["string one", "string two", "string three"]
}
```

* In your code:

```c++
    auto my_strings = strings::Strings::fromJsonFile("strings.json");

    // Ready single string
    auto name = my_strings.get_string("name");

    // Ready many strings
    auto many_strings = my_strings.get_strings("many_strings");
}
```


## Dependencies 

* [Cocos2d-x](http://cocos2d-x.org/) 3.14 or higher.
