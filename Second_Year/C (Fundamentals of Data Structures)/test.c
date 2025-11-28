#include <stdio.h>

typedef struct Node {
    int val;
    Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

typedef struct {
    Node *top;
} Stack;

void q_init(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

int q_empty(Queue *q) {
    return q->head == NULL && q->tail == NULL;
}

void q_read(Queue *q) {
    Node *temp = q->head;
    while(temp!= NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void q_enq(Queue *q, int val) {
    Node *newn = (Node *)malloc(sizeof(Node));
    newn->val = val;
    newn->next = NULL;

    if(q_empty(q)) {
        q->head = newn;
        q->tail = newn;
    }
    else{
        q->tail->next = newn;
        q->tail = newn;
    }
}

int q_deq(Queue *q) {
    if(q_empty(q)) {
        return -1; // Queue is empty
    }
    Node *temp = q->head;
    int val = temp->val;
    q->head = q->head->next;
    free(temp);
    return val;
}

void q_clear(Queue *q) {
    while(!q_empty(q)) {
        q_deq(q);
    }
}

void s_init(Stack *s) {
    s->top = NULL;
}

int s_empty(Stack *s) {
    return s->top == NULL;
}

void s_read(Stack *s) {
    Node *temp = s->top;
    while(temp!= NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void s_push(Stack *s, int val) {
    Node *newn = (Node *)malloc(sizeof(Node));
    newn->val = val;
    newn->next = s->top;
    s->top = newn;
}

int s_pop(Stack *s) {
    if(s_empty(s)) {
        return -1;
    }
    Node *temp = s->top;
    int val = temp->val;
    s->top = s->top->next;
    free(temp);
    return val;
}

void s_clear(Stack *s) {
    while(!s_empty(s)) {
        s_pop(s);
    }
}