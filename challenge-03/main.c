#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long double gauss_legendre(long double eps)
{
        long double prev_a = 1.0;
        long double prev_b = sqrt(2) / 2;
        long double prev_p = 1.0;
        long double prev_t = 0.25;
        long double prev_pi = 3;

        for (;;) {
                long double a = (prev_a + prev_b) / 2;
                long double b = sqrt(prev_a * prev_b);
                long double p = 2 * prev_p;
                long double t = prev_t - prev_p * pow(a - prev_a, 2);
                long double pi = powl(a + b, 2) / (4 * t);

                if (fabsl(pi - prev_pi) < eps) {
                        return pi;
                }

                prev_a = a;
                prev_b = b;
                prev_p = p;
                prev_t = t;
                prev_pi = pi;
        }
}

int main(int argc, char *argv[argc + 1])
{
        int precision = 6;
        long double eps = 1E-06;
        if (argc == 1) {
                puts("Number of decimal digits not provided. Will use 6");
        }
        if (argc >= 3) {
                puts("Error. Expecting 1 argument - number of decimal digits");
                return EXIT_FAILURE;
        }
        if (argc == 2) {
                precision = strtol(argv[1], NULL, 10);
                eps = powl(1E-01, precision + 1);
        }

        long double pi = gauss_legendre(eps);

        printf("%.*Lf\n", precision, pi);
        return EXIT_SUCCESS;
}
