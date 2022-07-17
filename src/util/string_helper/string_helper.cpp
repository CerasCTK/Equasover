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

    int32_t strcmp(const uint8_t *first, const uint8_t *sec) {
        if (first == nullptr || sec == nullptr)
            throw my_exception((uint8_t *) "Can't compare null value");

        int32_t min_len{strlen(first) > strlen(sec) ? strlen(sec) : strlen(first)};

        int32_t checker{0};
        for (int32_t i{0}; i < min_len; i++)
            if (*(first + i) < *(sec + i)) {
                checker = -1;
                break;
            } else if (*(first + i) > *(sec + i)) {
                checker = 1;
                break;
            }

        if (strlen(first) != strlen(sec) && checker == 0) {
            checker = min_len == strlen(first) ? -1 : 1;
        }

        return checker;
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