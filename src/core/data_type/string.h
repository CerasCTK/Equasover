#pragma once

#ifndef GENETICALGORITHM_STRING_H
#define GENETICALGORITHM_STRING_H

#include <iostream>

namespace da_ty {
    class string {
    private:
        uint8_t *data;
    public:
        string();

        string(const uint8_t *data);

        string(const string &other);

        string(string &&other);

        ~string();

        int32_t get_length();

        uint8_t *c_str();

        friend std::ostream &operator<<(std::ostream &os, const string &obj);

        friend std::istream &operator>>(std::istream &is, string &obj);

        string &operator=(const string &other);

        string &operator=(const uint8_t *text);

        friend string operator+(const string &left, const string &right);

        friend string operator+(const string &left, const uint8_t *text);

        bool operator==(string other);

        bool operator==(const uint8_t *text);
    };
}

#endif
