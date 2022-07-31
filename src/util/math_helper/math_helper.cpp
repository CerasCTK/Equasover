#include "math_helper.h"

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

    int32_t *decimal_to_fraction(double n, int32_t max_denominator) {
        // https://www.ics.uci.edu/~eppstein/numth/frap.c
//        long m[2][2];
//        double x, startx;
//        long maxden;
//        long ai;
//
//        /* read command line arguments */
//        startx = x = 0.125;
//        maxden = 100;
//
//        /* initialize matrix */
//        m[0][0] = m[1][1] = 1;
//        m[0][1] = m[1][0] = 0;
//
//        /* loop finding terms until denom gets too big */
//        while (m[1][0] *  ( ai = (long)x ) + m[1][1] <= maxden) {
//            long t;
//            t = m[0][0] * ai + m[0][1];
//            m[0][1] = m[0][0];
//            m[0][0] = t;
//            t = m[1][0] * ai + m[1][1];
//            m[1][1] = m[1][0];
//            m[1][0] = t;
//            if(x==(double)ai) break;     // AF: division by zero
//            x = 1/(x - (double) ai);
//            if(x>(double)0x7FFFFFFF) break;  // AF: representation failure
//        }
//
//        /* now remaining x is between 0 and 1/ai */
//        /* approx as either 0 or 1/m where m is max that will fit in maxden */
//        /* first try zero */
//        printf("%ld/%ld, error = %e\n", m[0][0], m[1][0],
//               startx - ((double) m[0][0] / (double) m[1][0]));
//
//        /* now try other possibility */
//        ai = (maxden - m[1][1]) / m[1][0];
//        m[0][0] = m[0][0] * ai + m[0][1];
//        m[1][0] = m[1][0] * ai + m[1][1];
//        printf("%ld/%ld, error = %e\n", m[0][0], m[1][0],
//               startx - ((double) m[0][0] / (double) m[1][0]));

        return new int32_t;
    }
}