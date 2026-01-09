#include <stdio.h>
#include "7.BST.h"

int main() {
    Tree *t;
    
    s_init(&s);
    q_init(&q);
    tree_init(&t);

    while(1) {
        printf("Binary Search Tree maker - \n");
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
            
            if(tree_add_BST(&t, push_val)) printf("Value %d pushed to Tree.\n", push_val);
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
                default:
                    printf("Invalid traversal choice.\n");
            }
            break;}
        case 3:
            {tree_read_breadthfirst(t);
            printf("Enter index to update: ");
            int index, new_value;
            int total_nodes = count_nodes(t);
            if(scanf("%d", &index) != 1 || index < 0 || index >= total_nodes) {
                printf("Invalid input. Please enter an integer index 0-%d.\n", total_nodes - 1);
                while(getchar() != '\n');
                break;
            }
            printf("Enter new value: ");
            if(scanf("%d", &new_value) != 1) {
                printf("Invalid input. Please enter an integer value.\n");
                while(getchar() != '\n');
                break;
            }
            update_value_BST(&t, index, new_value);
            printf("Value at index %d updated to %d.\n", index, new_value);
            break;}
        case 4:
            {tree_read_breadthfirst(t);
            printf("Enter value to delete: ");
            int del_value;
            if(scanf("%d", &del_value) != 1) {
                printf("Invalid input. Please enter an integer value.\n");
                while(getchar() != '\n');
                break;
            }
            t = delete_value_BST(t, del_value);
            break;}
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