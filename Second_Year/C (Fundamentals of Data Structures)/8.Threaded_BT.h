#ifndef TBT_H
#define TBT_H

#include <stdio.h>
#include <stdlib.h>
#include "5.stack_queue_func.h"

typedef struct ThTree {
    int value;
    struct ThTree *left;
    struct ThTree *right;
    int rthread;
} ThTree;

void TBT_init(ThTree **t) {
    if (t) *t = NULL;
}

int TBT_insert(ThTree **t, int value) {
    if (!t) return 0;

    ThTree *curr = *t;
    ThTree *parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (value < curr->value)
            curr = curr->left;
        else if (!curr->rthread)
            curr = curr->right;
        else
            break;
    }

    ThTree *newn = (ThTree *)calloc(1, sizeof(ThTree));
    if (!newn) return 0;
    newn->value = value;
    newn->rthread = 1;

    if (parent == NULL) {
        *t = newn;
        newn->left = NULL;
        newn->right = NULL;
        return 1;
    }

    if (value < parent->value) {
        newn->left = parent->left;
        newn->right = parent;
        parent->left = newn;
    } else {
        newn->left = NULL;
        newn->right = parent->right;
        parent->right = newn;
        parent->rthread = 0;
        if (!newn->right)
            newn->rthread = 1;
    }
    return 1;
}

int TBT_preorder(ThTree *t) {
    if (!t) {
        printf("Tree is empty.\n");
        return 0;
    }

    Stack s;
    s_init(&s);
    s_push_p(&s, t);

    while (!s_empty(&s)) {
        ThTree *n = s_pop_p(&s);
        printf("%d ", n->value);

        if (!n->rthread && n->right) s_push_p(&s, n->right);
        if (n->left) s_push_p(&s, n->left);
    }
    return 1;
}

int TBT_inorder(ThTree *t) {
    if (!t) {
        printf("Tree is empty.\n");
        return 0;
    }

    ThTree *curr = t;
    while (curr->left) curr = curr->left;

    while (curr) {
        printf("%d ", curr->value);
        if (curr->rthread)
            curr = curr->right;
        else {
            curr = curr->right;
            while (curr && curr->left) curr = curr->left;
        }
    }
    return 1;
}

int TBT_postorder(ThTree *t) {
    if (!t) {
        printf("Tree is empty.\n");
        return 0;
    }

    Stack s1, s2;
    s_init(&s1);
    s_init(&s2);

    s_push_p(&s1, t);

    while (!s_empty(&s1)) {
        ThTree *n = s_pop_p(&s1);
        s_push_p(&s2, n);

        if (!n->rthread && n->right) s_push_p(&s1, n->right);
        if (n->left) s_push_p(&s1, n->left);
    }

    while (!s_empty(&s2)) {
        ThTree *n = s_pop_p(&s2);
        printf("%d ", n->value);
    }
    return 1;
}

int TBT_breadthfirst(ThTree *t) {
    if (!t) {
        printf("Tree is empty.\n");
        return 0;
    }

    Queue q;
    q_init(&q);
    q_enq_p(&q, t);

    while (!q_empty(&q)) {
        ThTree *n = q_deq_p(&q);
        printf("%d ", n->value);

        if (n->left) q_enq_p(&q, n->left);
        if (!n->rthread && n->right) q_enq_p(&q, n->right);
    }
    return 1;
}

int TBT_update(ThTree *t, int old_value, int new_value) {
    if (!t) return 0;

    Queue q;
    q_init(&q);
    q_enq_p(&q, t);
    int found = 0;

    while (!q_empty(&q)) {
        ThTree *n = q_deq_p(&q);

        if (n->value == old_value) {
            n->value = new_value;
            found = 1;
            break;
        }

        if (n->left) q_enq_p(&q, n->left);
        if (!n->rthread && n->right) q_enq_p(&q, n->right);
    }
    return found;
}

int TBT_delete(ThTree **t, int value) {
    if (!t || !*t) return 0;

    Queue q;
    q_init(&q);
    q_enq_p(&q, *t);

    ThTree *node_to_delete = NULL;
    ThTree *last_node = NULL;
    ThTree *parent_of_last = NULL;

    while (!q_empty(&q)) {
        ThTree *n = q_deq_p(&q);

        if (n->value == value && !node_to_delete) node_to_delete = n;

        if (n->left) {
            parent_of_last = n;
            last_node = n->left;
            q_enq_p(&q, n->left);
        }
        if (!n->rthread && n->right) {
            parent_of_last = n;
            last_node = n->right;
            q_enq_p(&q, n->right);
        }
    }

    if (!node_to_delete) return 0;
    if (!last_node) {
        free(*t);
        *t = NULL;
        return 1;
    }

    node_to_delete->value = last_node->value;

    if (parent_of_last) {
        if (parent_of_last->left == last_node) parent_of_last->left = NULL;
        else parent_of_last->right = NULL;
    }
    free(last_node);
    return 1;
}

int TBT_delete_tree(ThTree **t) {
    if (!t || !*t) return 0;

    Queue q;
    q_init(&q);
    q_enq_p(&q, *t);

    while (!q_empty(&q)) {
        ThTree *n = q_deq_p(&q);

        if (n->left) q_enq_p(&q, n->left);
        if (!n->rthread && n->right) q_enq_p(&q, n->right);

        free(n);
    }
    *t = NULL;
    return 1;
}

#endif