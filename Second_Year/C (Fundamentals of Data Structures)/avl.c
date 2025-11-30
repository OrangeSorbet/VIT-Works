    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
        int height;
    };

    struct Node *root = NULL;

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int getHeight(struct Node *node)
    {
        if (node == NULL)
        {
            return -1;
        }
        return node->height;
    }

    int getBalance(struct Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void clear_input()
    {
        int c;
        while ((c = getchar()) != '\n');
    }

    int valid(char input[]){
        for (int i = 0; i < strlen(input); i++)
            {
                if (!isdigit(input[i]))
                {
                    return 0;
                }
            }
        return 1;
    }

    struct Node *createNode(int data)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->data = data;
        new->right = NULL;
        new->left = NULL;
        new->height = 0;
        return new;
    }

    struct Node *Stack[20];
    int top = -1;

    void push(struct Node *newNode)
    {
        Stack[++top] = newNode;
    };

    struct Node *pop()
    {
        return Stack[top--];
    }

    struct Node *Stack2[20];
    int top2 = -1;

    void push2(struct Node *newNode)
    {
        Stack2[++top2] = newNode;
    }

    struct Node *pop2()
    {
         return Stack2[top2--];
    }

    // Rotation

    struct Node *rightRotate(struct Node *y)
    {
        struct Node *x = y->left;
        struct Node *xr = x->right;

        x->right = y;
        y->left = xr;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    struct Node *leftRotate(struct Node *y)
    {
        struct Node *x = y->right;
        struct Node *xl = x->left;

        x->left = y;
        y->right = xl;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    void insertNode(int data)
    {

        struct Node *newNode = createNode(data);
        struct Node *current = root;
        struct Node *parent = current;

        if (root == NULL)
        {
            root = newNode;
            root->height = 0;
            return;
        }

        while (current != NULL)
        {
            push(current);
            parent = current;
            if (data < current->data)
            {
                current = current->left;
            }
            else if (data > current->data)
            {
                current = current->right;
            }
            else
            {
                free(newNode);
                return;
            }
        }

        if (data > parent->data)
        {
            parent->right = newNode;
        }
        else if (data < parent->data)
        {
            parent->left = newNode;
        }

        while (top != -1)
        {
            struct Node *node = pop();
            struct Node *newSubtreeRoot = NULL;

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            int balance = getBalance(node);

            // LL
            if (balance > 1 && newNode->data < node->left->data)
            {
                newSubtreeRoot = rightRotate(node);
            }
            // LR
            else if (balance > 1 && newNode->data > node->left->data)
            {
                node->left = leftRotate(node->left);
                newSubtreeRoot = rightRotate(node);
            }
            // RR
            else if (balance < -1 && newNode->data > node->right->data)
            {
                newSubtreeRoot = leftRotate(node);
            }
            // RL
            else if (balance < -1 && newNode->data < node->right->data)
            {
                node->right = rightRotate(node->right);
                newSubtreeRoot = leftRotate(node);
            }

            if (newSubtreeRoot != NULL)
            {
                if (top == -1)
                {
                    root = newSubtreeRoot;
                }
                else
                {
                    struct Node *parentOfNode = Stack[top];
                    if (parentOfNode->left == node)
                    {
                        parentOfNode->left = newSubtreeRoot;
                    }
                    else
                    {
                        parentOfNode->right = newSubtreeRoot;
                    }
                }
            }
        }
    }

    void preOrder(struct Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }

    void manualPreOrder(struct Node *root)
    {

        if (root == NULL)
        {
            printf("Tree is Empty!..");
            return;
        }

        push(root);
        while (top != -1)
        {
            struct Node *check = pop();

            printf("%d ", check->data);

            if (check->right != NULL)
            {
                push(check->right);
            }

            if (check->left != NULL)
            {
                push(check->left);
            }
        }
    }

    void manualInOrder(struct Node *root)
    {
        if (root == NULL)
        {
            printf("Tree is Empty!..");
            return;
        }

        struct Node *check = root;
        while (top != -1 || check != NULL)
        {
            while (check != NULL)
            {
                push(check);
                check = check->left;
            }

            check = pop();
            printf("%d ", check->data);
            check = check->right;
        }
    }

    void manualPostOrder(struct Node *root)
    {

        if (root == NULL)
        {
            printf("Tree is Empty!..");
            return;
        }

        push(root);

        while (top != -1)
        {
            struct Node *check = pop();
            push2(check);

            if (check->left != NULL)
            {
                push(check->left);
            }
            if (check->right != NULL)
            {
                push(check->right);
            }
        }

        while (top2 != -1)
        {
            struct Node *printNode = pop2();
            printf("%d ", printNode->data);
        }
    }

struct Node* deleteNode(struct Node *root, int value) {

    if (root == NULL) {
        printf("Tree is Empty!..\n");
        return root;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    top = -1;
    while (current != NULL && current->data != value) {
        push(current);
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Value Not Found!..\n");
        return root;
    }

    if (current->left == NULL || current->right == NULL) {
        struct Node* child = (current->left != NULL) ? current->left : current->right;

        if (parent == NULL) {
            free(current);
            return child;
        }

        if (parent->left == current) {
            parent->left = child;
        } else {
            parent->right = child;
        }

        free(current);
    } 
    else {
        push(current);
        struct Node* rightSub = current->right;
        struct Node* rightSubParent = current;

        while (rightSub->left != NULL) {
            rightSubParent = rightSub;
            push(rightSub);
            rightSub = rightSub->left;
        }

        current->data = rightSub->data;

        if (rightSubParent->left == rightSub)
            rightSubParent->left = rightSub->right;
        else
            rightSubParent->right = rightSub->right;

        free(rightSub);
    }


    while (top != -1) {
        struct Node* node = pop();

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // LL
        if (balance > 1 && getBalance(node->left) >= 0)
            node = rightRotate(node);

        // LR
        else if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }

        // RR
        else if (balance < -1 && getBalance(node->right) <= 0)
            node = leftRotate(node);

        // RL
        else if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }

        if (top == -1) root = node;
    }

    printf("The value %d Deleted Successfully!..\n", value);
    return root;
}

struct Node* updateNode(struct Node* root, int oldValue, int newValue) {  
    printf("Updating %d to %d...\n", oldValue, newValue);

    root = deleteNode(root, oldValue);

    insertNode(newValue);

    printf("Updated Successfully! \n");
    return root;
}


    int main()
    {
        int choice, value,updated;
        char input[10];

        while (1)
        {
            printf("\n--- Tree Menu ---\n");
            printf("1. Insert Node\n");
            printf("2. Update Node\n");
            printf("3. PreOrder Traverse\n");
            printf("4. PostOrder Traverse\n");
            printf("5. InOrder Traverse\n");
            printf("6. Delete Node\n");
            printf("7. Exit\n");

            printf("Enter your choice: ");
            scanf("%s", &input);
            

            if (!valid(input))
            {   
                printf("Invalid input! \n");
                clear_input();
                continue;
            }

            choice = atoi(input);

            switch (choice)
            {
            case 1:
                printf("Enter value to Insert: ");
                scanf("%s", &input);
                if (!valid(input)){
                    printf("Invalid input! \n");
                    clear_input();
                    continue;
                }
                value = atoi(input);
                insertNode(value);
                break;
            case 2:
                printf("Enter value to Update: ");
                scanf("%s", &input);
                if (!valid(input)){
                    printf("Invalid input! \n");
                    clear_input();
                    continue;
                }
                value = atoi(input);
                printf("Enter the updated value: ");
                scanf("%s", &input);
                if (!valid(input)){
                    printf("Invalid input! \n");
                    clear_input();
                    continue;
                }
                updated = atoi(input);
                updateNode(root,value,updated);
                break;
            case 3:
                manualPreOrder(root);
                break;
            case 4:
                manualPostOrder(root);
                break;
            case 5:
                manualInOrder(root);
                break;
            case 6:
                printf("Enter value to Delete: ");
                scanf("%s", &input);
                if (!valid(input)){
                    printf("Invalid input! \n");
                    clear_input();
                    continue;
                }
                value = atoi(input);
                root = deleteNode(root,value);
                break;
            case 7:
                printf("Exiting program. :) \n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
            }
        }


        return 0;
    }
