#include <stddef.h>

void copy_array(double src[], double out[], size_t count)
{
        for (int i = 0; i < count; ++i) {
                out[i] = src[i];
        }

        return;
}

void merge(double src[], size_t start, size_t middle, size_t end, double out[])
{
        size_t i = start;
        size_t j = middle;
        for (size_t k = start; k < end; ++k) {
                if (i < middle && (j >= end || src[i] <= src[j])) {
                        out[k] = src[i];
                        ++i;
                } else {
                        out[k] = src[j];
                        ++j;
                }
        }

        return;
}

void split_merge(double src[], size_t start, size_t end, double out[])
{
        if (end - start <= 1) {
                return;
        }

        size_t middle = start + (end - start) / 2;
        split_merge(out, start, middle, src);
        split_merge(out, middle, end, src);

        merge(src, start, middle, end, out);

        return;
}

void merge_sort(double src[], double out[], size_t start, size_t end)
{
        copy_array(src, out, end - start);
        split_merge(out, 0, end, src);

        return;
}
