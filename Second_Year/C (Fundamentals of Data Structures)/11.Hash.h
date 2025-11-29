#include <stdio.h>
#include <stdlib.h>

#ifndef HASH_H
#define HASH_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void hadd(int method, int arr[], int size) {
    int value;
    printf("Enter value to add: ");
    scanf("%d", &value);

    switch(method) {
        case 1: {
            Node **arr = (Node**)arr;
            int index = value % size;
            Node *newn = (Node *)malloc(sizeof(Node));
            newn->value = value;
            newn->next = arr[index];
            arr[index] = newn;
            printf("Added %d at index %d (Open Hashing)\n", value, index);
            break;
        }
        case 2: {
            int *arr = (int*)arr;
            int index = value % size;
            for(int i=0;i<size;i++) {
                int probe = (index+i)%size;
                if(arr[probe] == -1) {
                    arr[probe] = value;
                    printf("Added %d at index %d (Closed Hashing)\n", value, probe);
                    break;
                }
            }
            break;
        }
    }
}

void hread()
#endif