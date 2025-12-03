#include <stdio.h>
#include <stdlib.h>
#include "9.AVL.h"
#include "5.stack_queue_func.h"

int main() {
    Tree *t = NULL;

    while(1) {
        printf("\nAVL Tree Menu\n");
        printf("-----------------------------\n");
        printf("1. Add Node\n");
        printf("2. Traverse Tree\n");
        printf("3. Update Node\n");
        printf("4. Delete Node\n");
        printf("5. Delete Entire Tree\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");

        int choice;
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
        case 1: {
            int value;
            printf("Enter value to add: ");
            if(scanf("%d", &value) != 1) {
                printf("Invalid input. Enter an integer.\n");
                while(getchar() != '\n');
                break;
            }
            t = avlInsert(t, value);
            printf("Value %d added.\n", value);
            break;
        }
        case 2: {
            printf("\nTraversal Options:\n");
            printf("1. Preorder\n2. Inorder\n3. Postorder\n4. Breadth-First\n");
            int travChoice;
            printf("Enter traversal choice: ");
            if(scanf("%d", &travChoice) != 1) {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                break;
            }
            switch(travChoice) {
                case 1: preorder_AVL(t); break;
                case 2: inorder_AVL(t); break;
                case 3: postorder_AVL(t); break;
                case 4: breadthfirst_AVL(t); break;
                default: printf("Invalid traversal choice.\n");
            }
            printf("\n");
            break;
        }
        case 3: {
            printf("Current tree (BFS): ");
            breadthfirst_AVL(t);

            int oldValue, newValue;
            printf("Enter value to update: ");
            if(scanf("%d", &oldValue) != 1) {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                break;
            }
            printf("Enter new value: ");
            if(scanf("%d", &newValue) != 1) {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                break;
            }
            t = avlUpdate(t, oldValue, newValue);
            printf("Updated %d to %d.\n", oldValue, newValue);
            break;
        }
        case 4: {
            printf("Current tree (BFS): ");
            breadthfirst_AVL(t);

            int delValue;
            printf("Enter value to delete: ");
            if(scanf("%d", &delValue) != 1) {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                break;
            }
            t = avlDelete(t, delValue);
            printf("Deleted %d.\n", delValue);
            break;
        }
        case 5:
            delete_tree(&t);
            printf("Tree deleted.\n");
            break;
        case 6:
            delete_tree(&t);
            printf("Exiting program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}