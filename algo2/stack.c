#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define T char*

typedef struct {
    T* data;
    size_t size;
    size_t capacity;
} stack;

void stack_init(stack* stack, size_t capacity) {
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = capacity;
}

bool stack_empty(stack const* stack) {
    return stack->size == 0;
}

bool stack_full(stack const* stack) {
    return stack->size == stack->capacity;
}

bool stack_push(stack* stack, T const* value) {
    T* data;

    if (stack->size == stack->capacity) {
        return false;
    }

    data = realloc(stack->data, sizeof(T) * (stack->size + 1));
    if (!data) {
        return false;
    }
    data[stack->size] = *value;

    stack->data = data;
    ++stack->size;

    return true;
}

bool stack_pop(stack* stack, T* value) {
    T* data;

    if (stack->size == 0) {
        return false;
    }

    *value = stack->data[stack->size - 1];
    if (stack->size == 1) {
        free(stack->data);
        data = NULL;
    } else {
        data = realloc(stack->data, sizeof(T) * (stack->size - 1));
        if (!data) {
            return false;
        }
    }

    stack->data = data;
    --stack->size;

    return true;
}

void stack_free(stack* stack) {
    free(stack->data);
    stack_init(stack, 0);
}

int32_t main(int32_t argc, char* argv[]) {
    stack stack;
    T value;

    stack_init(&stack, argc);
    while (!stack_full(&stack)) {
        if (!stack_push(&stack, &argv[stack.size])) {
            return EXIT_FAILURE;
        }
    }
    while (!stack_empty(&stack)) {
        if (!stack_pop(&stack, &value)) {
            return EXIT_FAILURE;
        }
        puts(value);
    }
    stack_free(&stack);

    return EXIT_SUCCESS;
}
