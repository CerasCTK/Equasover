#include "string.h"

#include <iostream>

#include "../../util/string_helper/string_helper.h"

namespace da_ty {
    string::string() {
        this->data = new char;
        this->string_length = 0;
    }

    string::string(const char* data) {
        this->string_length = string_helper::strlen(data) + 1;
        this->data = new char[this->string_length];

        string_helper::strcpy(this->data, data);
    }

    string::string(const string& other) {
        this->string_length = other.string_length;

        this->data = new char[this->string_length];

        string_helper::strcpy(this->data, other.data);
    }

    string::string(string&& other) {

    }

    string::~string() {
        if (this->data != nullptr)
            delete this->data;
    }

    int string::get_length() {
        return this->string_length;
    }

    char* string::c_str() {
        return this->data;
    }

    std::ostream& operator<<(std::ostream& output, const string& string) {
        output << string.data << std::endl;
        return output;
    }

    std::istream& operator>>(std::istream& input, string& string) {
        
        return input;
    }
}