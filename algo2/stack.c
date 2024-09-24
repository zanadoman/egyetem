#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define T uint64_t

typedef struct {
    T* _data;
    size_t _size;
    size_t _capacity;
} stack;

void stack_init(stack* stack, size_t capacity) {
    stack->_data = NULL;
    stack->_size = 0;
    stack->_capacity = capacity;
}

void stack_free(stack* stack) {
    free(stack->_data);
    stack_init(stack, 0);
}

size_t stack_size(stack const* stack) {
    return stack->_size;
}

size_t stack_capacity(stack const* stack) {
    return stack->_capacity;
}

bool stack_empty(stack const* stack) {
    return stack->_size == 0;
}

bool stack_full(stack const* stack) {
    return stack->_size == stack->_capacity;
}

bool stack_push(stack* stack, T const* value) {
    T* data;

    if (stack->_size == stack->_capacity) {
        return false;
    }

    data = realloc(stack->_data, sizeof(T) * (stack->_size + 1));
    if (!data) {
        return false;
    }
    data[stack->_size] = *value;

    stack->_data = data;
    ++stack->_size;

    return true;
}

bool stack_pop(stack* stack, T* value) {
    T* data;

    if (stack->_size == 0) {
        return false;
    }

    *value = stack->_data[stack->_size - 1];
    if (stack->_size == 1) {
        free(stack->_data);
        data = NULL;
    } else {
        data = realloc(stack->_data, sizeof(T) * (stack->_size - 1));
        if (!data) {
            return false;
        }
    }

    stack->_data = data;
    --stack->_size;

    return true;
}

int32_t main(int32_t argc, char* argv[]) {
    // stack stack;
    // T value;
    //
    // stack_init(&stack, argc);
    // while (!stack_full(&stack)) {
    //     if (!stack_push(&stack, &argv[stack_size(&stack)])) {
    //         return EXIT_FAILURE;
    //     }
    // }
    // while (!stack_empty(&stack)) {
    //     if (!stack_pop(&stack, &value)) {
    //         return EXIT_FAILURE;
    //     }
    //     puts(value);
    // }
    // stack_free(&stack);

    // T number;
    // stack stack;
    // T sum;
    //
    // number = 5;
    // stack_init(&stack, number);
    //
    // while (number) {
    //     if (!stack_push(&stack, &number)) {
    //         return EXIT_FAILURE;
    //     }
    //     --number;
    // }
    // sum = 1;
    // while (!stack_empty(&stack)) {
    //     if (!stack_pop(&stack, &number)) {
    //         return EXIT_FAILURE;
    //     }
    //     sum *= number;
    // }
    // printf("%lu\n", sum);

    return EXIT_SUCCESS;
}
