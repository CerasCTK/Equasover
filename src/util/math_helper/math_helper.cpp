#include "math_helper.h"

#include <cstdlib>
#include <ctime>

#include "../../core/exception/my_exception.h"

namespace math_helper {
    double abs(double n) {
        return ((n >= 0) ? n : -n);
    }

    int32_t abs(int32_t n) {
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

    double random_number(double lower_threshold, double upper_threshold) {
        srand(time(0));

        double scale = rand() / (double) RAND_MAX;

        return lower_threshold + scale * (upper_threshold - lower_threshold);
    }

    int32_t random_int_number(int32_t lower_threshold, int32_t upper_threshold) {
        srand(time(0));

        int32_t scale{rand() % (upper_threshold - lower_threshold)};

        return lower_threshold + scale;
    }
}