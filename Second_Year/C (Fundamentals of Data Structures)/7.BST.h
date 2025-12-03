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

Tree *delete_value_BST(Tree *root, int value)
{
    Tree *cur = root;
    Tree *parent = NULL;

    while (cur != NULL && cur->value != value)
    {
        parent = cur;
        if (value < cur->value)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (cur == NULL)
        return root;

    if (cur->left != NULL && cur->right != NULL)
    {
        Tree *succ = cur->right;
        Tree *succParent = cur;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        cur->value = succ->value;

        cur = succ;
        parent = succParent;
    }

    Tree *child = (cur->left != NULL) ? cur->left : cur->right;

    if (parent == NULL)
    {
        free(cur);
        return child;
    }
    if (parent->left == cur)
        parent->left = child;
    else
        parent->right = child;

    free(cur);
    return root;
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