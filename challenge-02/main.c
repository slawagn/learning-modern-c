#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EPS 1E-09
#define DX0 1E-03

double F(double x) { return sin(x); }

double f(double x)
{
        double dx = DX0;
        double F0 = F(x);
        double prev_derivative = ((F(x) - F(x + dx)) / dx);

        while (true) {
                double F1 = F(x + dx);
                double df = F1 - F0;
                double derivative = df / dx;

                if (fabs(derivative - prev_derivative) <= EPS) {
                        return derivative;
                }

                prev_derivative = derivative;
                dx /= 2;
        }
}

int main()
{
        for (int i = 0; i < 8; ++i) {
                double x = M_PI * i / 4;
                double derivative = f(x);

                printf("derivative of F(x) at x = %dPI/4 with eps = %f is %f\n",
                       i, EPS, derivative);
        }

        return EXIT_SUCCESS;
}
