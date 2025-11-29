#ifndef QUEUE_H
#define QUEUE_H

// Typed FIFO queue storing Position elements for BFS and movement operations.
// Includes creation, destruction, enqueue, dequeue, peek and empty-check functions.

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    Position *arr;   // dynamic circular buffer
    int capacity;    // allocated size
    int size;        // number of valid elements
    int head;        // index of oldest element
    int tail;        // index for next insertion
} Queue;

// Create a queue
Queue queue_create(void);

// Free internal memory of queue; does not free the Queue itself
void queue_free(Queue *q);

// Insert a Position at the tail, expanding if needed
void queue_enqueue(Queue *q, Position value);

// Remove and return the Position at the head
Position queue_dequeue(Queue *q);

// Return the Position at the head without removing it
Position queue_peek(const Queue *q);

// Check if queue is empty
int queue_is_empty(const Queue *q);

// Number of elements
int queue_size(const Queue *q);

// Remove all logical elements but keep allocated memory
void queue_clear(Queue *q);

#endif
