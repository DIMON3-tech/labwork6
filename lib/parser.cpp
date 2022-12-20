#include "parser.h"
#include <iostream>
#include <fstream>
// C:\Users\dimab\Downloads\test_for_omfl_file.txt

bool omfl::ParserOMFL::valid() {
    return vector_multi_values[vector_multi_values.size() - 1].is_valid;
}

omfl::ParserOMFL& omfl::parse(const std::filesystem::path& path) {
    std::ifstream file;
    file.open(path);
    if (file.is_open() == false) {
        std::cout << "File was not open" << std::endl;
    }
}

omfl::ParserOMFL& omfl::parse(std::string str) {
    bool valid = true;
    std::string service_value;
    std::string key_name;
    int int_key_value;
    std::string string_key_value;
    bool bool_key_value;
    int prev_index_equal = 0;
    int next_index_equal = 0;
    std::string valid_value = "-_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int count_of_equal = std::count(str.begin(), str.end(), '=');
    // gey key's name
    for (int j = 0; j < count_of_equal; ++j) {
        next_index_equal = str.find('=');
        for (int i = prev_index_equal; i < next_index_equal; ++i) {
            // check for valid
            if (valid_value.find(str[i]) == -1) {
                valid = false;
            }
            if (key_name[i] != ' ' && key_name[i] != '\n') {
                key_name += str[i];
            }
//            if (str[i] != ' ') {
//                service_value += str[i];
//            }

        }
        prev_index_equal = next_index_equal;
    }

    if (valid == true) { // if key_name is valid start to read key_value


        // detect value's type and write in certain variable
        // bool value true
        bool all_elements_is_numbers = true;
        if (service_value == "true") {
            omfl::MultiValueClass multiValueClass;
            multiValueClass.bool_key_value = true;
            multiValueClass.type_of_value = '2';
            multiValueClass.key_name = key_name;
            multiValueClass.is_valid = valid;
            omfl::ParserOMFL::vector_multi_values.push_back(multiValueClass);
            // bool value false
        } else if (service_value == "false") {
            omfl::MultiValueClass multiValueClass;
            multiValueClass.bool_key_value = false;
            multiValueClass.type_of_value = '2';
            multiValueClass.key_name = key_name;
            multiValueClass.is_valid = valid;
            omfl::ParserOMFL::vector_multi_values.push_back(multiValueClass);

        } else {
            for (int i = 0; i < service_value.length(); ++i) {
                if (std::isdigit(service_value[i]) == -1) {
                    all_elements_is_numbers = false;
                }
            }
            // int value
            if (all_elements_is_numbers == true) {
                int_key_value = std::stoi(service_value);
                omfl::MultiValueClass multiValueClass;
                multiValueClass.key_name = key_name;
                multiValueClass.int_key_value = int_key_value;
                multiValueClass.type_of_value = '0';
                multiValueClass.is_valid = valid;
                omfl::ParserOMFL::vector_multi_values.push_back(multiValueClass);
            } else {
                // string value
                string_key_value = service_value;
                omfl::MultiValueClass multiValueClass;
                multiValueClass.key_name = key_name;
                multiValueClass.string_key_value = string_key_value;
                multiValueClass.type_of_value = '1';
                multiValueClass.is_valid = valid;
                omfl::ParserOMFL::vector_multi_values.push_back(multiValueClass);
            }
        }
    }
}
