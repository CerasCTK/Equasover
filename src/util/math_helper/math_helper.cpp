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

    template<typename Numeric, typename Generator>
    Numeric random(Numeric from, Numeric to) {
        thread_local static Generator gen(std::random_device{}());

        using dist_type = typename std::conditional<std::is_integral<Numeric>::value, std::uniform_int_distribution<Numeric>, std::uniform_real_distribution<Numeric>>::type;

        thread_local static dist_type dist;

        return dist(gen, typename dist_type::param_type{from, to});
    }

    template
    int32_t random<int32_t, std::mt19937>(int32_t, int32_t);

    template
    double random<double, std::mt19937>(double, double);
}