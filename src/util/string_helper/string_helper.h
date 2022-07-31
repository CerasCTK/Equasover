#pragma once

#ifndef GENETICALGORITHM_STRING_HELPER_H
#define GENETICALGORITHM_STRING_HELPER_H

#include <cstdint>

#include "../../core/data_type/string.h"

#define ROUND_NUMBER_THRESHOLD 0.00001
#define NUMBER_OF_DECIMAL_PLACES 2

namespace string_helper {
    /**
     *
     * @param destination
     * @param source
     * @return
     */
    uint8_t *strcpy(uint8_t *destination, const uint8_t *source);

    /**
     *
     * @param destination
     * @param source
     * @return
     */
    uint8_t *strcat(uint8_t *destination, const uint8_t *source);

    /**
     *
     * @param first
     * @param sec
     * @return
     */
    int32_t strcmp(const uint8_t *first, const uint8_t *sec);

    /**
     *
     * @param text
     * @return
     */
    int32_t strlen(const uint8_t *text);

    /**
     *
     * @param container
     * @param number_of_chars
     * @param stop_char
     */
    void get_text(uint8_t *container, const int32_t number_of_chars, uint8_t stop_char = '\n');

    /**
     *
     * @param text
     * @param character
     * @return
     */
    int32_t count_char(const uint8_t *text, uint8_t character);

    /**
     *
     * @param text
     * @param character
     * @return
     */
    int32_t pos(const uint8_t *text, uint8_t character);

    /**
     *
     * @param s
     * @return
     */
    double text_to_num(uint8_t *s);

    /**
     *
     * @param c
     * @return
     */
    int32_t char_to_int(uint8_t c);

    /**
     *
     * @param i
     * @return
     */
    int32_t int_to_char(int32_t i);

    /**
     *
     * @param num
     * @return
     */
    da_ty::string num_to_string(double num);
}

#endif
