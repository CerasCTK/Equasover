#include "string_helper.h"

#include <cstdio>

#include <cmath>

#include "../../core/exception/my_exception.h"

#include "../../core/data_structure/stack.h"

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

    double text_to_num(uint8_t *s) {
        int32_t num_len{string_helper::strlen(s)};

        int32_t point_index{0};

        double output{0};

        bool negative_num = (*(s + 0) == 45);

        int32_t counter{negative_num ? 1 : 0};

        for (; counter < num_len; counter++) {
            if (*(s + counter) == 46) {
                point_index = counter;
                continue;
            }
            output *= 10;
            output += char_to_int(*(s + counter));
        }

        int32_t power_of{point_index != 0 ? num_len - point_index - 1 : 0};
        for (int32_t i{0}; i < power_of; i++)
            output /= 10;

        if (negative_num)
            output *= -1;

        return output;
    }

    int32_t char_to_int(uint8_t c) {
        if (c < 48 || c > 57)
            throw my_exception((uint8_t *) ("This character is not a number"));

        return c - 48;
    }

    int32_t int_to_char(int32_t i) {
        if (i < 0 || i > 9)
            throw my_exception((uint8_t *) ("Can't not convert int to char"));

        return i + 48;
    }

    da_ty::string num_to_string(double num) {
        int32_t rounder{1};
        for (int32_t i{0}; i < NUMBER_OF_DECIMAL_PLACES; i++)
            rounder *= 10;

        num = round(num * rounder) / rounder;
        int32_t dot_index_from_tail{0};

        while (num - round(num) > ROUND_NUMBER_THRESHOLD || num - round(num) < -ROUND_NUMBER_THRESHOLD) {
            dot_index_from_tail++;
            num *= 10;
        }

        int32_t int_num{(int) num};
        da_st::stack<int32_t> num_stack(100);

        bool is_negative{false};

        if (int_num < 0) {
            is_negative = true;
            int_num = -int_num;
        }

        while (int_num) {
            num_stack.push(int_num % 10);
            int_num /= 10;
        }

        int32_t num_length{num_stack.size()};
        int32_t dot_index{num_length - dot_index_from_tail};
        bool less_than_one{false};
        if (dot_index == 0) {
            num_length++;
            dot_index++;
            less_than_one = true;
        }

        if (is_negative) {
            num_length++;
            dot_index++;
        }

        int32_t output_length{dot_index < num_length ? num_length + 1 + 1 : num_length + 1};

        da_ty::string output(output_length, '0');

        int32_t i{less_than_one
                  ? is_negative ? 2 : 1
                  : is_negative ? 1 : 0};

        for (; !num_stack.empty(); i++) {
            if (i == dot_index) {
                output.at(i) = '.';
                continue;
            }
            output.at(i) = int_to_char(num_stack.top());
            num_stack.pop();
        }

        if (is_negative) output.at(0) = '-';

        output.at(output_length - 1) = '\0';

        return output;
    }
}