#include "string.h"

#include <iostream>
#include <cstring>

#include "../exception/my_exception.h"

#include "../../util/string_helper/string_helper.h"

namespace da_ty {
    string::string() {
        this->data = new uint8_t;
        *this->data = END_STRING_CHAR;
    }

    string::string(const uint8_t *data) {
        if (data == nullptr) {
            this->data = new uint8_t;
            *this->data = END_STRING_CHAR;
        } else {
            int32_t string_length{string_helper::strlen(data) + END_STRING_COUNT};
            this->data = new uint8_t[string_length];

            string_helper::strcpy(this->data, data);
        }
    }

    string::string(const string &other) {
        int32_t string_length{string_helper::strlen(other.data) + END_STRING_COUNT};

        this->data = new uint8_t[string_length];

        string_helper::strcpy(this->data, other.data);
        *(this->data + string_length - 1) = END_STRING_CHAR;
    }

    string::string(string &&other) {
        this->data = other.data;
        other.data = nullptr;
    }

    string::~string() {
        if (this->data != nullptr)
            delete this->data;
    }

    int string::length() {
        return string_helper::strlen(this->data);
    }

    uint8_t *string::c_str() {
        return this->data;
    }

    std::ostream &operator<<(std::ostream &os, const string &obj) {
        os << obj.data;
        return os;
    }

    std::istream &operator>>(std::istream &is, string &obj) {
        uint8_t *buff{new uint8_t[MAX_STRING_LENGTH_DEFAULT]};
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
        int32_t string_length{string_helper::strlen(other.data) + END_STRING_COUNT};
        this->data = new uint8_t[string_length];
        string_helper::strcpy(this->data, other.data);
        return *this;
    }

    string &string::operator=(const uint8_t *text) {
        if (string_helper::strcmp(this->data, text))
            return *this;

        delete this->data;

        int32_t string_length{string_helper::strlen(text) + END_STRING_COUNT};
        this->data = new uint8_t[string_length];
        string_helper::strcpy(this->data, text);
        return *this;
    }

    string operator+(const string &left, const string &right) {
        int32_t new_length{string_helper::strlen(left.data) + string_helper::strlen(right.data) + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};

        string_helper::strcpy(buff, left.data);
        string_helper::strcat(buff, right.data);

        buff[new_length - 1] = END_STRING_CHAR;

        string temp {buff};

        delete[] buff;

        return temp;
    }

    string operator+(const string &left, const uint8_t *text) {
        int32_t new_length{string_helper::strlen(left.data) + string_helper::strlen(text) + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};

        string_helper::strcpy(buff, left.data);
        string_helper::strcat(buff, text);

        buff[new_length - 1] = END_STRING_CHAR;

        string temp {buff};

        delete[] buff;

        return temp;
    }

    bool string::operator==(string other) {
        return string_helper::strcmp(this->data, other.data);
    }

    bool string::operator==(const uint8_t *text) {
        return string_helper::strcmp(this->data, text);
    }

    da_st::array_list<string> *string::split(const uint8_t split_char) {
        using namespace da_st;
        array_list<string> *list = new array_list<string>;

        while (*(this->data) != '\0') {

        }

        return list;
    }

    uint8_t &string::at(int32_t index) {
        if (index >= this->length())
            throw my_exception((uint8_t *) ("Index out of bound"));
        return *(this->data + index);
    }

    void string::push_back(uint8_t c) {
        int32_t new_length{string_helper::strlen(this->data) + 1 + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};
        string_helper::strcpy(buff, this->data);
        buff[new_length - 2] = c;
        buff[new_length - 1] = END_STRING_CHAR;

        delete this->data;

        this->data = buff;
    }

    string string::clone() {

        return string();
    }
}