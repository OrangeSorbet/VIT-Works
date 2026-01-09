#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_QUEUE_DYNAMIC_H
#define STACK_QUEUE_DYNAMIC_H

/*===========================
           STACK
===========================*/
typedef struct {
    int *data;
    int top;
    int size;  // number of elements
} Stack;

void s_init(Stack *s) {
    s->data = NULL;
    s->top = -1;
    s->size = 0;
}

int s_empty(Stack *s) {
    return s->size == 0;
}

void s_push(Stack *s, int value) {
    int *tmp = realloc(s->data, (s->size + 1) * sizeof(int));
    if (!tmp) {
        printf("Stack realloc failed\n");
        return;
    }

    s->data = tmp;
    s->top++;
    s->data[s->top] = value;
    s->size++;
}

int s_pop(Stack *s) {
    if (s_empty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }

    int val = s->data[s->top--];
    s->size--;

    int *tmp = realloc(s->data, s->size * sizeof(int));
    if (tmp || s->size == 0)   // valid even if tmp==NULL when size==0
        s->data = tmp;

    return val;
}

void s_read(Stack *s) {
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->data[i]);
    printf("\n");
}

void s_free(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->top = -1;
    s->size = 0;
}

/*===========================
           QUEUE
===========================*/

typedef struct {
    int *data;
    int head;
    int tail;
    int size;
} Queue;

void q_init(Queue *q) {
    q->data = NULL;
    q->head = -1;
    q->tail = -1;
    q->size = 0;
}

int q_empty(Queue *q) {
    return q->size == 0;
}

void q_enq(Queue *q, int value) {
    int *tmp = realloc(q->data, (q->size + 1) * sizeof(int));
    if (!tmp) {
        printf("Queue realloc failed\n");
        return;
    }

    q->data = tmp;

    if (q_empty(q)) {
        q->head = 0;
        q->tail = 0;
    } else {
        q->tail++;
    }

    q->data[q->tail] = value;
    q->size++;
}

int q_deq(Queue *q) {
    if (q_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int val = q->data[q->head];

    // Shift left like normal array queue
    for (int i = 0; i < q->tail; i++)
        q->data[i] = q->data[i + 1];

    q->tail--;
    q->size--;

    int *tmp = realloc(q->data, q->size * sizeof(int));
    if (tmp || q->size == 0)
        q->data = tmp;

    if (q->size == 0)
        q->head = q->tail = -1;

    return val;
}

void q_read(Queue *q) {
    if (q_empty(q)) {
        printf("Queue empty\n");
        return;
    }

    for (int i = q->head; i <= q->tail; i++)
        printf("%d ", q->data[i]);
    printf("\n");
}

void q_free(Queue *q) {
    free(q->data);
    q->data = NULL;
    q->head = q->tail = -1;
    q->size = 0;
}

#endif