#include "string_helper.h"

namespace util {
    char* string_helper::strcpy(char* destination, const char* source) {
        if (destination == nullptr)
            return nullptr;

        char* p_string = destination;

        while (*source != '\0') {
            *(destination++) = *(source++);
        }

        *destination = '\0';

        return p_string;
    }

    int string_helper::strlen(const char* string) {
        int length {0};

        while (*string != '\0') {
            length++;
            string++;
        }

        return length;
    }
}