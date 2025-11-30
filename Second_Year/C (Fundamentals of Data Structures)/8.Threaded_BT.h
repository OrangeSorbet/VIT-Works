#ifndef BT_H
#define BT_H

#include <stdio.h>
#include "5.stack_queue_func.h"
#include "btree_func.h"

typedef struct ThTree {
    int value;
    struct ThTree *left;
    struct ThTree *right;
    int rthread;
} ThTree;

void tree_add_TBT(ThTree **t, int value) {
    ThTree *curr = *t;
    ThTree *parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (value < curr->value)
            curr = curr->left;
        else if (curr->rthread == 0)
            curr = curr->right;
        else
            break;
    }

    ThTree *newn = (ThTree *)calloc(1, sizeof(ThTree));
    newn->value = value;
    newn->rthread = 1;

    if (parent == NULL) {
        *t = newn;
        newn->left = NULL;
        newn->right = NULL;
        return;
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

        if (newn->right == NULL)
            newn->rthread = 0;
    }
}

void inorder_TBT(ThTree *root) {
    ThTree *curr = root;
    while (curr && curr->left) curr = curr->left;

    while (curr != NULL) {
        printf("%d ", curr->value);
        if (curr->rthread)
            curr = curr->right;
        else {
            curr = curr->right;
            while (curr && curr->left)
                curr = curr->left;
        }
    }
}

void update_TBT(ThTree *t, int old_value, int new_value) {
    if (t == NULL) return;

    q_init(&q);
    q_enq(&q, t);

    while (!q_empty(&q)) {
        ThTree *check = q_deq(&q);

        if (check->value == old_value) {
            check->value = new_value;
            return;
        }

        if (check->left != NULL) {
            q_enq(&q, check->left);
        }
        if (check->right != NULL) {
            q_enq(&q, check->right);
        }
    }
}

void delete_value_TBT(ThTree **t, int value) {
    if (*t == NULL) return;

    ThTree *to_delete = NULL;
    ThTree *father = NULL;
    ThTree *youngest = NULL;

    q_init(&q);
    q_enq(&q, *t);

    while (!q_empty(&q)) {
        ThTree *check = q_deq(&q);

        if (check->value == value && to_delete == NULL) {
            to_delete = check;
        }

        if (check->left != NULL) {
            q_enq(&q, check->left);
            youngest = check->left;
            father = check;
        }
        if (check->right != NULL) {
            q_enq(&q, check->right);
            youngest = check->right;
            father = check;
        }
    }
    q_clear(&q);

    if (to_delete == NULL || youngest == NULL) return;

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