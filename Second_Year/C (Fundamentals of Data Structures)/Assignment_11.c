#include <stdio.h>
#include <stdlib.h>
#include "11.Hash.h"

int main() {
    int mainChoice;

    while(1) {
        printf("Hashing Menu:\n");
        printf("1. Open Hashing\n");
        printf("2. Closed Hashing\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        if(scanf("%d", &mainChoice) != 1 || mainChoice < 1 || mainChoice > 3) {
            printf("Invalid input. Please enter 1-3.\n");
            while(getchar() != '\n');
            continue;
        }

        if(mainChoice == 3) break;

        int size;
        printf("Enter table size: ");
        if(scanf("%d", &size) != 1 || size <= 0) {
            printf("Invalid size.\n");
            while(getchar() != '\n');
            continue;
        }

        void *table = NULL;
        if(mainChoice == 1) {
            Node **arr = calloc(size, sizeof(Node*));
            table = arr;
        } 
        else {
            int *arr = calloc(size, sizeof(int));
            for(int i=0;i<size;i++) arr[i] = -1;
            table = arr;
        }

        while(1) {
            int subChoice;
            printf("\nOperations Menu:\n");
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

            switch(subChoice) {
                case 1:
                    hadd(mainChoice, table, size);
                    break;
                case 2:
                    hread(size);
                    break;
                case 3:
                    hsearch();
                    break;
                case 4:
                    hupdate();
                    break;
                case 5:
                    hdelete_entry();
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
    }

    printf("Exiting program.\n");
}