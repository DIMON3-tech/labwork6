#pragma once

#include <filesystem>
#include <istream>


namespace omfl {

    class MultiValueClass {

    public:
        std::string key_name;
        std::string string_key_value;
        int int_key_value;
        bool bool_key_value;
        char type_of_value = '3'; // 0-int, 1-string, 2-bool, 3- no value
        bool is_valid;
    };

    struct ParserOMFL {
        inline static std::vector<MultiValueClass> vector_multi_values = {};
        friend omfl::ParserOMFL& parse(const std::filesystem::path& path);
        friend omfl::ParserOMFL& parse(std::string str);
        bool valid();
    };
    omfl::ParserOMFL& parse(const std::filesystem::path& path);
    omfl::ParserOMFL& parse(std::string str);

}// namespace