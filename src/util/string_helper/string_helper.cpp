#include "string_helper.h"

#include <cstdio>

#include "../../core/exception/my_exception.h"

namespace string_helper {
    char *strcpy(char *destination, const char *source) {
        if (destination == nullptr)
            throw my_exception("Destination is null");

        char *p_string = destination;

        while (*source != '\0')
            *(destination++) = *(source++);

        *destination = '\0';

        return p_string;
    }

    char *strcat(char *destination, const char *source) {
        if (destination == nullptr)
            throw my_exception("Destination is null");

        char *p_string = destination;

        int end_char_index = strlen(destination);

        destination += end_char_index;

        while (*source != '\0')
            *(destination++) = *(source++);

        *destination = '\0';

        return p_string;
    }

    bool strcmp(const char *first, const char *sec) {
        if (first == nullptr || sec == nullptr)
            return false;

        if (strlen(first) != strlen(sec))
            return false;

        for (int i = 0; i < strlen(first); i++)
            if (*(first + i) != *(sec + i))
                return false;

        return true;
    }

    int strlen(const char *text) {
        int length{0};

        while (*text != '\0') {
            length++;
            text++;
        }

        return length;
    }

    void get_text(char *container, const int number_of_chars, char stop_char) {
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

    int count_char(const char *text, char character) {
        int counter{0};
        while (*text != '\0') {
            if (*(text++) == character) counter++;
        }
        return counter;
    }

    int pos(const char *text, char character) {
        int counter{0};

        while (*(text++) != character) counter++;

        return counter;
    }
}