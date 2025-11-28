#ifndef BTREE_FUNC_H
#define BTREE_FUNC_H

#include <stdio.h>
#include "5.stack_queue_func.h"

extern Stack s;
extern Queue q;

typedef struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

void tree_init(Tree **t) {
    *t = NULL;
}

int count_nodes(Tree *t) {
    if (!t) return 0;
    return 1 + count_nodes(t->left) + count_nodes(t->right);
}
/*
void tree_read_preorder(Tree *t) {
    if (t == NULL) printf("Tree is empty.\n");
        return;
    printf("%d\n", t->value);
    tree_read_preorder(t->left);
    tree_read_preorder(t->right);
}

void tree_read_inorder(Tree *t) {
    if (t == NULL) printf("Tree is empty.\n");
        return;
    tree_read_inorder(t->left);
    printf("%d\n", t->value);
    tree_read_inorder(t->right);
}

void tree_read_postorder(Tree *t) {
    if (t == NULL) printf("Tree is empty.\n");
        return;
    tree_read_postorder(t->left);
    tree_read_postorder(t->right);
    printf("%d\n", t->value);
}
*/

void tree_read_preorder(Tree *t) {
    if (t == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    s_init(&s);
    s_push_p(&s, t);

    while (!s_empty(&s)) {
        Tree *node = s_pop_p(&s);
        printf("%d\n", node->value);

        if (node->right)
            s_push_p(&s, node->right);
        if (node->left)
            s_push_p(&s, node->left);
    }
}

void tree_read_inorder(Tree *t) {
    if (t == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    s_init(&s);
    Tree *curr = t;

    while (curr != NULL || !s_empty(&s)) {
        while (curr != NULL) {
            s_push_p(&s, curr);
            curr = curr->left;
        }

        curr = s_pop_p(&s);
        printf("%d\n", curr->value);
        curr = curr->right;
    }
}

void tree_read_postorder(Tree *t) {
    if (t == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    Stack s1, s2;
    s_init(&s1);
    s_init(&s2);

    s_push_p(&s1, t);

    while (!s_empty(&s1)) {
        Tree *node = s_pop_p(&s1);
        s_push_p(&s2, node);

        if (node->left)
            s_push_p(&s1, node->left);
        if (node->right)
            s_push_p(&s1, node->right);
    }

    while (!s_empty(&s2)) {
        Tree *node = s_pop_p(&s2);
        printf("%d\n", node->value);
    }
}

void tree_read_breadthfirst(Tree *t) {
    if (t == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    q_init(&q);
    q_enq_p(&q, t);
    while(!q_empty(&q)) {
        Tree *check = q_deq_p(&q);
        printf("%d\n", check->value);
        if (check->left != NULL) {
            q_enq_p(&q, check->left);
        }
        if (check->right != NULL) {
            q_enq_p(&q, check->right);
        }
    }
}

void delete_tree(Tree **t) {
    if (*t == NULL)
        return;

    delete_tree(&((*t)->left));
    delete_tree(&((*t)->right));
    free(*t);
    *t = NULL;
}

#endif