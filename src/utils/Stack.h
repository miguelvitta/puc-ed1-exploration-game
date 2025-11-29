#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

// Define a generic item type (void pointer) so the stack can hold any data.
typedef void* StackItem;

// Stack structure definition
typedef struct {
    StackItem *arr;  // Dynamic array of generic pointers
    int capacity;    // Total allocated capacity
    int size;        // Current number of elements
} Stack;

// Create and initialize a new stack
Stack stack_create(void);

// Free the stack's internal memory (does not free the elements themselves)
void stack_free(Stack *s);

// Push a generic item onto the top of the stack, expanding capacity if needed
void stack_push(Stack *s, StackItem item);

// Remove and return the item at the top of the stack
StackItem stack_pop(Stack *s);

// Return the item at the top of the stack without removing it
StackItem stack_peek(Stack *s);

// Check if the stack is empty (returns 1 if empty, 0 otherwise)
int stack_is_empty(Stack *s);

// Get the number of elements currently in the stack
int stack_size(Stack *s);

// Remove all elements from the stack (optionally freeing them if a function is provided)
void stack_clear(Stack *s, void (*free_item_func)(void*));

#endif