#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define T int32_t

T const* binary_search(T const* begin, T const* end, T value) {
    if (end < begin) {
        return NULL;
    }
    T const* current = begin + (end - begin) / 2;
    if (value < *current) {
        return binary_search(begin, current - 1, value);
    }
    if (*current < value) {
        return binary_search(current + 1, end, value);
    }
    return current;
}

T sum_evens(T begin, T end) {
    if (end <= begin) {
        return 0;
    }
    if (begin % 2 != 0) {
        return ++begin;
    }
    return begin + sum_evens(begin + 2, end);
}

int32_t main() {
    T array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%lu\n",
           binary_search(array, array + sizeof(array) / sizeof(T), 5) - array);
    printf("%i\n", sum_evens(2, 7));
}
