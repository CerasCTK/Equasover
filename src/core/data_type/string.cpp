#include "string.h"

#include <iostream>

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

    string::string(int32_t n, uint8_t c) {
        int32_t str_data_len{n + END_STRING_COUNT};

        this->str_data = new uint8_t[str_data_len];

        for (int32_t i{0}; i < n; i++)
            *(this->str_data + i) = c;

        *(this->str_data + str_data_len - 1) = END_STRING_CHAR;
    }

    string::string (std::initializer_list<uint8_t> il) {
        std::initializer_list<uint8_t>::iterator it;

        int32_t str_data_len = il.size() + END_STRING_COUNT;

        this->str_data = new uint8_t[str_data_len];

        int32_t index{0};
        for (it = il.begin(); it != il.end(); it++, index++)
            *(this->str_data + index) = *it;

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

        int32_t new_len{str.length() + END_STRING_COUNT};
        this->str_data = new uint8_t[new_len];
        string_helper::strcpy(this->str_data, str.str_data);

        *(this->str_data + new_len - 1) = END_STRING_CHAR;

        return *this;
    }

    string &string::operator=(const uint8_t *s) {
        if (string_helper::strcmp(this->str_data, s) == 0)
            return *this;

        int32_t new_len{string_helper::strlen(s) + END_STRING_COUNT};
        this->str_data = new uint8_t[new_len];
        string_helper::strcpy(this->str_data, s);

        *(this->str_data + new_len - 1) = END_STRING_CHAR;

        return *this;
    }

    string &string::operator=(uint8_t c) {
        int32_t new_len{1 + END_STRING_COUNT};

        this->str_data = new uint8_t[new_len];
        *this->str_data = c;
        *(this->str_data + new_len - 1) = END_STRING_CHAR;

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
        this->str_data = new uint8_t;
        *this->str_data = END_STRING_CHAR;
    }

    bool string::empty() const noexcept {
        if (this->str_data == nullptr || this->length() == 0)
            return true;

        return false;
    }

    uint8_t &string::operator[](int32_t pos) {
        if (pos >= this->length())
            throw my_exception((uint8_t *) ("Index out of bound"));
        return *(this->str_data + pos);
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
        return *(this->str_data + this->length() - 1);
    }

    const uint8_t &string::back() const {
        return *(this->str_data + this->length() - 1);
    }

    uint8_t &string::front() {
        return *(this->str_data);
    }

    const uint8_t &string::front() const {
        return *(this->str_data);
    }

    string &string::operator+=(const string &str) {
        int32_t new_len{this->length() + str.length() + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        string_helper::strcpy(buff, this->str_data);
        string_helper::strcat(buff, str.str_data);

        buff[new_len - 1] = END_STRING_CHAR;

        this->str_data = buff;

        return *this;
    }

    string &string::operator+=(const uint8_t *s) {
        int32_t new_len{this->length() + string_helper::strlen(s) + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        string_helper::strcpy(buff, this->str_data);
        string_helper::strcat(buff, s);

        buff[new_len - 1] = END_STRING_CHAR;

        this->str_data = buff;

        return *this;
    }

    string &string::operator+=(uint8_t c) {
        int32_t new_len{this->length() + 1 + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        string_helper::strcpy(buff, this->str_data);
        buff[new_len - 2] = c;
        buff[new_len - 1] = END_STRING_CHAR;

        this->str_data = buff;

        return *this;
    }

    string &string::append(const string &str) {
        int32_t new_len{this->length() + str.length() + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        string_helper::strcpy(buff, this->str_data);
        string_helper::strcat(buff, str.str_data);

        buff[new_len - 1] = END_STRING_CHAR;

        this->str_data = buff;

        return *this;
    }

    string &string::append(const string &str, int32_t sub_pos, int32_t sub_len) {
        return *this;
        // TODO
    }

    string &string::append(const uint8_t *s) {
        int32_t new_len{this->length() + string_helper::strlen(s) + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        string_helper::strcpy(buff, this->str_data);
        string_helper::strcat(buff, s);

        buff[new_len - 1] = END_STRING_CHAR;

        this->str_data = buff;

        return *this;
    }

    string &string::append(const uint8_t *s, int32_t n) {
        return *this;
        // TODO
    }

    string &string::append(int32_t n, uint8_t c) {
        return *this;
        // TODO
    }

    void string::push_back(uint8_t c) {
        int32_t new_length{this->length() + 1 + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};
        string_helper::strcpy(buff, this->str_data);
        buff[new_length - 2] = c;
        buff[new_length - 1] = END_STRING_CHAR;

        this->str_data = buff;
    }

    string &string::erase(int32_t pos, int32_t len) {
        int32_t str_data_len{this->length()};
        int32_t nocfp{str_data_len - pos}; // number of chars from pos

        len = ((len > nocfp) || len == NPOS) ? nocfp : len;

        int32_t new_len{str_data_len - len + END_STRING_COUNT};
        uint8_t *buff{new uint8_t[new_len]};

        for (int32_t i{0}; i < pos; i++)
            *(buff + i) = *(this->str_data + i);

        if (len != nocfp) {
            int32_t new_pos_aft_del{pos + len};
            int32_t chars_remaining{new_len - pos};

            for (int32_t i{0}; i < chars_remaining; i++)
                *(buff + i) = *(this->str_data + new_pos_aft_del + i);
        }

        *(buff + new_len - 1) = END_STRING_CHAR;

        this->str_data = buff;

        return *this;
    }

    string &string::replace(int32_t pos, int32_t len, const string &str, int32_t sub_pos, int32_t sub_len) {

        return *this;
        // TODO
    }

    void string::swap(string &str) {
        uint8_t *temp{this->str_data};

        this->str_data = str.str_data;
        str.str_data = temp;
    }

    void string::pop_back() {
        int32_t new_len{this->length() - 1 + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        for (int32_t i{0}; i < new_len; i++)
            *(buff + i) = *(this->str_data + i);

        *(buff + new_len - 1) = END_STRING_CHAR;

        this->str_data = buff;
    }

    const uint8_t *string::c_str() const noexcept {
        return this->str_data;
    }

    const uint8_t *string::data() const noexcept {
        return this->str_data;
    }

    int32_t string::copy(uint8_t *s, int32_t len, int32_t pos) const {
        return 0;
        // TODO
    }

    int32_t string::find(const string &str, int32_t pos) const {
        return 0;
        // TODO
    }

    int32_t string::find(const uint8_t *s, int32_t pos) const {
        return 0;
        // TODO
    }

    int32_t string::find(const uint8_t *s, int32_t pos, int32_t n) const {
        return 0;
        // TODO
    }

    int32_t string::find(uint8_t c, int32_t pos) const {
        return 0;
        // TODO
    }

    string string::substr(int32_t pos, int32_t len) const {
        int32_t str_data_len{this->length()};
        int32_t nocfp{str_data_len - pos}; // number of chars from pos

        len = ((len > nocfp) || len == NPOS) ? nocfp : len;

        int32_t new_len{str_data_len - len + END_STRING_COUNT};
        uint8_t *buff{new uint8_t[new_len]};

        for (int32_t i{0}; i < pos; i++)
            *(buff + i) = *(this->str_data + i);

        if (len != nocfp) {
            int32_t new_pos_aft_del{pos + len};
            int32_t chars_remaining{new_len - pos};

            for (int32_t i{0}; i < chars_remaining; i++)
                *(buff + i) = *(this->str_data + new_pos_aft_del + i);
        }

        *(buff + new_len - 1) = END_STRING_CHAR;

        string temp(buff);

        delete[] buff;

        return temp;
    }

    string operator+(const string &left, const string &right) {
        int32_t new_length{left.length() + right.length() + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};

        string_helper::strcpy(buff, left.str_data);
        string_helper::strcat(buff, right.str_data);

        buff[new_length - 1] = END_STRING_CHAR;

        string temp(buff);

        delete[] buff;

        return temp;
    }

    string operator+(const string &left, const uint8_t *text) {
        int32_t new_length{string_helper::strlen(left.str_data) + string_helper::strlen(text) + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_length]};

        string_helper::strcpy(buff, left.str_data);
        string_helper::strcat(buff, text);

        buff[new_length - 1] = END_STRING_CHAR;

        string temp(buff);

        delete[] buff;

        return temp;
    }

    string operator+(const uint8_t *lhs, const string &rhs) {
        int32_t new_len{string_helper::strlen(lhs) + rhs.length() + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        string_helper::strcpy(buff, lhs);
        string_helper::strcat(buff, rhs.str_data);

        buff[new_len - 1] = END_STRING_CHAR;

        string temp(buff);

        delete[] buff;

        return temp;
    }

    string operator+(const string &lhs, uint8_t rhs) {
        int32_t new_len{lhs.length() + 1 + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        string_helper::strcpy(buff, lhs.str_data);
        buff[new_len - 2] = rhs;
        buff[new_len - 1] = END_STRING_CHAR;

        string temp(buff);

        delete[] buff;

        return temp;
    }

    string operator+(uint8_t lhs, const string &rhs) {
        int32_t new_len{1 + rhs.length() + END_STRING_COUNT};

        uint8_t *buff{new uint8_t[new_len]};

        buff[0] = lhs;
        string_helper::strcat(buff, rhs.str_data);
        buff[new_len - 1] = END_STRING_CHAR;

        string temp(buff);

        delete[] buff;

        return temp;
    }

    bool operator==(const string &lhs, const string &rhs) noexcept {
        return string_helper::strcmp(lhs.str_data, rhs.str_data) == 0;
    }

    bool operator==(const uint8_t *lhs, const string &rhs) {
        return string_helper::strcmp(lhs, rhs.str_data) == 0;
    }

    bool operator==(const string &lhs, const uint8_t *rhs) {
        return string_helper::strcmp(lhs.str_data, rhs) == 0;
    }

    bool operator!=(const string &lhs, const string &rhs) noexcept {
        return string_helper::strcmp(lhs.str_data, rhs.str_data) != 0;
    }

    bool operator!=(const uint8_t *lhs, const string &rhs) {
        return string_helper::strcmp(lhs, rhs.str_data) != 0;
    }

    bool operator!=(const string &lhs, const uint8_t *rhs) {
        return string_helper::strcmp(lhs.str_data, rhs) != 0;
    }

    bool operator<(const string &lhs, const string &rhs) noexcept {
        return string_helper::strcmp(lhs.str_data, rhs.str_data) == -1;
    }

    bool operator<(const uint8_t *lhs, const string &rhs) {
        return string_helper::strcmp(lhs, rhs.str_data) == -1;
    }

    bool operator<(const string &lhs, const uint8_t *rhs) {
        return string_helper::strcmp(lhs.str_data, rhs) == -1;
    }

    bool operator<=(const string &lhs, const string &rhs) noexcept {
        return string_helper::strcmp(lhs.str_data, rhs.str_data) <= 0;
    }

    bool operator<=(const uint8_t *lhs, const string &rhs) {
        return string_helper::strcmp(lhs, rhs.str_data) <= 0;
    }

    bool operator<=(const string &lhs, const uint8_t *rhs) {
        return string_helper::strcmp(lhs.str_data, rhs) <= 0;
    }

    bool operator>(const string &lhs, const string &rhs) noexcept {
        return string_helper::strcmp(lhs.str_data, rhs.str_data) == 1;
    }

    bool operator>(const uint8_t *lhs, const string &rhs) {
        return string_helper::strcmp(lhs, rhs.str_data) == 1;
    }

    bool operator>(const string &lhs, const uint8_t *rhs) {
        return string_helper::strcmp(lhs.str_data, rhs) == 1;
    }

    bool operator>=(const string &lhs, const string &rhs) noexcept {
        return string_helper::strcmp(lhs.str_data, rhs.str_data) >= 0;
    }

    bool operator>=(const uint8_t *lhs, const string &rhs) {
        return string_helper::strcmp(lhs, rhs.str_data) >= 0;
    }

    bool operator>=(const string &lhs, const uint8_t *rhs) {
        return string_helper::strcmp(lhs.str_data, rhs) >= 0;
    }


    void string::get_line() {
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

        string temp;

        if (split_char == 0) {
            for (int32_t i{0}; i < this->length(); i++) {
                temp += *(this->str_data + i);
                std::cout << temp << std::endl;
                list->add(temp);
                temp.clear();
            }
            return list;
        }


        for (int32_t i{0}; i < this->length(); i++) {
            if (*(this->str_data + i) == split_char) {
                if (!temp.empty())
                    list->add(temp);
                temp.clear();
                continue;
            }

            temp += *(this->str_data + i);

            if (i == this->length() - 1)
                if (!temp.empty())
                    list->add(temp);
        }

        return list;
    }

    string string::clone() {
        // TODO
        return string();
    }
}