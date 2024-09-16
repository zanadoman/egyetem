#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define T size_t

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

bool stack_empty(stack* stack) {
    return stack->size == 0;
}

bool stack_full(stack* stack) {
    return stack->size == stack->capacity;
}

bool stack_push(stack* stack, T value) {
    T* data;

    if (stack->size == stack->capacity) {
        return false;
    }

    data = realloc(stack->data, sizeof(T) * (stack->size + 1));
    if (!data) {
        return false;
    }
    data[stack->size] = value;

    stack->data = data;
    ++stack->size;

    return true;
}

int32_t stack_pop(stack* stack, T* value) {
    T* data;

    if (stack->size == 0) {
        return false;
    }

    *value = stack->data[stack->size - 1];
    if (stack->size == 1) {
        free(stack->data);
        stack->data = NULL;
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

int32_t main() {
    stack stack;
    T value;

    stack_init(&stack, 10);
    for (T i = 0; !stack_full(&stack); ++i) {
        stack_push(&stack, i);
    }
    for (size_t i = 0; !stack_empty(&stack); ++i) {
        stack_pop(&stack, &value);
        printf("%lu\n", value);
    }
}
