#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define T int32_t

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

int32_t stack_empty(stack* stack) {
    return stack->size == 0;
}

int32_t stack_full(stack* stack) {
    return stack->size == stack->capacity;
}

int32_t stack_push(stack* stack, T value) {
    T* data;

    if (stack->size == stack->capacity) {
        return 1;
    }

    data = realloc(stack->data, sizeof(T) * (stack->size + 1));
    if (!data) {
        return 1;
    }
    data[stack->size] = value;

    stack->data = data;
    ++stack->size;

    return 0;
}

int32_t stack_pop(stack* stack, T* value) {
    T* data;

    if (stack->size == 0) {
        return 1;
    }

    *value = stack->data[stack->size - 1];
    if (stack->size == 1) {
        free(stack->data);
        stack->data = NULL;
    } else {
        data = realloc(stack->data, sizeof(T) * (stack->size - 1));
        if (!data) {
            return 1;
        }
    }

    stack->data = data;
    --stack->size;

    return 0;
}

void stack_free(stack* stack) {
    free(stack->data);
    stack_init(stack, 0);
}

int32_t main() {
    stack stack;
    T value;

    stack_init(&stack, 10);
    for (size_t i = 0; !stack_full(&stack); ++i) {
        stack_push(&stack, i);
    }
    for (size_t i = 0; !stack_empty(&stack); ++i) {
        stack_pop(&stack, &value);
        printf("%i\n", value);
    }
}
