#include <stdlib.h>
#include <stdio.h>
#ifndef STACK_QUEUE_FUNC_H
#define STACK_QUEUE_FUNC_H

typedef struct {
    struct Node *top;
} Stack;

typedef struct {
    struct Node *head;
    struct Node *tail;
} Queue;

struct Node {
    int data;
    void *ptr;
    struct Node *next;
};

void s_init(Stack *s) {
    s->top = NULL;
}

int s_empty(Stack *s) {
    return s->top == NULL;
}

void s_push(Stack *s, int value) {
    struct Node *newn = (struct Node *)calloc(1, sizeof(struct Node));
    if(newn) {
        newn->data = value;
        newn->next = s->top;
        s->top = newn;
    }
}

int s_pop(Stack *s) {
    if(!s_empty(s)) {
        struct Node *temp = s->top;
        int value = temp->data;
        s->top = temp->next;
        free(temp);
        return value;
    }
    return -1;
}

void s_push_p(Stack *s, void *value) {
    struct Node *newn = (struct Node *)calloc(1, sizeof(struct Node));
    if (newn) {
        newn->ptr = value;
        newn->next = s->top;
        s->top = newn;
    }
}

void *s_pop_p(Stack *s) {
    if (!s_empty(s)) {
        struct Node *temp = s->top;
        void *value = temp->ptr;
        s->top = temp->next;
        free(temp);
        return value;
    }
    return NULL;
}

int s_read(Stack *s) {
    if(!s_empty(s)) {
        struct Node *temp = s->top;
        while(temp != NULL) {
            int value = temp->data;
            printf("%d\n", value);
            temp = temp->next;
        }
    }
}

void q_init(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

int q_empty(Queue *q) {
    return q->head == NULL;
}

void q_enq(Queue *q, int value) {
    struct Node *newn = (struct Node *)calloc(1, sizeof(struct Node));
    if(newn) {
        newn->data = value;
        newn->next = NULL;
        if(q_empty(q)) {
            q->head = newn;
            q->tail = newn;
        }
        else {
            q->tail->next = newn;
            q->tail = newn;
        }
    }
}

int q_deq(Queue *q) {
    if(!q_empty(q)) {
        struct Node *temp = q->head;
        int value = temp->data;
        q->head = temp->next;
        temp->next = NULL;
        if(q->head == NULL) {
            q->tail = NULL;
        }
        free(temp);
        return value;
    }
    return -1;
}

void q_enq_p(Queue *q, void *value) {
    struct Node *newn = (struct Node *)calloc(1, sizeof(struct Node));
    if (newn) {
        newn->ptr = value;
        newn->next = NULL;
        if (q_empty(q)) {
            q->head = q->tail = newn;
        } else {
            q->tail->next = newn;
            q->tail = newn;
        }
    }
}

void *q_deq_p(Queue *q) {
    if (!q_empty(q)) {
        struct Node *temp = q->head;
        void *value = temp->ptr;
        q->head = temp->next;
        if (q->head == NULL)
            q->tail = NULL;
        free(temp);
        return value;
    }
    return NULL;
}

void q_read(Queue *q) {
    if(!q_empty(q)) {
        struct Node *temp = q->head;
        while(temp != NULL) {
            int value = temp->data;
            printf("%d ", value);
            temp = temp->next;
        }
        printf("\n");
    }
}

void q_clear(Queue *q) {
    while(!q_empty(q)) {
        q_deq(q);
    }
}

#endif