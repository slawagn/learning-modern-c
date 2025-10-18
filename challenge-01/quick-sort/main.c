
#include "quick_sort.c"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 4

void print(double arr[])
{
        for (size_t i = 0; i < ARRAY_SIZE; ++i) {
                printf("%f ", arr[i]);
        }
        printf("\n");
}

int main()
{
        double a[ARRAY_SIZE] = {42.1, 39.05, 39.04, 1.001};

        print(a);

        quick_sort(a, 0, ARRAY_SIZE);

        print(a);

        return EXIT_SUCCESS;
}
