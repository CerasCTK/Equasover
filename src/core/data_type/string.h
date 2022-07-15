#pragma once

#ifndef GENETICALGORITHM_STRING_H
#define GENETICALGORITHM_STRING_H

#include <iostream>

#include <cstdint>

#include "../data_structure/array_list.h"

#include "config/cloneable.h"

#define MAX_STRING_LENGTH_DEFAULT 1000

#define END_STRING_COUNT 1 // \0
#define END_STRING_CHAR '\0'

namespace da_ty {
class string : public cloneable<string> {
    private:
        uint8_t *data;
    public:
        string();

        string(const uint8_t *data);

        string(const string &other);

        string(string &&other);

        ~string();

        int32_t length();

        uint8_t *c_str();

        uint8_t &at(int32_t index);

        void push_back(uint8_t c);

        da_st::array_list<string> *split(const uint8_t split_char);

        friend std::ostream &operator<<(std::ostream &os, const string &obj);

        friend std::istream &operator>>(std::istream &is, string &obj);

        string &operator=(const string &other);

        string &operator=(const uint8_t *text);

        friend string operator+(const string &left, const string &right);

        friend string operator+(const string &left, const uint8_t *text);

        bool operator==(string other);

        bool operator==(const uint8_t *text);

        string clone();
    };
}

#endif
