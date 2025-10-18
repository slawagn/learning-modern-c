#include <stdbool.h>
#include <stddef.h>

void swap(double *a, double *b)
{
        double tmp = *a;
        *a = *b;
        *b = tmp;
}

size_t partition(double arr[], size_t start_i, size_t end_i)
{
        size_t pivot_i = (start_i + end_i) / 2;
        double pivot = arr[pivot_i];

        size_t i = start_i;
        size_t j = end_i - 1;
        while (true) {
                while (i < j && arr[i] < pivot) {
                        ++i;
                }
                while (i < j && arr[j] > pivot) {
                        --j;
                }

                if (i >= j)
                        return j;

                swap(&arr[i], &arr[j]);
                ++i;
                --j;
        }
}

void quick_sort(double arr[], size_t start_i, size_t end_i)
{
        if (end_i <= start_i)
                return;

        size_t p = partition(arr, start_i, end_i);

        quick_sort(arr, start_i, p);
        quick_sort(arr, p + 1, end_i);

        return;
}
