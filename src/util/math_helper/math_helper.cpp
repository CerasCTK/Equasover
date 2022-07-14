#include "math_helper.h"

#define SQRT_THRESHOLD 0.000000001

namespace math_helper {
    double abs(double n) {
        return ((n >= 0) ? n : -n);
    }

    double square(double n, double i, double j) {
        double mid{(i + j) / 2};
        double mul{mid * mid};

        if ((mul == n) || (abs(mul - n) < SQRT_THRESHOLD))
            return mid;
        else if (mul < n)
            return square(n, mid, j);
        else
            return square(n, i, mid);
    }

    double sqrt(double n) {
        double i{1};

        while (true) {
            if (i * i == n) {
                return i;
            } else if (i * i > n) {
                return square(n, i - 1, i);
            }
            i++;
        }
    }

    int32_t *decimal_to_fraction(double n, int32_t max_denominator) {
        // https://www.ics.uci.edu/~eppstein/numth/frap.c
        return new int32_t;
    }
}