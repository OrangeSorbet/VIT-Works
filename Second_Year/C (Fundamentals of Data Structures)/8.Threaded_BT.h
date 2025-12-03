#ifndef BT_H
#define BT_H

#include <stdio.h>
#include <stdlib.h>
#include "5.stack_queue_func.h"

Stack s;
Queue q;

typedef struct ThTree {
    int value;
    struct ThTree *left;
    struct ThTree *right;
    int rthread;
} ThTree;

void TBT_init(ThTree **t) {
    *t = NULL;
}

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
    printf("Node added!\n");
}

void preorder_TBT(ThTree *t) {
    if (t == NULL) {
        printf("Tree empty!\n");
        return;
    }

    s_init(&s);
    s_push_p(&s, t);

    while (!s_empty(&s)) {
        ThTree *n = s_pop_p(&s);
        printf("%d ", n->value);

        if (n->rthread == 0 && n->right)
            s_push_p(&s, n->right);
        if (n->left)
            s_push_p(&s, n->left);
    }
}

void inorder_TBT(ThTree *t) {
    if (t == NULL) {
        printf("Tree empty!\n");
        return;
    }
    ThTree *curr = t;
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

void postorder_TBT(ThTree *t) {
    if (t == NULL) {
        printf("Tree empty!\n");
        return;
    }

    Stack s2;
    s_init(&s);
    s_init(&s2);
    s_push_p(&s, t);

    while (!s_empty(&s)) {
        ThTree *n = s_pop_p(&s);
        s_push_p(&s2, n);

        if (n->rthread == 0 && n->right)
            s_push_p(&s, n->right);
        if (n->left)
            s_push_p(&s, n->left);
    }

    while (!s_empty(&s2)) {
        ThTree *printval = s_pop_p(&s2);
        printf("%d ", printval->value);
    }
}

void breadthfirst_TBT(ThTree *t) {
    if (t == NULL) {
        printf("Tree empty!\n");
        return;
    }

    q_init(&q);
    q_enq_p(&q, t);

    while (!q_empty(&q)) {
        ThTree *n = q_deq_p(&q);
        printf("%d ", n->value);

        if (n->left)
            q_enq_p(&q, n->left);
        if (n->rthread == 0 && n->right)
            q_enq_p(&q, n->right);
    }
}

void update_value_TBT(ThTree **t, int old_value, int new_value) {
    if (*t == NULL) {
        printf("Tree empty!\n");
        return;
    }

    int found = 0;

    q_init(&q);
    q_enq_p(&q, *t);

    while (!q_empty(&q)) {
        ThTree *check = q_deq_p(&q);

        if (check->value == old_value) {
            check->value = new_value;
            printf("Value %d updated to %d.\n", old_value, new_value);
            found = 1;
            break;
        }

        if (check->left)
            q_enq_p(&q, check->left);
        if (check->rthread == 0 && check->right)
            q_enq_p(&q, check->right);
    }

    if (!found)
        printf("Value not found!\n");
}

void delete_value_TBT(ThTree **t, int value) {
    if (*t == NULL) {
        printf("Tree is empty\n");
        return;
    }

    ThTree *to_delete = NULL;
    ThTree *father = NULL;
    ThTree *youngest = NULL;

    q_init(&q);
    q_enq_p(&q, *t);

    while (!q_empty(&q)) {
        ThTree *check = q_deq_p(&q);

        if (check->value == value && to_delete == NULL) {
            to_delete = check;
        }

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
        printf("Value not found!\n");
        return;
    }

    if (*t == to_delete && youngest == to_delete) {
        free(*t);
        *t = NULL;
        printf("Root deleted!\n");
        return;
    }

    to_delete->value = youngest->value;

    if (father != NULL) {
        if (father->left == youngest) father->left = NULL;
        else if (father->right == youngest) father->right = NULL;
    }

    free(youngest);
    printf("Deletion complete\n");
}

void delete_TBT(ThTree **t) {
    if (*t == NULL) return;

    q_init(&q);
    q_enq_p(&q, *t);

    while (!q_empty(&q)) {
        ThTree *n = q_deq_p(&q);

        if (n->left)
            q_enq_p(&q, n->left);
        if (n->rthread == 0 && n->right)
            q_enq_p(&q, n->right);

        free(n);
    }

    *t = NULL;
}

#endif