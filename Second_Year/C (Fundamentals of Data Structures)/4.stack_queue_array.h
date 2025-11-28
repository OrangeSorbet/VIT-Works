#include <stdlib.h>
#include <stdlib.h>

#ifndef STACK_QUEUE_ARRAY_H
#define STACK_QUEUE_ARRAY_H

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

typedef struct {
    int data[MAX];
    int head;
    int tail;
} Queue;

void s_init(Stack *s) {
    s->top = -1;
}

int s_empty(Stack *s) {
    return s->top == -1;
}

int s_full(Stack *s) {
    return s->top == MAX - 1;
}

void s_push(Stack *s, int value) {
    if (!s_full(s)) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int s_pop(Stack *s) {
    if (!s_empty(s)) {
        return s->data[s->top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

void s_read(Stack *s) {
    if (!s_empty(s)) {
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    }
}

void q_init(Queue *q) {
    q->head = -1;
    q->tail = -1;
}

int q_empty(Queue *q) {
    return q->head == -1;
}

int q_full(Queue *q) {
    return q->tail == MAX - 1;
}

void q_enq(Queue *q, int value) {
    if (q_full(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q_empty(q)) {
        q->head = 0;
    }
    q->tail++;
    q->data[q->tail] = value;
}

int q_deq(Queue *q) {
    if (q_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    int value = q->data[q->head];
    
    if (q->head == q->tail) {
        q_init(q);
    } 
    else {
        q->head++;
    }
    return value;
}

void q_read(Queue *q) {
    if (!q_empty(q)) {
        for (int i = q->head; i <= q->tail; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

#endif