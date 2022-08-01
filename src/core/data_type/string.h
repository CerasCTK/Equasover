#pragma once

#ifndef GENETICALGORITHM_STRING_H
#define GENETICALGORITHM_STRING_H

#include <iostream>

#include <cstdint>

#include "../data_structure/array_list.h"

#include "../config/cloneable.h"

#define MAX_STRING_LENGTH_DEFAULT 1000

#define MAX_STRING_LENGTH UINT32_MAX

#define END_STRING_CHAR '\0'
#define END_STRING_COUNT 1 // \0

#define NPOS -1

namespace da_ty {
    class string : public cloneable<string> {
    private:
        /**
         *
         */
        uint8_t *str_data;

    public:
        /**
         * Constructor string object
         */
        string();

        /**
         * Constructor string object - Copy constructor
         * @param str - another string object, whose value is either copied or acquired
         */
        string(const string &str);

        /**
         * Constructor string object
         * @param str - another string object, whose value is either copied or acquired
         * @param pos - position of the first character in str that is copied to the object as a substring
         * @param len - length of the substring to be copied (if the string is shorter, as many characters as possible are copied)
         */
        string(const string &str, int32_t pos, int32_t len = NPOS);

        /**
         * Constructor string object
         * @param s - pointer to an array of characters (such as a c-string)
         */
        string(const uint8_t *s);

        /**
         * Constructor string object
         * @param s - pointer to an array of characters (such as a c-string)
         * @param len - number of characters to copy
         */
        string(const uint8_t *s, int32_t len);

        /**
         * Constructor string object
         * @param n - number of characters
         * @param c - character to fill the string with. Each of the n characters in the string will be initialized to a copy of this value
         */
        string(int32_t n, uint8_t c);

        /**
         * Constructor string object
         * @param il - an initializer_list object. These objects are automatically constructed from initializer list declarators
         */
        string(std::initializer_list<uint8_t> il);

        /**
         * Constructor string object - Move constructor
         * @param str
         */
        string(string &&str) noexcept;

        /**
         * String destructor
         */
        ~string();

        /**
         * Assigns a new value to the string, replacing its current contents
         * @param str - a string object
         * @return *this
         */
        string &operator=(const string &str);

        /**
         * Assigns a new value to the string, replacing its current contents
         * @param s - pointer to a null-terminated sequence of characters. The sequence is copied as the new value for the string
         * @return *this
         */
        string &operator=(const uint8_t *s);

        /**
         * Assigns a new value to the string, replacing its current contents
         * @param c - a character. The string value is set to a single copy of this character (the string length becomes 1)
         * @return *this
         */
        string &operator=(uint8_t c);

        /**
         * Assigns a new value to the string, replacing its current contents - Move
         * @param str - a string object
         * @return *this
         */
        string &operator=(string &&str) noexcept;

        /**
         *
         * @return length of string
         */
        int32_t size() const noexcept;

        /**
         *
         * @return length of string
         */
        int32_t length() const noexcept;

        /**
         *
         * @return maximum size of string
         */
        int32_t max_size() const noexcept;

        /**
         *
         * @param n
         */
        void resize(int32_t n);

        /**
         *
         * @param n
         * @param c
         */
        void resize(int32_t n, uint8_t c);

        /**
         * Erases the contents of the string, which becomes an empty string (with a length of 0 characters)
         */
        void clear() noexcept;

        /**
         * Test if string is empty
         * @return true - if the string length is 0
         */
        bool empty() const noexcept;

        /**
         * Get character of string
         * @param pos - value with the position of a character within the string
         * @return the character at the specified position in the string.
         */
        uint8_t &operator[](int32_t pos);

        /**
         * Get character of string
         * @param pos - value with the position of a character within the string
         * @return the character at the specified position in the string.
         */
        const uint8_t &operator[](int32_t pos) const;

        /**
         * Get character in string
         * @param index - value with the position of a character within the string
         * @return a reference to the character at position pos in the string
         */
        uint8_t &at(int32_t index);

        /**
         * Get character in string
         * @param index - value with the position of a character within the string
         * @return a reference to the character at position pos in the string
         */
        const uint8_t &at(int32_t index) const;

        /**
         * Access last character
         * @return a reference to the last character of the string
         */
        uint8_t &back();

        /**
         * Access last character
         * @return a reference to the last character of the string
         */
        const uint8_t &back() const;

        /**
         * Access first character
         * @return a reference to the first character of the string
         */
        uint8_t &front();

