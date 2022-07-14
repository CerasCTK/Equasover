#include <cstdint>

#ifndef GENETICALGORITHM_MATH_HELPER_H
#define GENETICALGORITHM_MATH_HELPER_H

namespace math_helper {
    double abs(double n);

    double sqrt(double n);

    int32_t *decimal_to_fraction(double n, int32_t max_denominator);
}

#endif
