#pragma once

#ifndef GENETICALGORITHM_STRING_H
#define GENETICALGORITHM_STRING_H

#include <iostream>

#include <cstdint>

#include "../data_structure/array_list.h"

#include "config/cloneable.h"

#define MAX_STRING_LENGTH_DEFAULT 1000

#define MAX_STRING_LENGTH UINT32_MAX

#define END_STRING_CHAR '\0'
#define END_STRING_COUNT 1 // \0

#define NPOS -1

namespace da_ty {
    class string : public cloneable<string> {
    private:
        uint8_t *str_data;
    public:
        string();

        string(const string &str);

        string(const string &str, int32_t pos, int32_t len = NPOS);

        string(const uint8_t *s);

        string(const uint8_t *s, int32_t len);

        string(int32_t n, uint8_t c);

        string(string &&str) noexcept;

        ~string();

        string &operator=(const string &str);

        string &operator=(const uint8_t *s);

        string &operator=(uint8_t c);

        string &operator=(string &&str) noexcept;

        int32_t size() const noexcept;

        int32_t length() const noexcept;

        int32_t max_size() const noexcept;

        void resize(int32_t n);

        void resize(int32_t n, uint8_t c);

        void clear() noexcept;

        bool empty() const noexcept;

        uint8_t &operator[](int32_t pos);

        const uint8_t &operator[](int32_t pos) const;

        uint8_t &at(int32_t index);

        const uint8_t &at(int32_t index) const;

        uint8_t &back();

        const uint8_t &back() const;

        uint8_t &front();

        const uint8_t &front() const;

        string &operator+=(const string &str);

        string &operator+=(const uint8_t *s);

        string &operator+=(uint8_t c);

        string &append(const string &str);

        string &append(const string &str, int32_t sub_pos, int32_t sub_len);

        string &append(const uint8_t *s);

        string &append(const uint8_t *s, size_t n);

        string &append(int32_t n, uint8_t c);

        void push_back(uint8_t c);

        string &erase(int32_t pos = 0, int32_t len = NPOS);

        string &replace(int32_t pos, int32_t len, const string &str, int32_t sub_pos, int32_t sub_len);

        void swap(string &str);

        void pop_back();

        const uint8_t *c_str() const noexcept;

        const uint8_t *data() const noexcept;

        int32_t copy(uint8_t *s, int32_t len, int32_t pos = 0) const;

        int32_t find(const string &str, int32_t pos = 0) const;

        int32_t find(const uint8_t *s, int32_t pos = 0) const;

        int32_t find(const uint8_t *s, int32_t pos, int32_t n) const;

        int32_t find(uint8_t c, int32_t pos = 0) const;

        string substr(int32_t pos = 0, int32_t len = NPOS) const;

        friend string operator+(const string &lhs, const string &rhs);

        friend string operator+(const string &lhs, const uint8_t *rhs);

        friend string operator+(const uint8_t *lhs, const string &rhs);

        friend string operator+(const string &lhs, uint8_t rhs);

        friend string operator+(uint8_t lhs, const string &rhs);

        friend bool operator==(const string &lhs, const string &rhs) noexcept;

        friend bool operator==(const uint8_t *lhs, const string &rhs);

        friend bool operator==(const string &lhs, const uint8_t *rhs);

        friend bool operator!=(const string &lhs, const string &rhs) noexcept;

        friend bool operator!=(const uint8_t *lhs, const string &rhs);

        friend bool operator!=(const string &lhs, const uint8_t *rhs);

        friend bool operator<(const string &lhs, const string &rhs) noexcept;

        friend bool operator<(const uint8_t *lhs, const string &rhs);

        friend bool operator<(const string &lhs, const uint8_t *rhs);

        friend bool operator<=(const string &lhs, const string &rhs) noexcept;

        friend bool operator<=(const uint8_t *lhs, const string &rhs);

        friend bool operator<=(const string &lhs, const uint8_t *rhs);

        friend bool operator>(const string &lhs, const string &rhs) noexcept;

        friend bool operator>(const uint8_t *lhs, const string &rhs);

        friend bool operator>(const string &lhs, const uint8_t *rhs);

        friend bool operator>=(const string &lhs, const string &rhs) noexcept;

        friend bool operator>=(const uint8_t *lhs, const string &rhs);

        friend bool operator>=(const string &lhs, const uint8_t *rhs);


        void get_line();

        friend std::ostream &operator<<(std::ostream &os, const string &obj);

//        friend std::istream &operator>>(std::istream &is, string &obj);

        da_st::array_list<string> *split(const uint8_t split_char);

        string clone();
    };
}

#endif
