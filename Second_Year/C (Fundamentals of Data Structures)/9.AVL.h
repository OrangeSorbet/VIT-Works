#ifndef AVL_H
#define AVL_H
#include <stdio.h>
#include <stdlib.h>
#include "5.stack_queue_func.h"

typedef struct Tree {
    int value;
    struct Tree *left, *right;
    int height;
} Tree;

int height(Tree *n) {
    return n ? n->height : 0;
}

int maxf(int a, int b) {
    return (a > b) ? a : b;
}

int getBalance(Tree *n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

Tree* rightRotate(Tree *y) {
    Tree *x = y->left;
    Tree *xr = x->right;

    x->right = y;
    y->left = xr;

    y->height = 1 + maxf(height(y->left), height(y->right));
    x->height = 1 + maxf(height(x->left), height(x->right));

    return x;
}

Tree* leftRotate(Tree *y) {
    Tree *x = y->right;
    Tree *xl = x->left;

    x->left = y;
    y->right = xl;

    y->height = 1 + maxf(height(y->left), height(y->right));
    x->height = 1 + maxf(height(x->left), height(x->right));

    return x;
}

Tree* avlInsert(Tree *node, int value) {
    Stack s;
    s_init(&s);

    Tree *curr = node;
    Tree *parent = NULL;

    while(curr != NULL) {
        s_push_p(&s, curr);
        parent = curr;

        if(value < curr->value)
            curr = curr->left;
        else if(value > curr->value)
            curr = curr->right;
        else
            return node;   // duplicate not allowed
    }

    Tree *newn = malloc(sizeof(Tree));
    newn->value = value;
    newn->left = newn->right = NULL;
    newn->height = 1;

    if (!node)
        return newn;

    if(value < parent->value)
        parent->left = newn;
    else
        parent->right = newn;

    // rebalance from bottom up
    while(!s_empty(&s)) {
        Tree *temp = s_pop_p(&s);

        temp->height = 1 + maxf(height(temp->left), height(temp->right));
        int balance = getBalance(temp);

        // LL
        if(balance > 1 && value < temp->left->value) {
            temp = rightRotate(temp);
        }
        // RR
        else if(balance < -1 && value > temp->right->value) {
            temp = leftRotate(temp);
        }
        // LR
        else if(balance > 1 && value > temp->left->value) {
            temp->left = leftRotate(temp->left);
            temp = rightRotate(temp);
        }
        // RL
        else if(balance < -1 && value < temp->right->value) {
            temp->right = rightRotate(temp->right);
            temp = leftRotate(temp);
        }

        // update root or attach back to parent
        if(s_empty(&s)) {
            node = temp;
        } else {
            Tree *p = s_top_p(&s);
            if(value < p->value) p->left = temp;
            else p->right = temp;
        }
    }

    return node;
}

Tree* minNode(Tree *node) {
    while(node->left)
        node = node->left;
    return node;
}

void preorder_AVL(Tree *t) {
    if(!t) return;

    Stack s;
    s_init(&s);
    s_push_p(&s, t);

    while(!s_empty(&s)) {
        Tree *curr = s_pop_p(&s);
        printf("%d ", curr->value);
        if(curr->right) s_push_p(&s, curr->right);
        if(curr->left) s_push_p(&s, curr->left);
    }
}

void inorder_AVL(Tree *t) {
    if(!t) return;

    Stack s;
    s_init(&s);
    Tree *curr = t;

    while(!s_empty(&s) || curr != NULL) {
        while(curr != NULL) {
            s_push_p(&s, curr);
            curr = curr->left;
        }
        curr = s_pop_p(&s);
        printf("%d ", curr->value);
        curr = curr->right;
    }
}

void postorder_AVL(Tree *t) {
    if(!t) return;

    Stack s1, s2;
    s_init(&s1);
    s_init(&s2);

    s_push_p(&s1, t);

    while(!s_empty(&s1)) {
        Tree *curr = s_pop_p(&s1);
        s_push_p(&s2, curr);

        if(curr->left) s_push_p(&s1, curr->left);
        if(curr->right) s_push_p(&s1, curr->right);
    }

    while(!s_empty(&s2)) {
        Tree *curr = s_pop_p(&s2);
        printf("%d ", curr->value);
    }
}

void breadthfirst_AVL(Tree *t) {
    if(!t) return;

    Queue q;
    q_init(&q);
    q_enq_p(&q, t);

    while(!q_empty(&q)) {
        Tree *curr = q_deq_p(&q);
        printf("%d ", curr->value);

        if(curr->left) q_enq_p(&q, curr->left);
        if(curr->right) q_enq_p(&q, curr->right);
    }
    printf("\n");
}

Tree* avlDelete(Tree *root, int value) {
    if (!root) return NULL;

    Stack s;
    s_init(&s);

    Tree *curr = root;
    Tree *parent = NULL;
    Tree *toDelete = NULL;

    while(curr != NULL) {
        s_push_p(&s, curr);
        if(value < curr->value) {
            parent = curr;
            curr = curr->left;
        } else if(value > curr->value) {
            parent = curr;
            curr = curr->right;
        } else {
            toDelete = curr;
            break;
        }
    }

    if (!toDelete) return root;

    Tree *child = NULL;
    if (!toDelete->left || !toDelete->right) {
        child = toDelete->left ? toDelete->left : toDelete->right;

        if (!parent) {
            free(toDelete);
            root = child;
            toDelete = NULL;
        } else {
            if(parent->left == toDelete) parent->left = child;
            else parent->right = child;
            free(toDelete);
            toDelete = NULL;
        }
    }
    else {
        Tree *succ = toDelete->right;
        Tree *succParent = toDelete;

        while(succ->left != NULL) {
            s_push_p(&s, succ);
            succParent = succ;
            succ = succ->left;
        }

        toDelete->value = succ->value;

        if(succParent->left == succ) succParent->left = succ->right;
        else succParent->right = succ->right;

        free(succ);
    }

    while(!s_empty(&s)) {
        Tree *temp = s_pop_p(&s);

        temp->height = 1 + maxf(height(temp->left), height(temp->right));
        int balance = getBalance(temp);

        // LL
        if(balance > 1 && getBalance(temp->left) >= 0)
            temp = rightRotate(temp);
        // RR
        else if(balance < -1 && getBalance(temp->right) <= 0)
            temp = leftRotate(temp);
        // LR
        else if(balance > 1 && getBalance(temp->left) < 0) {
            temp->left = leftRotate(temp->left);
            temp = rightRotate(temp);
        }
        // RL
        else if(balance < -1 && getBalance(temp->right) > 0) {
            temp->right = rightRotate(temp->right);
            temp = leftRotate(temp);
        }

        if(s_empty(&s)) root = temp;
        else {
            Tree *p = s_top_p(&s);
            if(temp->value < p->value) p->left = temp;
            else p->right = temp;
        }
    }
    return root;
}

Tree* avlUpdate(Tree *root, int oldValue, int newValue) {
    root = avlDelete(root, oldValue);
    root = avlInsert(root, newValue);
    return root;
}

void delete_tree(Tree **t) {
    if (!t || !*t) return;

    Stack s;
    s_init(&s);
    Tree *curr = *t;

    while(!s_empty(&s) || curr != NULL) {
        while(curr != NULL) {
            s_push_p(&s, curr);
            curr = curr->left;
        }
        curr = s_pop_p(&s);
        Tree *right = curr->right;
        free(curr);
        curr = right;
    }
    *t = NULL;
    s_clear(&s);
}

#endif