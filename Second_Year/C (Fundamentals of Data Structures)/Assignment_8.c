#include <stdio.h>
#include "8.Threaded_BT.h"

int main() {
    ThTree *t;
    Stack s;
    Queue q;
    
    s_init(&s);
    q_init(&q);
    TBT_init(&t);

    while(1) {
        printf("\nThreaded Binary Search Tree maker - \n");
        printf("-----------------------------\n");
        printf("1. Add to Tree\n");
        printf("2. Traverse Tree\n");
        printf("3. Update Tree\n");
        printf("4. Remove from Tree\n");
        printf("5. Delete Tree\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");

        int choice;

        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
            printf("Invalid input. Please enter an integer between 1 and 6.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
        case 1:
            {int push_val;
            printf("Enter value to Add: ");
            if(scanf("%d", &push_val) != 1) {
                printf("Invalid input. Please enter an integer value.\n");
                while(getchar() != '\n');
                break;
            }
            
            tree_add_TBT(&t, push_val);
            break;}
        case 2:
            {printf("-----------------------------\n");
            printf("1. Preorder\n");
            printf("2. Inorder\n");
            printf("3. Postorder\n");
            printf("4. Breadth First\n");
            printf("-----------------------------\n");
            int traversalChoice;
            
            printf("Enter traversal choice: ");
            scanf("%d", &traversalChoice);
            while (traversalChoice < 1 || traversalChoice > 4) {
                printf("Invalid choice. Please enter a number between 1 and 4: ");
                scanf("%d", &traversalChoice);
            }

            switch (traversalChoice) {
                case 1:
                    preorder_TBT(t);
                    break;
                case 2:
                    inorder_TBT(t);
                    break;
                case 3:
                    postorder_TBT(t);
                    break;
                case 4:
                    breadthfirst_TBT(t);
                    break;
                default:
                    printf("Invalid traversal choice.\n");
            }
            break;}
        case 3:
            {breadthfirst_TBT(t);
            printf("\nEnter value to update: ");
            int old_value, new_value;
            if(scanf("%d", &old_value) != 1) {
                printf("Invalid input. Please enter an integer.\n");
                while(getchar() != '\n');
                break;
            }
            printf("Enter new value: ");
            if(scanf("%d", &new_value) != 1) {
                printf("Invalid input. Please enter an integer value.\n");
                while(getchar() != '\n');
                break;
            }
            update_value_TBT(&t, old_value, new_value);
            break;}
        case 4:
            {breadthfirst_TBT(t);
            printf("\nEnter value to delete: ");
            int del_value;
            if(scanf("%d", &del_value) != 1) {
                printf("Invalid input. Please enter an integer value.\n");
                while(getchar() != '\n');
                break;
            }
            delete_value_TBT(&t, del_value);
            break;}
        case 5:
            delete_TBT(&t);
            printf("Tree deleted.\n");
            break;
        case 6:
            delete_TBT(&t);
            printf("Exiting program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}