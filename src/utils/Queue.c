#include "Queue.h"
#include <stdlib.h>

#define QUEUE_DEFAULT_CAPACITY 10

static void queue_expand(Queue *q) {
    int new_capacity = q->capacity * 2;
    Position *new_arr = (Position *)malloc(new_capacity * sizeof(Position));

    int i = 0;
    while (i < q->size) {
        new_arr[i] = q->arr[(q->head + i) % q->capacity];
        i++;
    }

    free(q->arr);
    q->arr = new_arr;
    q->capacity = new_capacity;
    q->head = 0;
    q->tail = q->size;
}

Queue queue_create(void) {
    Queue q;

    q.capacity = QUEUE_DEFAULT_CAPACITY;
    q.arr = (Position *)malloc(QUEUE_DEFAULT_CAPACITY * sizeof(Position));

    if (q.arr == NULL) {
        q.capacity = 0;
        q.size = 0;
        q.head = 0;
        q.tail = 0;
        return q;
    }

    q.size = 0;
    q.head = 0;
    q.tail = 0;

    return q;
}


void queue_free(Queue *q) {
    if (q->arr != NULL) {
        free(q->arr);
    }
    q->arr = NULL;
    q->capacity = 0;
    q->size = 0;
    q->head = 0;
    q->tail = 0;
}

void queue_enqueue(Queue *q, Position value) {
    if (q->size == q->capacity) {
        queue_expand(q);
    }

    q->arr[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}

Position queue_dequeue(Queue *q) {
    Position value = q->arr[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return value;
}

Position queue_peek(const Queue *q) {
    return q->arr[q->head];
}

int queue_is_empty(const Queue *q) {
    return (q->size == 0);
}

int queue_size(const Queue *q) {
    return q->size;
}

void queue_clear(Queue *q) {
    q->size = 0;
    q->head = 0;
    q->tail = 0;
}
