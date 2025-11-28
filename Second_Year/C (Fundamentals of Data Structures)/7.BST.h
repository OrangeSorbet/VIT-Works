#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "5.stack_queue_func.h"
#include "btree_func.h"

Tree t;
Stack s;
Queue q;

int tree_add_BST(Tree **t, int value) {
    if (t == NULL) return 0;

    Tree *curr = *t;
    Tree *parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (value < curr->value) curr = curr->left;
        else if (value > curr->value) curr = curr->right;
        else {
            printf("Value %d already exists in the BST. Duplicates not allowed.\n", value);
            return 0;
        };
    }
    
    Tree *newn = (Tree *)calloc(1, sizeof(Tree));
    if (!newn) return 0;
    newn->value = value;

    if (*t == NULL) {
        *t = newn;
        return 1;
    }
    else if (value < parent->value) parent->left = newn;
    else parent->right = newn;
    return 1;
}

Tree* delete_value_BST(Tree *t, int value) {
    if (t == NULL) return NULL;

    if (value < t->value) t->left = delete_value_BST(t->left, value);
    else if (value > t->value) t->right = delete_value_BST(t->right, value);
    else {
        if (!t->left) {
            Tree *tmp = t->right;
            free(t);
            return tmp;
        } else if (!t->right) {
            Tree *tmp = t->left;
            free(t);
            return tmp;
        } else {
            Tree *succ = t->right;
            while (succ->left) succ = succ->left;
            t->value = succ->value;
            t->right = delete_value_BST(t->right, succ->value);
        }
    }
    return t;
}

Tree* delete_all_BST(Tree *t, int value) {
    if (t == NULL) return NULL;

    t->left = delete_all_BST(t->left, value);
    t->right = delete_all_BST(t->right, value);

    if (t->value == value) {
        if (!t->left) {
            Tree *tmp = t->right;
            free(t);
            return tmp;
        } else if (!t->right) {
            Tree *tmp = t->left;
            free(t);
            return tmp;
        } else {
            Tree *succ = t->right;
            Tree *succParent = t;
            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }
            t->value = succ->value;

            if (succParent->left == succ) succParent->left = delete_all_BST(succ, succ->value);
            else succParent->right = delete_all_BST(succ, succ->value);
        }
    }

    return t;
}

void update_value_BST(Tree **t, int index, int new_value) {
    if (*t == NULL) return;

    int count = 0;
    q_init(&q);
    q_enq_p(&q, *t);

    Tree *old_node = NULL;
    while (!q_empty(&q)) {
        Tree *curr = q_deq_p(&q);
        if (count == index) { old_node = curr; break; }
        count++;
        if (curr->left) q_enq_p(&q, curr->left);
        if (curr->right) q_enq_p(&q, curr->right);
    }
    q_clear(&q);

    if (old_node) {
        int old_value = old_node->value;
        *t = delete_value_BST(*t, old_value);
        tree_add_BST(t, new_value);
    }
}

#endif