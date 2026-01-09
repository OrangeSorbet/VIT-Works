#ifndef BT_H
#define BT_H

#include <stdio.h>
#include "5.stack_queue_func.h"
#include "btree_func.h"

Tree t;
Stack s;
Queue q;

void tree_add_BT(Tree **t, int value) {
    if (t == NULL) return;

    Tree *newn = (Tree *)calloc(1, sizeof(Tree));
    if (!newn) return;
    newn->value = value;

    if (*t == NULL) {
        *t = newn;
        return;
    }

    q_init(&q);
    q_enq_p(&q, *t);

    while (!q_empty(&q)) {
        Tree *check = q_deq_p(&q);

        if (check->left == NULL) {
            check->left = newn;
            break;
        }
        else {
            q_enq_p(&q, check->left);
        }

        if (check->right == NULL) {
            check->right = newn;
            break;
        }
        else {
            q_enq_p(&q, check->right);
        }
    }

    q_clear(&q);
}

void update_value_BT(Tree *t, int index, int value) {
    if (t == NULL) {
        return;
    }

    int count = 0;
    q_init(&q);
    q_enq_p(&q, t);
    while(!q_empty(&q)) {
        Tree *check = q_deq_p(&q);
        if (index == count) {
            check->value = value;
            return;
        }
        count++;
        if (check->left != NULL) {
            q_enq_p(&q, check->left);
        }
        if (check->right != NULL) {
            q_enq_p(&q, check->right);
        }
    }
}

void delete_value_BT(Tree **t, int index) {
    if (*t == NULL) return;

    int count = 0;
    Tree *to_delete = NULL;
    Tree *father = NULL;
    Tree *youngest = NULL;

    q_init(&q);
    q_enq_p(&q, *t);

    if (index == 0 && (*t)->left == NULL && (*t)->right == NULL) {
        free(*t);
        *t = NULL;
        q_clear(&q);
        return;
    }

    while (!q_empty(&q)) {
        Tree *check = q_deq_p(&q);

        if (count == index) {
            to_delete = check;
        }
        count++;

        if (check->left != NULL) {
            q_enq_p(&q, check->left);
            youngest = check->left;
            father = check;
        }
        if (check->right != NULL) {
            q_enq_p(&q, check->right);
            youngest = check->right;
            father = check;
        }
    }
    q_clear(&q);

    if (to_delete == NULL || youngest == NULL) {
        return;
    }

    if (*t == to_delete && youngest == to_delete) {
        free(*t);
        *t = NULL;
        return;
    }

    to_delete->value = youngest->value;

    if (father != NULL) {
        if (father->left == youngest) father->left = NULL;
        else if (father->right == youngest) father->right = NULL;
    }

    free(youngest);
}

#endif