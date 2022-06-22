#include "string_helper.h"

#include <cstdio>

#include "../../core/exception/my_exception.h"

namespace util {
    char* string_helper::strcpy(char* destination, const char* source) {
        if (destination == nullptr)
            throw my_exception("Destination is null");

        char* p_string = destination;

        while (*source != '\0') {
            *(destination++) = *(source++);
        }

        *destination = '\0';

        destination = p_string;

        return destination;
    }

    int string_helper::strlen(const char* string) {
        int length {0};

        while (*string != '\0') {
            length++;
            string++;
        }

        return length;
    }

    void string_helper::get_text(char* container, const int number_of_chars, char stop_char) {
        if (container == nullptr) throw my_exception("Container is null");

        char c;
        int counter = 0;

        while (true) {
            c = getchar();

            if (c == stop_char || counter >= number_of_chars - 2) {
                *container = '\0';
                break;
            }

            *(container++) = c;
            counter++;
        }
    }
}