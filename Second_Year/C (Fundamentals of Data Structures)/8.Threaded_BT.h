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
    ThTree *ptr = *t;
    ThTree *par = NULL;

    while (ptr != NULL) {
        par = ptr;
        if (value < ptr->value)
            ptr = ptr->left;
        else if (ptr->rthread == 0)
            ptr = ptr->right;
        else
            break;
    }

    ThTree *newn = (ThTree *)calloc(1, sizeof(ThTree));
    newn->value = value;
    newn->rthread = 1;

    if (par == NULL) {
        *t = newn;
        newn->left = NULL;
        newn->right = NULL;
        return;
    }

    if (value < par->value) {
        newn->left = par->left;
        newn->right = par;
        par->left = newn;
    } else {
        newn->left = NULL;
        newn->right = par->right;
        par->right = newn;
        par->rthread = 0;
    }
}

void inorder_TBT(ThTree *root) {
    ThTree *ptr = root;
    while (ptr && ptr->left) ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->value);
        if (ptr->rthread)
            ptr = ptr->right;
        else {
            ptr = ptr->right;
            while (ptr && ptr->left)
                ptr = ptr->left;
        }
    }
}

void update_value_TBT(ThTree *t, int index, int value) {
    if (t == NULL) {
        return;
    }

    int count = 0;
    q_init(&q);
    q_enq(&q, t);
    while(!q_empty(&q)) {
        ThTree *check = q_deq(&q);
        if (index == count) {
            check->value = value;
            return;
        }
        count++;
        if (check->left != NULL) {
            q_enq(&q, check->left);
        }
        if (check->right != NULL) {
            q_enq(&q, check->right);
        }
    }
}

void delete_value_TBT(ThTree **t, int index) {
    if (*t == NULL) return;

    int count = 0;
    ThTree *to_delete = NULL;
    ThTree *father = NULL;
    ThTree *youngest = NULL;

    q_init(&q);
    q_enq(&q, *t);

    while (!q_empty(&q)) {
        ThTree *check = q_deq(&q);

        if (count == index) {
            to_delete = check;
        }
        count++;

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