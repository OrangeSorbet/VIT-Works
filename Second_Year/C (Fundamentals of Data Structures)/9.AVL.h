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
    s_init_p(&s);

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

Tree* avlDelete(Tree *root, int value) {
    if (!root) return NULL;

    Stack s;
    s_init_p(&s);

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

void inorder(Tree *t) {
    if(!t) {
        printf("Tree does not exist\n");
        return;
    }

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