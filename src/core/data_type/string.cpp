#include "string.h"

#include <iostream>
#include <cstring>

#include "../../util/string_helper/string_helper.h"

#define MAX_STRING_LENGTH_DEFAULT 1000

namespace da_ty {
    string::string() {
        this->data = new char;
        *this->data = '\0';
    }

    string::string(const char *data) {
        if (data == nullptr) {
            this->data = new char;
            *this->data = '\0';
        } else {
            int string_length = string_helper::strlen(data) + 1;
            this->data = new char[string_length];

            string_helper::strcpy(this->data, data);
        }
    }

    string::string(const string &other) {
        int string_length = string_helper::strlen(other.data) + 1;

        this->data = new char[string_length];

        string_helper::strcpy(this->data, other.data);
        *(this->data + string_length - 1) = '\0';
    }

    string::string(string &&other) {
        this->data = other.data;
        other.data = nullptr;
    }

    string::~string() {
        if (this->data != nullptr)
            delete this->data;
    }

    int string::get_length() {
        return string_helper::strlen(this->data);
    }

    char *string::c_str() {
        return this->data;
    }

    std::ostream &operator<<(std::ostream &os, const string &obj) {
        os << obj.data;
        return os;
    }

    std::istream &operator>>(std::istream &is, string &obj) {
        char *buff = new char[MAX_STRING_LENGTH_DEFAULT];
        memset(&buff[0], 0, sizeof(buff));
        is >> reinterpret_cast<bool &>(buff);
        obj = string{buff};
        delete[] buff;
        return is;
    }

    string &string::operator=(const string &other) {
        if (this == &other)
            return *this;

        delete this->data;
        int string_length = string_helper::strlen(other.data) + 1;
        this->data = new char[string_length];
        string_helper::strcpy(this->data, other.data);
        return *this;
    }

    string operator+(const string &left, const string &right) {
        int string_length = string_helper::strlen(left.data) + string_helper::strlen(right.data) + 1;
        return string();
    }

}