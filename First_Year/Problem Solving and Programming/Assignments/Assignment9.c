#include <stdio.h>
#include <string.h>

void findLength(char *str) {
    int length = 0;
    char *temp = str;

    while (*temp != '\0') {
        length++;
        temp++;
    }
    printf("Length of string is - %d\n", length);
}

void copyString(char *src, char *dest) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int main() {
    int choice;
    char str[100], str2[100];

    do {
        printf("---------------------------------\n");
        printf("String manipulation through pointers\n");
        printf("---------------------------------\n");
        printf("1. Find length of string.\n");
        printf("2. Copy one string to another.\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice - ");
        scanf("%d", &choice);

        getchar();

        switch (choice) {
            case 1: {
                printf("Enter a string - ");
                gets(str);
                strlwr(str);
                findLength(&str);
                break;
            }

            case 2: {
                printf("Enter a string - ");
                gets(str);
                printf("Enter another string - ");
                gets(str2);

                strlwr(str);
                strlwr(str2);
                copyString(&str, &str2);

                printf("Original string is - %s\n", str);
                printf("Copied string is - %s\n", str2);
                break;
            }

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
