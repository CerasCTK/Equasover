#include "string.h"

#include <iostream>
#include <cstring>

#include "../exception/my_exception.h"

#include "../../util/string_helper/string_helper.h"

namespace da_ty {
    string::string() {
        this->str_data = new uint8_t;
        *this->str_data = END_STRING_CHAR;
    }

    string::string(const string &str) {
        int32_t str_data_len{string_helper::strlen(str.str_data) + END_STRING_COUNT};

        this->str_data = new uint8_t[str_data_len];

        string_helper::strcpy(this->str_data, str.str_data);
        *(this->str_data + str_data_len - 1) = END_STRING_CHAR;
    }

    string::string(const string &str, int32_t pos, int32_t len) {
        if (str.str_data == nullptr) {
            this->str_data = new uint8_t;
            *this->str_data = END_STRING_CHAR;
            return;
        }

        int32_t str_len{string_helper::strlen(str.str_data)};

        len = len == NPOS ? str_len - pos : len;
        len = len > str_len ? str_len : len;

        int32_t str_data_len{len + END_STRING_COUNT};

        this->str_data = new uint8_t[str_data_len];

        for (int32_t i{0}; i < len; i++)
            *(this->str_data + i) = *(str.str_data + pos + i);

        *(this->str_data + str_data_len - 1) = END_STRING_CHAR;
    }

    string::string(const uint8_t *s) {
        if (s == nullptr) {
            this->str_data = new uint8_t;
            *this->str_data = END_STRING_CHAR;
        } else {
            int32_t str_data_len{string_helper::strlen(s) + END_STRING_COUNT};
            this->str_data = new uint8_t[str_data_len];

            string_helper::strcpy(this->str_data, s);
            *(this->str_data + str_data_len - 1) = END_STRING_CHAR;
        }
    }

    string::string(const uint8_t *s, int32_t len) {
        if (s == nullptr) {
            this->str_data = new uint8_t;
            *this->str_data = END_STRING_CHAR;
        } else {
            len = len > string_helper::strlen(s) ? string_helper::strlen(s) : len;

            int32_t str_data_len{len + END_STRING_COUNT};

            this->str_data = new uint8_t[str_data_len];

            for (int32_t i{0}; i < len; i++)
                *(this->str_data + i) = *(s + i);

            *(this->str_data + str_data_len - 1) = END_STRING_CHAR;
        }
    }

    string::string(uint32_t n, uint8_t c) {
        // TODO: Fills the string with n consecutive copies of character c.
        uint32_t str_data_len{n + END_STRING_COUNT};

        for (int32_t i{0}; i < n; i++)
            *(this->str_data + i) = c;

        *(this->str_data + str_data_len - 1) = END_STRING_CHAR;
    }

    string::string(string &&str) noexcept {
        this->str_data = str.str_data;
        str.str_data = nullptr;
    }

    string::~string() {
        if (this->str_data != nullptr)
            delete this->str_data;
    }

    string &string::operator=(const string &str) {
        if (this == &str)
            return *this;

        delete this->str_data;
        int32_t string_length{string_helper::strlen(str.str_data) + END_STRING_COUNT};
        this->str_data = new uint8_t[string_length];
        string_helper::strcpy(this->str_data, str.str_data);
        return *this;
    }

    string &string::operator=(const uint8_t *s) {
        if (string_helper::strcmp(this->str_data, s))
            return *this;

        delete this->str_data;

        int32_t string_length{string_helper::strlen(s) + END_STRING_COUNT};
        this->str_data = new uint8_t[string_length];
        string_helper::strcpy(this->str_data, s);
        return *this;
    }

    string &string::operator=(uint8_t c) {
        if (this->str_data != nullptr)
            delete this->str_data;

        this->str_data = new uint8_t[1 + END_STRING_COUNT];
        *this->str_data = c;
        *(this->str_data + 1) = END_STRING_CHAR;

        return *this;
    }

    string &string::operator=(string &&str) noexcept {
        this->str_data = str.str_data;
        str.str_data = nullptr;

        return *this;
    }

    int32_t string::size() const noexcept {
        return string_helper::strlen(this->str_data);
    }

    int32_t string::length() const noexcept {
        return string_helper::strlen(this->str_data);
    }

    int32_t string::max_size() const noexcept {
        return MAX_STRING_LENGTH;
    }

    void string::resize(int32_t n) {
        // TODO
    }

    void string::resize(int32_t n, uint8_t c) {
        // TODO
    }

    void string::clear() noexcept {
        // TODO
    }

    bool string::empty() const noexcept {
        // TODO
    }

    uint8_t &string::operator[](int32_t pos) {
        // TODO
    }

    const uint8_t &string::operator[](int32_t pos) const {
        if (pos >= this->length())
            throw my_exception((uint8_t *) ("Index out of bound"));
        return *(this->str_data + pos);
    }

    uint8_t &string::at(int32_t index) {
        if (index >= this->length())
            throw my_exception((uint8_t *) ("Index out of bound"));
        return *(this->str_data + index);
    }

    const uint8_t &string::at(int32_t index) const {
        if (index >= this->length())
            throw my_exception((uint8_t *) ("Index out of bound"));
        return *(this->str_data + index);
    }

    uint8_t &string::back() {
        // TODO:
    }

    const uint8_t &string::back() const {
        // TODO
    }

    uint8_t &string::front() {
        // TODO
    }

    const uint8_t &string::front() const {
        // TODO
    }

    string &string::operator+=(const string &str) {
        // TODO:
    }

    string &string::operator+=(const uint8_t *s) {
        // TODO
    }

