#pragma once

#ifndef GENETICALGORITHM_STRING_H
#define GENETICALGORITHM_STRING_H

#include <iostream>

namespace da_ty {
    class string {
    private:
        char *data;
    public:
        string();

        string(const char *data);

        string(const string &other);

        string(string &&other);

        ~string();

        int get_length();

        char *c_str();

        friend std::ostream &operator<<(std::ostream &os, const string &obj);

        friend std::istream &operator>>(std::istream &is, string &obj);

        string &operator=(const string &other);

        string &operator=(const char *text);

        friend string operator+(const string &left, const string &right);
    };
}

#endif
