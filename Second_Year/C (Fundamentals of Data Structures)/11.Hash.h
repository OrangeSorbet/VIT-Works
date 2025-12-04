#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

void h_init(int **table, int *size) {
    *size = 4;
    *table = (int *)malloc((*size) * sizeof(int));
    for (int i = 0; i < *size; i++)
        (*table)[i] = -1;
}

int h_read(int table[], int size) {
    if (!table) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (table[i] == -1) printf("[ - ]");
        else printf("[%d]", table[i]);
    }
    printf("\n");
}

int h_search(int table[], int size, int value) {
    if (!table) return -1;

    int index = value % size;

    for (int i = 0; i < size; i++) {
        int probe = (index + i) % size;

        if (table[probe] == value) {
            printf("%d found at index %d!\n", value, probe);
            return 1;
        }
    }
    return 0;
}

void h_rehash(int **table, int *size) {
    int old_size = *size;
    int new_size = old_size * 2;

    int *old_table = *table;
    int *new_table = (int *)malloc(new_size * sizeof(int));

    for (int i = 0; i < new_size; i++)
        new_table[i] = -1;

    for (int i = 0; i < old_size; i++) {
        if (old_table[i] != -1) {
            int value = old_table[i];
            int index = value % new_size;

            for (int j = 0; j < new_size; j++) {
                int probe = (index + j) % new_size;
                if (new_table[probe] == -1) {
                    new_table[probe] = value;
                    break;
                }
            }
        }
    }

    free(old_table);
    *table = new_table;
    *size = new_size;
}

int h_add(int **table, int *size, int value) {
    int index = value % *size;

    for (int i = 0; i < *size; i++) {
        int probe = (index + i) % *size;

        if ((*table)[probe] == -1) {
            (*table)[probe] = value;
            printf("%d added at index %d\n", value, probe);
            return 1;
        }
    }

    h_rehash(table, size);

    return h_add(table, size, value);
}

int h_delete(int **table, int *size, int value) {
    if (!*table) return -1;

    int index = value % *size;

    for (int i = 0; i < *size; i++) {
        int probe = (index + i) % *size;

        if ((*table)[probe] == value) {
            (*table)[probe] = -1;
            printf("%d deleted from index %d\n", value, probe);

            int empty = 1;
            for (int j = 0; j < *size; j++) {
                if ((*table)[j] != -1) {
                    empty = 0;
                    break;
                }
            }

            if (empty) {
                free(*table);
                *table = NULL;
                *size = 0;
                printf("Table deleted (all empty)\n");
                return 2;
            }

            return 1;
        }
    }
    return 0;
}

int h_update(int **table, int *size, int oldValue, int newValue) {
    if (!*table) return -1;

    int d = h_delete(table, size, oldValue);
    if (d != 1) return d;

    return h_add(table, size, newValue);
}

int h_empty(int **table, int *size) {
    if (!*table) return 1;
    for (int i = 0; i < *size; i++)
        if (*table[i] != -1) return 0;
    return 1;
}

#endif