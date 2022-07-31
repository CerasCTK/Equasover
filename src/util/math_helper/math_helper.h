#pragma once

#ifndef GENETICALGORITHM_MATH_HELPER_H
#define GENETICALGORITHM_MATH_HELPER_H

#include <cstdint>

#define SQRT_THRESHOLD 0.000000001

namespace math_helper {
    /***
     *
     * @param n
     * @return
     */
    double abs(double n);

    /***
     *
     * @param n
     * @return
     */
    int32_t abs(int32_t n);

    /***
     *
     * @param n
     * @return
     */
    double sqrt(double n);

    /***
     *
     * @param n
     * @param max_denominator
     * @return
     */
    int32_t *decimal_to_fraction(double n, int32_t max_denominator);


}

#endif
