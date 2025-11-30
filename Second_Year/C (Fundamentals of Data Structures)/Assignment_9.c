#include <stdio.h>
#include<stdlib.h>
#include "9.AVL.h"

int main() {
    Tree *t;

    s_init(&s);
    q_init(&q);
    tree_init(&t);

    while(1) {
        printf("AVL maker - \n");
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
        scanf("%d", &choice);
        
        while (choice < 1 || choice > 6) {
            printf("Invalid choice. Please enter a number between 1 and 6: ");
            scanf("%d", &choice);
        }

        switch(choice) {
        case 1:
            {int push_val;
            printf("Enter value to Add: ");
            scanf("%d", &push_val);
            tree_add_avl(&t, push_val);
            printf("Value %d pushed to Tree.\n", push_val);
            break;}
        case 2:
            {printf("-----------------------------\n");
            printf("1. Preorder\n");
            printf("2. Inorder\n");
            printf("3. Postorder\n");
            printf("4. Breadth First\n");
            printf("5. Depth First\n");
            printf("-----------------------------\n");
            int traversalChoice;
            
            printf("Enter traversal choice: ");
            scanf("%d", &traversalChoice);
            while (traversalChoice < 1 || traversalChoice > 5) {
                printf("Invalid choice. Please enter a number between 1 and 5: ");
                scanf("%d", &traversalChoice);
            }

            switch (traversalChoice) {
                case 1:
                    tree_read_preorder(t);
                    break;
                case 2:
                    tree_read_inorder(t);
                    break;
                case 3:
                    tree_read_postorder(t);
                    break;
                case 4:
                    tree_read_breadthfirst(t);
                    break;
                case 5:
                    tree_read_depthfirst(t);
                    break;
                default:
                    printf("Invalid traversal choice.\n");
            }
            break;}
        case 3:
        {
            printf("Enter value to update: ");
            int oldValue, newValue;

            if(scanf("%d", &oldValue) != 1) {
                printf("Invalid old value.\n");
                while(getchar() != '\n');
                break;
            }

            printf("Enter new value: ");
            if(scanf("%d", &newValue) != 1) {
                printf("Invalid new value.\n");
                while(getchar() != '\n');
                break;
            }

            tree_update_avl(t, oldValue, newValue);
            break;
        }
        case 4:
        {
            tree_read_breadthfirst(t);
            printf("Enter value to delete: ");
            int del_value;
            if (scanf("%d", &del_value) != 1) {
                printf("Invalid input. Please enter an integer value.\n");
                while (getchar() != '\n');
                break;
            }

            t = tree_delete_avl(t, del_value);
            printf("%d deleted.\n", del_value);
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
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
}