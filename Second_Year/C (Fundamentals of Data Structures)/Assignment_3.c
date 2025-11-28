#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Student {
    unsigned int roll;
    char name[50];
    char email[50];
    char phone[15];
    struct Student *next;
};

int main() {
    struct Student *head = NULL;
    int choice;

    while (1) {
        printf("\n===== Student Record Menu =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            struct Student *s = (struct Student *)calloc(1, sizeof(struct Student));
            s->next = NULL;

            char rollInput[20];
            int valid = 0, len;

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

                s->roll = atoi(rollInput);
                if (s->roll <= 0) valid = 0;

                struct Student *temp = head;
                while (temp != NULL) {
                    if (temp->roll == s->roll) {
                        valid = 0;
                        break;
                    }
                    temp = temp->next;
                }

                if (!valid) printf("Invalid or duplicate roll number.\n");
            }

            valid = 0;
            while (!valid) {
                valid = 1;
                printf("Enter full name (first middle last, English letters only): ");
                scanf(" %[^\n]", s->name);

                int spaceCount = 0;
                for (int i = 0; s->name[i]; i++) {
                    if (s->name[i] == ' ') spaceCount++;
                    else if (!isalpha(s->name[i])) {
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
                scanf(" %[^\n]", s->email);

                struct Student *temp = head;
                while (temp != NULL) {
                    if (strcmp(temp->email, s->email) == 0) {
                        valid = 0;
                        break;
                    }
                    temp = temp->next;
                }

                char expected[50];
                int i = 0, j = 0;
                int firstLen = 0, lastLen = 0;

                while (s->name[i] != ' ' && s->name[i] != '\0') {
                    expected[j++] = tolower(s->name[i++]);
                    firstLen++;
                }

                expected[j++] = '.';

                i++;
                while (s->name[i] != ' ' && s->name[i] != '\0') {
                    i++;
                }

                i++;
                while (s->name[i] != '\0') {
                    expected[j++] = tolower(s->name[i++]);
                    lastLen++;
                }

                expected[j] = '\0';

                int requiredMinLen = firstLen + 1 + lastLen + 2 + 8;
                int actualLen = strlen(s->email);

                if (actualLen < requiredMinLen) valid = 0;

                if (valid) {
                    for (i = 0; i < strlen(expected); i++) {
                        if (tolower(s->email[i]) != expected[i]) {
                            valid = 0;
                            break;
                        }
                    }
                }

                if (valid) {
                    char digits[10];
                    int d = 0;
                    i = strlen(expected);
                    while (isdigit(s->email[i])) {
                        digits[d++] = s->email[i++];
                    }
                    digits[d] = '\0';

                    if (d < 2 || d > 3) valid = 0;

                    if (strcmp(&s->email[i], "@vit.edu") != 0) {
                        valid = 0;
                    }
                }

                if (valid) {
                    int atCount = 0;
                    for (i = 0; s->email[i]; i++) {
                        if (s->email[i] == '@') atCount++;
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
                scanf(" %[^\n]", s->phone);

                if (strlen(s->phone) != 14 || s->phone[0] != '+' || s->phone[3] != ' ') valid = 0;
                else if (!isdigit(s->phone[1]) || !isdigit(s->phone[2])) valid = 0;
                else {
                    for (int i = 4; i < 14; i++) {
                        if (!isdigit(s->phone[i])) {
                            valid = 0;
                            break;
                        }
                    }
                }

                struct Student *temp = head;
                while (temp != NULL) {
                    if (strcmp(temp->phone, s->phone) == 0) {
                        valid = 0;
                        break;
                    }
                    temp = temp->next;
                }

                if (!valid) printf("Invalid or duplicate phone number.\n");
            }

            if (head == NULL) {
                head = s;
            } else {
                struct Student *temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = s;
            }

            printf("Student added!\n");
        }

        else if (choice == 2) {
            if (head == NULL) {
                printf("No students yet.\n");
            } else {
                struct Student *temp = head;
                int count = 1;
                while (temp != NULL) {
                    printf("\n--- Student %d ---\n", count++);
                    printf("Roll: %u\n", temp->roll);
                    printf("Name: %s\n", temp->name);
                    printf("Email: %s\n", temp->email);
                    printf("Phone: %s\n", temp->phone);
                    temp = temp->next;
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

    struct Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}