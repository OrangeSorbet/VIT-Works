#include <stdio.h>
#include <stdlib.h>
#include "5.stack_queue_func.h"
#ifndef AVL_H
#define AVL_H

Queue q;
typedef struct Tree {
    int value;
    Tree *left, *right, *parent;
    int height;
} Tree;

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Tree *t) {
    return t ? t->height : 0;
}

Tree* left_rotate(Tree *t) {
    Tree *tattach = t->right;
    Tree *rightattach = tattach->left;
    tattach->left = t;
    t->right = rightattach;

    if(rightattach) rightattach->parent = t;
    tattach->parent =  t->parent;

    tattach->height = 1+max(height(tattach->left), height(tattach->right));
    t->height = 1+max(height(t->left), height(t->right));

    return tattach;
}

Tree* right_rotate(Tree *t) {
    Tree *tattach = t->left;
    Tree *leftattach = tattach->right;

    tattach->right = t;
    t->left = leftattach;

    if(leftattach) leftattach->parent = t;
    tattach->parent = t->parent;

    tattach->height = 1+max(height(tattach->left), height(tattach->right));
    t->height = 1+max(height(t->left), height(t->right));

    return tattach;
}

void avl_add(Tree **t, int value) {
    Tree *newn = (Tree *)malloc(sizeof(Tree));
    newn->height = 1;
    newn->left = NULL;
    newn->right = NULL;
    
    if(*t == NULL) {
        *t = newn;
        return;
    }

    Tree *parent = NULL;
    Tree *curr = *t;

    while(curr) {
        parent = curr;
        if(value < curr->value) curr = curr->left;
        if(value > curr->value ) curr = curr->right;
        else printf("No duplicates allowed!");
    }

    curr->parent = parent;
    if(value < parent->value) parent->left = newn;
    else parent->right = newn;

    curr = newn->parent;

    while(curr != NULL) {
        curr->height = 1+max(height(curr->left), height(curr->right));
        int balance = height(curr->left) - height(curr->right);

        //left left
        if(balance > 1 && value < curr->left->value) {
            Tree *newroot = right_rotate(curr);
            if(!newroot->parent) *t = newroot;
            else {
                
            }
        }
    }
}

#endif