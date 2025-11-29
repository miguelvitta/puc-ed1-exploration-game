#include "Stack.h"

#define INITIAL_CAPACITY 10

// Create and initialize a new stack
Stack stack_create(void) {
    Stack s;
    s.capacity = INITIAL_CAPACITY;
    s.size = 0;
    s.arr = (StackItem *)malloc(INITIAL_CAPACITY * sizeof(StackItem));

    if (s.arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for stack creation.\n");
        exit(EXIT_FAILURE);
    }

    return s;
}

// Free the stack's internal memory
void stack_free(Stack *s) {
    if (s == NULL) return;
    
    if (s->arr != NULL) {
        free(s->arr);
        s->arr = NULL;
    }
    s->capacity = 0;
    s->size = 0;
}

// Push a generic item onto the top of the stack
void stack_push(Stack *s, StackItem item) {
    if (s == NULL) return;

    // Expand capacity if full
    if (s->size == s->capacity) {
        int new_capacity = s->capacity * 2;
        StackItem *new_arr = (StackItem *)realloc(s->arr, new_capacity * sizeof(StackItem));
        
        if (new_arr == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed for stack push.\n");
            exit(EXIT_FAILURE);
        }
        
        s->arr = new_arr;
        s->capacity = new_capacity;
    }

    s->arr[s->size++] = item;
}

// Remove and return the item at the top of the stack
StackItem stack_pop(Stack *s) {
    if (s == NULL || s->size == 0) {
        // You might want to log a warning here or return NULL
        return NULL;
    }
    s->size--;
    return s->arr[s->size];
}

// Return the item at the top of the stack without removing it
StackItem stack_peek(Stack *s) {
    if (s == NULL || s->size == 0) {
        return NULL;
    }
    return s->arr[s->size - 1];
}

// Check if the stack is empty
int stack_is_empty(Stack *s) {
    if (s == NULL) return 1;
    return (s->size == 0);
}

// Get the number of elements currently in the stack
int stack_size(Stack *s) {
    if (s == NULL) return 0;
    return s->size;
}

// Remove all elements from the stack
void stack_clear(Stack *s, void (*free_item_func)(void*)) {
    if (s == NULL) return;

    // If a cleaning function was provided, use it on every item
    if (free_item_func != NULL) {
        for (int i = 0; i < s->size; i++) {
            if (s->arr[i] != NULL) {
                free_item_func(s->arr[i]);
            }
        }
    }

    s->size = 0;
    // We do not free s->arr here, so the stack can be reused immediately
}