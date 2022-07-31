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

    /**
     *
     * @param lower_threshold
     * @param upper_threshold
     * @return
     */
    double random_number(double lower_threshold, double upper_threshold);

    /**
     *
     * @param lower_threshold
     * @param upper_threshold
     * @return
     */
    int32_t random_int_number(int32_t lower_threshold, int32_t upper_threshold);
}

#endif
