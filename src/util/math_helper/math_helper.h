#pragma once

#ifndef GENETICALGORITHM_MATH_HELPER_H
#define GENETICALGORITHM_MATH_HELPER_H

#include <cstdint>
#include <random>

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
     * @tparam Numeric
     * @tparam Generator
     * @param from
     * @param to
     * @return
     */
    template<typename Numeric, typename Generator = std::mt19937>
    Numeric random(Numeric from, Numeric to);
}

#endif
