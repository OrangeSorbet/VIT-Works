#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    char str1[20], str2[20];
    int choice, i, j;
    //do this entire thing till exit is pressed
    do
    {
    //Menu
    printf("Welcome to the ULTIMATE STRING MANIPULATOR!!\n");
    printf("----------------------------------------------\n");
    printf("1. Get length of string.\n");
    printf("2. Copy string to another.\n");
    printf("3. Compare the two strings.\n");
    printf("4. Concatenate two strings.\n");
    printf("5. Reverse the given string.\n");
    printf("6. Convert to lower case.\n");
    printf("7. Exit\n");
    printf("Enter your choice - ");
    scanf("%d", &choice);
    printf("----------------------------------------------\n");

    //Switch case
    switch (choice)
    {
    case 1: //length
        printf("Enter a string - ");
        scanf("%s", &str1);
        i=strlen(str1);
        printf("Length of string is %d\n", i);
        printf("----------------------------------------------\n");
        break;

    case 2: //copy string
        printf("Enter a string - ");
        scanf("%s", &str1);
        printf("Enter another string - ");
        scanf("%s", &str2);
        i=strcpy(str2, str1);
        printf("Original string is %s\n", str1);
        printf("Copied string is %s\n", str2);
        printf("----------------------------------------------\n");
        break;

    case 3: //compare strings
        printf("Enter a string - ");
        scanf("%s", &str1);
        printf("Enter another string - ");
        scanf("%s", &str2);
        j=strcmp(str1, str2);
        //ifelse for results
        if (j<0)
        {
            printf("The strings are not same.\n");
            printf("----------------------------------------------\n");
        }
        else
        {
            printf("The strings are same.\n");
            printf("----------------------------------------------\n");
        }
        break;

    case 4: //concatenate strings
        printf("Enter a string - ");
        scanf("%s", &str1);
        printf("Enter another string - ");
        scanf("%s", &str2);
        i=strcat(str1, str2);
        printf("Concatenated string is %s\n", str1);
        printf("----------------------------------------------\n");
        break;

    case 5: //reverse string
        printf("Enter a string - ");
        scanf("%s", &str1);
        i=strrev(str1);
        printf("Reversed string is - %s\n", str1);
        printf("----------------------------------------------\n");
        break;

    case 6: //convert to lower case
        printf("Enter a string - ");
        scanf("%s", &str1);
        i=strlwr(str1);
        printf("Lower case string is - %s\n", str1);
        printf("----------------------------------------------\n");
        break;

    case 7: //exit
        exit(0);
        break;
    } //switch end
    } //do end
    while (choice != 7);
    getch();
}
