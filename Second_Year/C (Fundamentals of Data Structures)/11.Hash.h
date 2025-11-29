#include <stdio.h>
#include <stdlib.h>

#ifndef HASH_H
#define HASH_H

void hadd(int table[], int size, int value) {
    int index = value % size;

    for(int i = 0; i < size; i++) {
        int probe = (index + i) % size;
        if(table[probe] == -1) {
            table[probe] = value;
            printf("Inserted at index %d\n", probe);
            return;
        }
    }
    printf("Hash table full, cannot insert.\n");
}

void hread(int table[], int size) {
    for(int i = 0; i < size; i++)
        printf("Index %d: %d\n", i, table[i]);
}

int hsearch(int table[], int size, int value) {
    int index = value % size;

    for(int i = 0; i < size; i++) {
        int probe = (index + i) % size;
        if(table[probe] == value) {
            printf("Found at index %d\n", probe);
            return probe;
        }
        if(table[probe] == -1) break;  
    }

    printf("Not found.\n");
    return -1;
}

void hupdate(int table[], int size, int oldValue, int newValue) {
    int idx = hsearch(table, size, oldValue);
    if(idx == -1) return;

    table[idx] = newValue;
    printf("Updated index %d -> %d\n", idx, newValue);
}

void hdelete_entry(int table[], int size, int value) {
    int idx = hsearch(table, size, value);
    if(idx == -1) return;

    table[idx] = -1; // Mark empty
    printf("Deleted at index %d\n", idx);
}

#endif