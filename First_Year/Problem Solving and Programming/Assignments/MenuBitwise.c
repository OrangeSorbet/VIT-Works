#include <stdio.h>

int main() {
    int choice, a, b, con;
do {
    printf("----------------------------------\n");
    printf("Welcome to the Bitwise Calculator!\n");
    printf("----------------------------------\n");
    printf("Choose which operation you want.\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise Right Shift\n");
    printf("4. Bitwise Left Shift\n");
    printf("5. Exit\n");
    printf("Enter Your Choice - ");
    scanf("%d", &choice);
    printf("----------------------------------\n");
    //numbers
    /*
    printf("Enter the first number - ");
    scanf("%d", &a);
    printf("Enter the second number - ");
    scanf("%d", &b);
    printf("----------------------------------\n");
    */

    //switch case
    switch (choice)
    {
    case 1:
        printf("Enter the first number - ");
        scanf("%d", &a);
        printf("Enter the second number - ");
        scanf("%d", &b);
        printf("----------------------------------\n");
        printf("The bitwise AND of %d and %d is %d\n", a, b, a&b);
        printf("----------------------------------\n");
        //continue choice
        printf("Do you want to continue? Press 1 for yes, 2 for no - ");
        scanf("%d", &con);
        if (con==1)
            continue;
        else
            goto case5;
        break;
    case 2:
        printf("Enter the first number - ");
        scanf("%d", &a);
        printf("Enter the second number - ");
        scanf("%d", &b);
        printf("----------------------------------\n");
        printf("The bitwise OR of %d and %d is %d\n", a, b, a|b);
        printf("----------------------------------\n");
        //continue choice
        printf("Do you want to continue? Press 1 for yes, 2 for no - ");
        scanf("%d", &con);
        if (con==1)
            continue;
        else
            goto case5;
        break;
    case 3:
        printf("Enter a number - ");
        scanf("%d", &a);
        printf("Enter the number of bits you want to shift right - ");
        scanf("%d", &b);
        printf("----------------------------------\n");
        printf("The bitwise right shift of %d and %d is %d\n", a, b, a>>b);
        printf("----------------------------------\n");
        //continue choice
        printf("Do you want to continue? Press 1 for yes, 2 for no - ");
        scanf("%d", &con);
        if (con==1)
            continue;
        else
            goto case5;
        break;
    case 4:
        printf("Enter a number - ");
        scanf("%d", &a);
        printf("Enter the number of bits you want to shift left- ");
        scanf("%d", &b);
        printf("----------------------------------\n");
        printf("The bitwise left shift of %d and %d is %d\n", a, b, a<<b);
        printf("----------------------------------\n");
        //continue choice
        printf("Do you want to continue? Press 1 for yes, 2 for no - ");
        scanf("%d", &con);
        if (con==1)
            continue;
        else
            goto case5;
        break;
    case 5:
        case5:
        exit(0);
        break;
    }
}
while (choice!=5);
getch();
}

