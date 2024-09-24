#include <stdint.h>
#include <stdio.h>

uint64_t ifactorial(uint64_t number) {
    uint64_t sum;
    uint64_t i;

    sum = 1;
    for (i = 1; i != number + 1; ++i) {
        sum *= i;
    }

    return sum;
}

uint64_t rfactorial(uint64_t number) {
    if (number) {
        return number * rfactorial(number - 1);
    } else {
        return 1;
    }
}

uint64_t rfibonacci(uint64_t number) {
    if (1 < number) {
        return rfibonacci(number - 1) + rfibonacci(number - 2);
    } else {
        return number;
    }
}

uint64_t rsum(uint64_t number) {
    if (number) {
        return number + rsum(number - 1);
    } else {
        return number;
    }
}

int32_t main() {
    printf("%lu\n", rsum(5));
}
