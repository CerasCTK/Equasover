#pragma once

#ifndef GENETICALGORITHM_MATH_HELPER_H
#define GENETICALGORITHM_MATH_HELPER_H

#include <cstdint>

#define SQRT_THRESHOLD 0.000000001

namespace math_helper {
    double abs(double n);

    int32_t abs(int32_t n);

    double sqrt(double n);

    int32_t *decimal_to_fraction(double n, int32_t max_denominator);

    double text_to_num(uint8_t *s);

    int32_t char_to_int(uint8_t c);
}

#endif