    string &string::operator+=(uint8_t c) {
        // TODO
    }

    string &string::append(const string &str) {
        // TODO
    }

    string &string::append(const string &str, int32_t sub_pos, int32_t sub_len) {
        // TODO
    }

    string &string::append(const uint8_t *s) {
        // TODO
    }

    string &string::append(const uint8_t *s, size_t n) {
        // TODO
    }

    string &string::append(int32_t n, uint8_t c) {
        // TODO
    }

    void string::push_back(uint8_t c) {
        int32_t new_length{string_helper::strlen(this->str_data) + 1 + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};
        string_helper::strcpy(buff, this->str_data);
        buff[new_length - 2] = c;
        buff[new_length - 1] = END_STRING_CHAR;

        delete this->str_data;

        this->str_data = buff;
    }

    string &string::erase(int32_t pos, int32_t len) {
        // TODO
    }

    string &string::replace(int32_t pos, int32_t len, const string &str, int32_t sub_pos, int32_t sub_len) {
        // TODO
    }

    void string::swap(string &str) {
        // TODO:
    }

    void string::pop_back() {
        // TODO:
    }

    const uint8_t *string::c_str() const noexcept {
        return this->str_data;
    }

    const uint8_t *string::data() const noexcept {
        // TODO
    }

    int32_t string::copy(uint8_t *s, int32_t len, int32_t pos) const {
        // TODO
    }

    int32_t string::find(const string &str, int32_t pos) const {
        // TODO
    }

    int32_t string::find(const uint8_t *s, int32_t pos) const {
        // TODO
    }

    int32_t string::find(const uint8_t *s, int32_t pos, int32_t n) const {
        // TODO
    }

    int32_t string::find(uint8_t c, int32_t pos) const {
        // TODO
    }

    string string::substr(int32_t pos, int32_t len) const {
        // TODO
    }

    string operator+(const string &left, const string &right) {
        int32_t new_length{
                string_helper::strlen(left.str_data) + string_helper::strlen(right.str_data) + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};

        string_helper::strcpy(buff, left.str_data);
        string_helper::strcat(buff, right.str_data);

        buff[new_length - 1] = END_STRING_CHAR;

        string temp{buff};

        delete[] buff;

        return temp;
    }

    string operator+(const string &left, const uint8_t *text) {
        int32_t new_length{string_helper::strlen(left.str_data) + string_helper::strlen(text) + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};

        string_helper::strcpy(buff, left.str_data);
        string_helper::strcat(buff, text);

        buff[new_length - 1] = END_STRING_CHAR;

        string temp{buff};

        delete[] buff;

        return temp;
    }

    string operator+(const uint8_t *lhs, const string &rhs) {
        // TODO
    }

    string operator+(const string &lhs, uint8_t rhs) {
        // TODO
    }

    string operator+(uint8_t lhs, const string &rhs) {
        // TODO
    }

    bool operator==(const string &lhs, const string &rhs) noexcept {
        // TODO
    }

    bool operator==(const uint8_t *lhs, const string &rhs) {
        // TODO
    }

    bool operator==(const string &lhs, const uint8_t *rhs) {
        // TODO
    }

    bool operator!=(const string &lhs, const string &rhs) noexcept {
        // TODO
    }

    bool operator!=(const uint8_t *lhs, const string &rhs) {
        // TODO
    }

    bool operator!=(const string &lhs, const uint8_t *rhs) {
        // TODO
    }

    bool operator<(const string &lhs, const string &rhs) noexcept {
        // TODO
    }

    bool operator<(const uint8_t *lhs, const string &rhs) {
        // TODO
    }

    bool operator<(const string &lhs, const uint8_t *rhs) {
        // TODO
    }

    bool operator<=(const string &lhs, const string &rhs) noexcept {
        // TODO
    }

    bool operator<=(const uint8_t *lhs, const string &rhs) {
        // TODO
    }

    bool operator<=(const string &lhs, const uint8_t *rhs) {
        // TODO
    }

    bool operator>(const string &lhs, const string &rhs) noexcept {
        // TODO
    }

    bool operator>(const uint8_t *lhs, const string &rhs) {
        // TODO
    }

    bool operator>(const string &lhs, const uint8_t *rhs) {
        // TODO
    }

    bool operator>=(const string &lhs, const string &rhs) noexcept {
        // TODO
    }

    bool operator>=(const uint8_t *lhs, const string &rhs) {
        // TODO
    }

    bool operator>=(const string &lhs, const uint8_t *rhs) {
        // TODO
    }


    void string::get_line() {
        if (this->str_data != nullptr)
            delete this->str_data;

        int32_t str_data_len{MAX_STRING_LENGTH_DEFAULT};

        this->str_data = new uint8_t[str_data_len];
        string_helper::get_text(this->str_data, str_data_len);
    }

    std::ostream &operator<<(std::ostream &os, const string &obj) {
        os << obj.str_data;
        return os;
    }

//    std::istream &operator>>(std::istream &is, string &obj) {
//        uint8_t *buff{new uint8_t[MAX_STRING_LENGTH_DEFAULT]};
//        memset(&buff[0], 0, sizeof(buff));
//        is >> reinterpret_cast<short &>(buff);
//        obj = string{buff};
//        string_helper::strcpy(buff, obj.str_data);
//        delete[] buff;
//        return is;
//    }

    da_st::array_list<string> *string::split(const uint8_t split_char) {
        using namespace da_st;
        array_list<string> *list = new array_list<string>;

        while (*(this->str_data) != '\0') {

        }

        return list;
    }

    string string::clone() {

        return string();
    }
}