#ifndef GENETICALGORITHM_STRING_H
#define GENETICALGORITHM_STRING_H

#include <iostream>

namespace da_ty {
    class string {
    private:
        char* data;
        int string_length;
    public:
        string();

        string(const char* data);

        string(const string& other);

        string(string&& other);

        ~string();

        int get_length();

        char* c_str();

        friend std::ostream& operator<<(std::ostream& output, const string& string);

        friend std::istream& operator>>(std::istream& input, string& string);
    };
}


#endif //GENETICALGORITHM_STRING_H
