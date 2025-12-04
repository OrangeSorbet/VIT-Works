#include <stdio.h>
#include <stdlib.h>
#include "11.Hash.h"

int main() {

    int *table = NULL;
    int size = 0;

    while (1) {

        int subChoice;

        printf("\n-----------------------------\n");
        printf("           Hash Map          \n");
        printf("-----------------------------\n");
        printf("1. Add\n");
        printf("2. Read\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("6. Exit to main menu\n");
        printf("-----------------------------\n");

        printf("Enter choice: ");

        if (scanf("%d", &subChoice) != 1 || subChoice < 1 || subChoice > 6) {
            printf("Invalid input. Please enter 1–6.\n");
            while (getchar() != '\n');
            continue;
        }

        if (subChoice == 6)
            break;

        int value, oldValue, newValue;

        switch (subChoice) {

            case 1:
                printf("Enter value to add: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    break;
                }
                h_init(&table, &size);
                h_add(&table, &size, value);
                break;

            case 2:
                if(h_read(table, size) == -1) {
                    printf("Table is empty!\n");
                }
                break;

            case 3:
                {
                    int searsucc = h_search(table, size, value);
                    if (searsucc == -1) printf("Table is empty!\n");
                    else if (searsucc == 0) printf("%d Not found!\n", value);
                    break;
                }
            case 4:
                if(h_read(table, size) == -1) {
                    printf("Table is empty!\n");
                    break;
                }

                printf("Enter existing value: ");
                if (scanf("%d", &oldValue) != 1) {
                    printf("Invalid input!\n");
                    while(getchar()!='\n');
                    break;
                }

                printf("Enter new value: ");
                if (scanf("%d", &newValue) != 1) {
                    printf("Invalid input!\n");
                    while(getchar()!='\n');
                    break;
                }
                int updsucc = h_update(&table, &size, oldValue, newValue);
                if (updsucc == 1) printf("Updated.\n");
                else if (updsucc == 0) printf("Not found.\n");
                break;

            case 5:
                if(h_read(table, size) == -1) {
                    printf("Table is empty!\n");
                    break;
                }

                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    while(getchar()!='\n');
                    break;
                }
                int delsucc = h_delete(table, size, value);
                if (delsucc == 1) printf("Deleted.\n");
                else if (delsucc == 0) printf("Not found.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                free(table);
                return 0;
        }
    }
    printf("Exiting program.\n");
    free(table);
    return 0;
}