#include "merge_sort.c"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 4

int main()
{
        double src[ARRAY_SIZE] = {42.1, 39.05, 39.04, 1.001};
        double out[ARRAY_SIZE] = {0};

        merge_sort(src, out, 0, ARRAY_SIZE);

        for (size_t i = 0; i < ARRAY_SIZE; ++i) {
                printf("%f ", src[i]);
        }
        printf("\n");
        for (size_t i = 0; i < ARRAY_SIZE; ++i) {
                printf("%f ", out[i]);
        }
        printf("\n");

        return EXIT_SUCCESS;
}
