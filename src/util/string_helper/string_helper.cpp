#include "string_helper.h"

#include <cstdio>

#include "../../core/exception/my_exception.h"

namespace string_helper {
    char* strcpy(char* destination, const char* source) {
        if (destination == nullptr)
            throw my_exception("Destination is null");

        // TODO: destination not enough memory

        char* p_string = destination;

        while (*source != '\0') {
            *(destination++) = *(source++);
        }

        *destination = '\0';

        return p_string;
    }

    int strlen(const char* text) {
        int length {0};

        while (*text != '\0') {
            length++;
            text++;
        }

        return length;
    }

    void get_text(char* container, const int number_of_chars, char stop_char) {
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

    char** split(const char* text, char split_char) {
        int container_size = count_char(text, split_char);

        char** container = new char*[container_size + 1];

        while (*text != '\0') {


        }

        return container;
    }

    int count_char(const char* text, char character) {
        int counter {0};
        while (*text != '\0') {
            if (*(text++) == character) counter++;
        }
        return counter;
    }

    int pos(const char* text, char character) {
        int counter {0};

        while (*(text++) != character) counter++;

        return counter;
    }
}