#include <stdio.h>
#include <conio.h>
#include <string.h>

char str1[20], str2[20];
int choice, i=0, j=0, count=0;

int main() {
    //do this entire thing till exit is pressed
    do
    {
    //Menu
    printf("Welcome to the ULTIMATE STRING MANIPULATOR!!\n");
    printf("----------------------------------------------\n");
    printf("1. Get length of string.\n");
    printf("2. Print string in reverse order.\n");
    printf("3. Copy given string into other string.\n");
    printf("4. Compare two strings.\n");
    printf("5. Concatenate strings.\n");
    printf("6. Exit\n");
    printf("Enter your choice - ");
    scanf("%d", &choice);
    printf("----------------------------------------------\n");

    //Switch case
    switch (choice)
    {
    case 1: //length
        printf("Enter a string - ");
        scanf("%s", str1);
        //logic
        while (str1[i] != '\0')
        {
            count++;
            i++;
        }
        printf("Length of string is %d\n", count);
        printf("----------------------------------------------\n");
        break;

    case 2: //reverse string
        printf("Enter a string - ");
        scanf("%s", &str1);
        //logic
        i = 0;
        while (str1[i] != '\0') {
            i++;  // Find the length of str1
        }
        i--;  // Move to the last character of str1

        j = 0;
        while (i >= 0)
        {
            str2[j++] = str1[i--];  // Copy characters in reverse order
        }
        str2[j] = '\0';

        printf("Original string is %s\n", str1);
        printf("Reversed string is %s\n", str2);
        printf("----------------------------------------------\n");
        break;

    case 3: //copy strings
        printf("Enter a string - ");
        scanf("%s", &str1);
        printf("Enter another string - ");
        scanf("%s", &str2);
        //logic
        i = 0;
        while (str1[i] != '\0')
        {
            str2[i]=str1[i];
            i++;
        }
        printf("Original string is %s\n", str1);
        printf("Copied string is %s\n", str2);
        printf("----------------------------------------------\n");
        break;

    case 4: //compare strings
        printf("Enter a string - ");
        scanf("%s", &str1);
        printf("Enter another string - ");
        scanf("%s", &str2);
        //logic
        // Compare the strings character by character
        while (str1[i] && str1[i] == str2[i])
        {
            i++;
        }

        // Determine the result
        if (str1[i] == str2[i])
        {
            printf("The two strings are equal\n");
        }
        else if (str1[i] < str2[i])
        {
            printf("String 1 is lexicographically lesser than String 2\n");
        }
        else
        {
            printf("String 1 is lexicographically greater than String 2\n");
        }
        printf("----------------------------------------------\n");
        break;

    case 5: //concatenate string
        printf("Enter a string - ");
        scanf("%s", &str1);
        printf("Enter another string - ");
        scanf("%s", &str2);
        //logic
        while(str1[i]!='\0')
            i++;
        //copy to str2
        while(str2[j]!='\0')
        {
            str1[i]=str2[j];
            i++;
            j++;
        }
        str1[i]='\0';
        printf("Concatenated String is %s\n", str1);
        printf("----------------------------------------------\n");
        break;

    case 6: //exit
        exit(0);
        break;
    } //switch end
    } //do end
    while (choice != 7);
    getch();
}
