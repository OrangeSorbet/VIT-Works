#include <stdio.h>
#include <stdlib.h>
#include "11.Hash.h"

int main() {

    int size = 10;
    int table[10];
    for(int i = 0; i < size; i++) table[i] = -1;  // -1 means empty

    while(1) {
        int subChoice;
        printf("\nHash Map:\n");
        printf("1. Add\n");
        printf("2. Read\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("6. Exit to main menu\n");
        printf("Enter choice: ");
        if(scanf("%d", &subChoice) != 1 || subChoice < 1 || subChoice > 6) {
            printf("Invalid input. Please enter 1-6.\n");
            while(getchar() != '\n');
            continue;
        }

        if(subChoice == 6) break;

        int value, oldValue, newValue;

        switch(subChoice) {

            case 1: // Add
                printf("Enter value to add: ");
                if(scanf("%d", &value) != 1) {
                    while(getchar()!='\n');
                    continue;
                }
                hadd(table, size, value);
                break;

            case 2: // Read
                hread(table, size);
                break;

            case 3: // Search
                printf("Enter value to search: ");
                if(scanf("%d", &value) != 1) {
                    while(getchar()!='\n');
                    continue;
                }
                hsearch(table, size, value);
                break;

            case 4: // Update
                printf("Enter existing value: ");
                if(scanf("%d", &oldValue) != 1) {
                    while(getchar()!='\n');
                    continue;
                }
                printf("Enter new value: ");
                if(scanf("%d", &newValue) != 1) {
                    while(getchar()!='\n');
                    continue;
                }
                hupdate(table, size, oldValue, newValue);
                break;

            case 5: // Delete
                printf("Enter value to delete: ");
                if(scanf("%d", &value) != 1) {
                    while(getchar()!='\n');
                    continue;
                }
                hdelete_entry(table, size, value);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    printf("Exiting program.\n");
}