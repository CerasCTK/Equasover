#include "string.h"

#include <iostream>
#include <cstring>

#include "../../util/string_helper/string_helper.h"

#define MAX_STRING_LENGTH_DEFAULT 1000

namespace da_ty {
    string::string() {
        this->data = new uint8_t;
        *this->data = '\0';
    }

    string::string(const uint8_t *data) {
        if (data == nullptr) {
            this->data = new uint8_t;
            *this->data = '\0';
        } else {
            int32_t string_length{string_helper::strlen(data) + 1};
            this->data = new uint8_t[string_length];

            string_helper::strcpy(this->data, data);
        }
    }

    string::string(const string &other) {
        int32_t string_length{string_helper::strlen(other.data) + 1};

        this->data = new uint8_t[string_length];

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
        int32_t string_length{string_helper::strlen(other.data) + 1};
        this->data = new uint8_t[string_length];
        string_helper::strcpy(this->data, other.data);
        return *this;
    }

    string &string::operator=(const uint8_t *text) {
        if (string_helper::strcmp(this->data, text))
            return *this;

        delete this->data;

        int32_t string_length{string_helper::strlen(text) + 1};
        this->data = new uint8_t[string_length];
        string_helper::strcpy(this->data, text);
        return *this;
    }

    string operator+(const string &left, const string &right) {
        int32_t string_length{string_helper::strlen(left.data) + string_helper::strlen(right.data) + 1};

        uint8_t *buff{new uint8_t[string_length]};

        string_helper::strcpy(buff, left.data);
        string_helper::strcat(buff, right.data);

        buff[string_length] = '\0';

        string temp {buff};

        delete[] buff;

        return temp;
    }

    string operator+(const string &left, const uint8_t *text) {
        int32_t string_length{string_helper::strlen(left.data) + string_helper::strlen(text) + 1};

        uint8_t *buff{new uint8_t[string_length]};

        string_helper::strcpy(buff, left.data);
        string_helper::strcat(buff, text);

        buff[string_length] = '\0';

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
}