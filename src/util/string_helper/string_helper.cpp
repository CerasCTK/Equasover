#include "string_helper.h"

#include <cstdio>

#include "../../core/exception/my_exception.h"

namespace string_helper {
    uint8_t *strcpy(uint8_t *destination, const uint8_t *source) {
        if (destination == nullptr)
            throw my_exception((uint8_t *) ("Destination is null"));

        uint8_t *p_string{destination};

        while (*source != '\0')
            *(destination++) = *(source++);

        *destination = '\0';

        return p_string;
    }

    uint8_t *strcat(uint8_t *destination, const uint8_t *source) {
        if (destination == nullptr)
            throw my_exception((uint8_t *) ("Destination is null"));

        uint8_t *p_string{destination};

        int32_t end_char_index{strlen(destination)};

        destination += end_char_index;

        while (*source != '\0')
            *(destination++) = *(source++);

        *destination = '\0';

        return p_string;
    }

    bool strcmp(const uint8_t *first, const uint8_t *sec) {
        if (first == nullptr || sec == nullptr)
            return false;

        if (strlen(first) != strlen(sec))
            return false;

        for (int32_t i = 0; i < strlen(first); i++)
            if (*(first + i) != *(sec + i))
                return false;

        return true;
    }

    int32_t strlen(const uint8_t *text) {
        int32_t length{0};

        while (*text != '\0') {
            length++;
            text++;
        }

        return length;
    }

    void get_text(uint8_t *container, const int32_t number_of_chars, uint8_t stop_char) {
        if (container == nullptr) throw my_exception((uint8_t *) ("Container is null"));

        uint8_t c;
        int32_t counter{0};

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

    int32_t count_char(const uint8_t *text, uint8_t character) {
        int32_t counter{0};
        while (*text != '\0') {
            if (*(text++) == character) counter++;
        }
        return counter;
    }

    int32_t pos(const uint8_t *text, uint8_t character) {
        int32_t counter{0};

        while (*(text++) != character) counter++;

        return counter;
    }
}