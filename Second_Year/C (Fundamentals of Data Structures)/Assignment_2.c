#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Student {
    unsigned int roll;
    char name[50];
    char email[50];
    char phone[15];
};

int main() {
    struct Student students[10];
    int total = 0, choice;

    while (1) {
        printf("\n===== Student Record Menu =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (total >= 10) {
                printf("List is full!\n");
                continue;
            }

            struct Student s;
            char rollInput[20];
            int valid = 0;
            int len;

            while (!valid) {
                valid = 1;
                printf("Enter roll number (max 8 digits): ");
                scanf("%s", rollInput);
                len = strlen(rollInput);

                if (len == 0 || len > 8) valid = 0;
                for (int i = 0; i < len; i++) {
                    if (!isdigit(rollInput[i])) {
                        valid = 0;
                        break;
                    }
                }

                s.roll = atoi(rollInput);
                if (s.roll <= 0) valid = 0;

                for (int i = 0; i < total; i++) {
                    if (students[i].roll == s.roll) {
                        valid = 0;
                        break;
                    }
                }

                if (!valid) printf("Invalid or duplicate roll number.\n");
            }

            valid = 0;
            while (!valid) {
                valid = 1;
                printf("Enter full name (first middle last, English letters only): ");
                scanf(" %[^\n]", s.name);

                int spaceCount = 0;
                for (int i = 0; s.name[i]; i++) {
                    if (s.name[i] == ' ') spaceCount++;
                    else if (!isalpha(s.name[i])) {
                        valid = 0;
                        break;
                    }
                }

                if (spaceCount != 2) valid = 0;
                if (!valid) printf("Invalid name format.\n");
            }

            valid = 0;
            while (!valid) {
                valid = 1;
                printf("Enter email: ");
                scanf(" %[^\n]", s.email);

                // duplicate email
                for (int i = 0; i < total; i++) {
                    if (strcmp(students[i].email, s.email) == 0) {
                        valid = 0;
                        break;
                    }
                }

                // firstname.lastname
                char expected[50];
                int i = 0, j = 0;
                int firstLen = 0, lastLen = 0;

                // Add first name
                while (s.name[i] != ' ' && s.name[i] != '\0') {
                    expected[j++] = tolower(s.name[i++]);
                    firstLen++;
                }

                expected[j++] = '.';

                // Skip middle name
                i++;
                while (s.name[i] != ' ' && s.name[i] != '\0') {
                    i++;
                }

                // Add last name
                i++;
                while (s.name[i] != '\0') {
                    expected[j++] = tolower(s.name[i++]);
                    lastLen++;
                }

                expected[j] = '\0';

                // minimum length
                int requiredMinLen = firstLen + 1 + lastLen + 2 + 8;
                int actualLen = strlen(s.email);

                if (actualLen < requiredMinLen) {
                    valid = 0;
                }

                // expected == email (without domain) entered?
                if (valid) {
                    for (i = 0; i < strlen(expected); i++) {
                        if (tolower(s.email[i]) != expected[i]) {
                            valid = 0;
                            break;
                        }
                    }
                }

                // digits between name and "@vit.edu"
                if (valid) {
                    char digits[10];
                    int d = 0;
                    i = strlen(expected);
                    while (isdigit(s.email[i])) {
                        digits[d++] = s.email[i++];
                    }
                    digits[d] = '\0';

                    if (d < 2 || d > 3) valid = 0;

                    // "@vit.edu"
                    if (strcmp(&s.email[i], "@vit.edu") != 0) {
                        valid = 0;
                    }
                }

                // '@' exactly once
                if (valid) {
                    int atCount = 0;
                    for (i = 0; s.email[i]; i++) {
                        if (s.email[i] == '@') atCount++;
                    }
                    if (atCount != 1) valid = 0;
                }

                if (!valid) {
                    printf("Invalid email format. Expected: firstname.lastname[2-3 digits]@vit.edu\n");
                }
            }

            valid = 0;
            while (!valid) {
                valid = 1;
                printf("Enter phone (+CC XXXXXXXXXX): ");
                scanf(" %[^\n]", s.phone);

                if (strlen(s.phone) != 14 || s.phone[0] != '+' || s.phone[3] != ' ') valid = 0;
                else if (!isdigit(s.phone[1]) || !isdigit(s.phone[2])) valid = 0;
                else {
                    for (int i = 4; i < 14; i++) {
                        if (!isdigit(s.phone[i])) {
                            valid = 0;
                            break;
                        }
                    }
                }

                for (int i = 0; i < total; i++) {
                    if (strcmp(students[i].phone, s.phone) == 0) {
                        valid = 0;
                        break;
                    }
                }

                if (!valid) printf("Invalid or duplicate phone number.\n");
            }

            students[total++] = s;
            printf("Student added!\n");
        }

        else if (choice == 2) {
            if (total == 0) {
                printf("No students yet.\n");
            } else {
                for (int i = 0; i < total; i++) {
                    printf("\n--- Student %d ---\n", i + 1);
                    printf("Roll: %u\n", students[i].roll);
                    printf("Name: %s\n", students[i].name);
                    printf("Email: %s\n", students[i].email);
                    printf("Phone: %s\n", students[i].phone);
                }
            }
        }

        else if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice. Try again.\n");
        }
    }
}