        /**
         * Access first character
         * @return a reference to the first character of the string
         */
        const uint8_t &front() const;

        /**
         * Append to string
         * @param str - a string object, whose value is copied at the end
         * @return *this
         */
        string &operator+=(const string &str);

        /**
         * Append to string
         * @param s - pointer to a null-terminated sequence of characters. The sequence is copied at the end of the string
         * @return *this
         */
        string &operator+=(const uint8_t *s);

        /**
         * Append to string
         * @param c - a character, which is appended to the current value of the string
         * @return *this
         */
        string &operator+=(uint8_t c);

        /**
         *
         * @param str
         * @return
         */
        string &append(const string &str);

        /**
         *
         * @param str
         * @param sub_pos
         * @param sub_len
         * @return
         */
        string &append(const string &str, int32_t sub_pos, int32_t sub_len);

        /**
         *
         * @param s
         * @return
         */
        string &append(const uint8_t *s);

        /**
         *
         * @param s
         * @param n
         * @return
         */
        string &append(const uint8_t *s, int32_t n);

        /**
         *
         * @param n
         * @param c
         * @return
         */
        string &append(int32_t n, uint8_t c);

        /**
         *
         * @param c
         */
        void push_back(uint8_t c);

        /**
         *
         * @param pos
         * @param len
         * @return
         */
        string &erase(int32_t pos = 0, int32_t len = NPOS);

        /**
         *
         * @param pos
         * @param len
         * @param str
         * @param sub_pos
         * @param sub_len
         * @return
         */
        string &replace(int32_t pos, int32_t len, const string &str, int32_t sub_pos, int32_t sub_len);

        /**
         *
         * @param str
         */
        void swap(string &str);

        /**
         *
         */
        void pop_back();

        /**
         *
         * @return
         */
        const uint8_t *c_str() const noexcept;

        /**
         *
         * @return
         */
        const uint8_t *data() const noexcept;

        /**
         *
         * @param s
         * @param len
         * @param pos
         * @return
         */
        int32_t copy(uint8_t *s, int32_t len, int32_t pos = 0) const;

        /**
         *
         * @param str
         * @param pos
         * @return
         */
        int32_t find(const string &str, int32_t pos = 0) const;

        /**
         *
         * @param s
         * @param pos
         * @return
         */
        int32_t find(const uint8_t *s, int32_t pos = 0) const;

        /**
         *
         * @param s
         * @param pos
         * @param n
         * @return
         */
        int32_t find(const uint8_t *s, int32_t pos, int32_t n) const;

        /**
         *
         * @param c
         * @param pos
         * @return
         */
        int32_t find(uint8_t c, int32_t pos = 0) const;

        /**
         *
         * @param pos
         * @param len
         * @return
         */
        string substr(int32_t pos = 0, int32_t len = NPOS) const;

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend string operator+(const string &lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend string operator+(const string &lhs, const uint8_t *rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend string operator+(const uint8_t *lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend string operator+(const string &lhs, uint8_t rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend string operator+(uint8_t lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator==(const string &lhs, const string &rhs) noexcept;

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator==(const uint8_t *lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator==(const string &lhs, const uint8_t *rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator!=(const string &lhs, const string &rhs) noexcept;

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator!=(const uint8_t *lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator!=(const string &lhs, const uint8_t *rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator<(const string &lhs, const string &rhs) noexcept;

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator<(const uint8_t *lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator<(const string &lhs, const uint8_t *rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator<=(const string &lhs, const string &rhs) noexcept;

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator<=(const uint8_t *lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator<=(const string &lhs, const uint8_t *rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator>(const string &lhs, const string &rhs) noexcept;

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator>(const uint8_t *lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator>(const string &lhs, const uint8_t *rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator>=(const string &lhs, const string &rhs) noexcept;

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator>=(const uint8_t *lhs, const string &rhs);

        /**
         *
         * @param lhs
         * @param rhs
         * @return
         */
        friend bool operator>=(const string &lhs, const uint8_t *rhs);

        /**
         *
         */
        void get_line();

        /**
         *
         * @param os
         * @param obj
         * @return
         */
        friend std::ostream &operator<<(std::ostream &os, const string &obj);

//        friend std::istream &operator>>(std::istream &is, string &obj);

        /**
         *
         * @param split_char
         * @return
         */
        da_st::array_list<string> *split(const uint8_t split_char);

        string clone();
    };
}

#endif
