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

int check_duplicates(Tree *t, int value) {
    Tree *curr = t;
    while (curr) {
        if (value < curr->value) curr = curr->left;
        else if (value > curr->value) curr = curr->right;
        else return 1;
    }
    return 0;
}

Tree* rightRotate(Tree *y) {
    Tree *x = y->left;
    Tree *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxf(height(y->left), height(y->right));
    x->height = 1 + maxf(height(x->left), height(x->right));

    return x;
}

Tree* leftRotate(Tree *y) {
    Tree *x = y->right;
    Tree *T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = 1 + maxf(height(y->left), height(y->right));
    x->height = 1 + maxf(height(x->left), height(x->right));

    return x;
}


int avlInsert(Tree **t, int value) {
    if (check_duplicates(*t, value)) {
        printf("Duplicate values not allowed!\n");
        return 0;
    }

    Stack s;
    s_init(&s);

    Tree *curr = *t;
    Tree *parent = NULL;

    while(curr != NULL) {
        s_push_p(&s, curr);
        parent = curr;

        if(value < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }

    Tree *newn = malloc(sizeof(Tree));
    newn->value = value;
    newn->left = newn->right = NULL;
    newn->height = 1;

    if (!*t) {
        *t = newn;
        return 1;
    }

    if(value < parent->value)
        parent->left = newn;
    else
        parent->right = newn;

    while(!s_empty(&s)) {
        Tree *temp = s_pop_p(&s);
        Tree *orig = temp;

        temp->height = 1 + maxf(height(temp->left), height(temp->right));
        int balance = getBalance(temp);

        if(balance > 1 && value < temp->left->value)
            temp = rightRotate(temp);

        else if(balance < -1 && value > temp->right->value)
            temp = leftRotate(temp);

        else if(balance > 1 && value > temp->left->value) {
            temp->left = leftRotate(temp->left);
            temp = rightRotate(temp);
        }

        else if(balance < -1 && value < temp->right->value) {
            temp->right = rightRotate(temp->right);
            temp = leftRotate(temp);
        }

        if (s_empty(&s)) {
            *t = temp;
        } else {
            Tree *p = s_top_p(&s);
            if (p == NULL) { *t = temp; }
            else if (p->left == orig) p->left = temp;
            else p->right = temp;
        }
    }
    return 1;
}

int preorder_AVL(Tree *t) {
    if(!t) {
        printf("Tree is empty.\n");
        return 0;
    }

    Stack s;
    s_init(&s);
    s_push_p(&s, t);

    while(!s_empty(&s)) {
        Tree *curr = s_pop_p(&s);
        printf("%d ", curr->value);
        if(curr->right) s_push_p(&s, curr->right);
        if(curr->left) s_push_p(&s, curr->left);
    }
    return 1;
}

int inorder_AVL(Tree *t) {
    if(!t) {
        printf("Tree is empty.\n");
        return 0;
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
    return 1;
}

int postorder_AVL(Tree *t) {
    if(!t) {
        printf("Tree is empty.\n");
        return 0;
    }

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
    return 1;
}

int breadthfirst_AVL(Tree *t) {
    if(!t) {
        printf("Tree is empty.\n");
        return 0;
    }

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
    return 1;
}

int avlDelete(Tree **t, int value) {
    if (!*t)  {
        return 0;
    }

    Stack s;
    s_init(&s);

    Tree *curr = *t;
    Tree *parent = NULL;
    Tree *toDelete = NULL;

    while (curr != NULL) {
        s_push_p(&s, curr);
        if (value < curr->value) {
            parent = curr;
            curr = curr->left;
        } else if (value > curr->value) {
            parent = curr;
            curr = curr->right;
        } else {
            toDelete = curr;
            break;
        }
    }

    if (!toDelete) return 0;

    Tree *child = NULL;

    if (!toDelete->left || !toDelete->right) {
        child = toDelete->left ? toDelete->left : toDelete->right;

        s_pop_p(&s);
        Tree *curParent = s_empty(&s) ? NULL : s_top_p(&s);

        free(toDelete);

        if (!curParent) {
            *t = child;
        } else {
            if (curParent->left == toDelete) curParent->left = child;
            else curParent->right = child;
        }
    }

    else {
        Tree *succ = toDelete->right;
        Tree *succParent = toDelete;

        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        toDelete->value = succ->value;

        if (succParent->left == succ) succParent->left = succ->right;
        else succParent->right = succ->right;

        if (!s_empty(&s)) s_pop_p(&s);

        free(succ);
    }

    while (!s_empty(&s)) {
        Tree *temp = s_pop_p(&s);
        Tree *orig = temp;

        temp->height = 1 + maxf(height(temp->left), height(temp->right));
        int balance = getBalance(temp);

        // LL
        if (balance > 1 && getBalance(temp->left) >= 0)
            temp = rightRotate(temp);

        // LR
        else if (balance > 1 && getBalance(temp->left) < 0) {
            temp->left = leftRotate(temp->left);
            temp = rightRotate(temp);
        }

        // RR
        else if (balance < -1 && getBalance(temp->right) <= 0)
            temp = leftRotate(temp);

        // RL
        else if (balance < -1 && getBalance(temp->right) > 0) {
            temp->right = rightRotate(temp->right);
            temp = leftRotate(temp);
        }

        if (s_empty(&s)) {
            *t = temp;
        } else {
            Tree *p = s_top_p(&s);
            if (p == NULL) { *t = temp; }
            else if (p->left == orig) p->left = temp;
            else p->right = temp;
        }
    }
    return 1;
}

void avlUpdate(Tree **t, int oldValue, int newValue) {

    if (oldValue == newValue) {
        printf("Duplicate value %d. Update aborted.\n", newValue);
        return;
    }

    if (check_duplicates(*t, newValue)) {
        printf("Duplicate value %d. Update aborted.\n", newValue);
        return;
    }

    if (!avlDelete(t, oldValue)) {
        printf("Value %d not found. Update aborted.\n", oldValue);
        return;
    }

    int updsucc = avlInsert(t, newValue);

    if (updsucc)
        printf("Value %d updated to %d.\n", oldValue, newValue);
}

int delete_tree(Tree **t) {
    if (!t || !*t) return 0;

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
    return 1;
}

#endif