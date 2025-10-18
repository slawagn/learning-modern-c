#include "minunit.h"
#include <stdbool.h>
#include <stdio.h>

#include "quick_sort.c"

int tests_run = 0;

bool array_eq(double a[], double b[], size_t n)
{
        for (int i = 0; i < n; ++i) {
                if (a[i] != b[i])
                        return false;
        }
        return true;
}

#define LEN1 5
static char *unsorted_array_odd_len_test()
{
        double src[LEN1] = {2.7, 2.4, 1.0, 5.0, 6.0};
        double expected[LEN1] = {1.0, 2.4, 2.7, 5.0, 6.0};

        quick_sort(src, 0, LEN1);

        mu_assert("should sort the array of odd length ascending",
                  array_eq(src, expected, LEN1));
        return 0;
}

#define LEN2 6
static char *unsorted_array_even_len_test()
{
        double src[LEN2] = {2.7, 2.4, 1.0, 5.0, 6.0, 5.4};
        double expected[LEN2] = {1.0, 2.4, 2.7, 5.0, 5.4, 6.0};

        quick_sort(src, 0, LEN2);

        mu_assert("should sort the array of even length ascending",
                  array_eq(src, expected, LEN2));
        return 0;
}

#define LEN3 5
static char *sorted_array_test()
{
        double src[LEN3] = {1.0, 2.4, 2.7, 5.0, 6.0};
        double expected[LEN3] = {1.0, 2.4, 2.7, 5.0, 6.0};

        quick_sort(src, 0, LEN3);

        mu_assert("should leave the sorted array as is",
                  array_eq(src, expected, LEN3));
        return 0;
}

static char *all_tests()
{
        mu_run_test(unsorted_array_odd_len_test);
        mu_run_test(unsorted_array_even_len_test);
        mu_run_test(sorted_array_test);

        return 0;
}

int main(int argc, char **argv)
{
        char *result = all_tests();
        if (result != 0) {
                printf("%s\n", result);
        } else {
                printf("ALL TESTS PASSED\n");
        }
        printf("Tests run: %d\n", tests_run);

        return result != 0;
}
