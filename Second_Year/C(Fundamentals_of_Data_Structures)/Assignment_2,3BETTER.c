#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 10

struct Student {
    unsigned int roll;
    char name[50];
    char email[50];
    char phone[15];
};

void rebuildEmail(struct Student *s) {
    char expected[100];
    int i = 0, j = 0;

    // first name
    while (s->name[i] != ' ' && s->name[i] != '\0')
        expected[j++] = tolower(s->name[i++]);

    expected[j++] = '.';

    // skip middle
    while (s->name[i] != ' ' && s->name[i] != '\0')
        i++;
    i++;

    // last name
    while (s->name[i] != '\0')
        expected[j++] = tolower(s->name[i++]);

    expected[j] = '\0';

    // ask digits again
    char digits[4];
    while (1) {
        printf("Enter 2-3 digits for email: ");
        if (scanf("%3s", digits) != 1 ||
            strlen(digits) < 2 ||
            strlen(digits) > 3) {
            printf("Invalid. Try again.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    snprintf(s->email, sizeof(s->email), "%s%s@vit.edu", expected, digits);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int total = 0, choice;

    while (1) {
        printf("\n========= STUDENT MENU =========\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("================================\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        /* ================================
                ADD STUDENT
           ================================ */
        if (choice == 1) {
            if (total >= MAX_STUDENTS) {
                printf("List full.\n");
                continue;
            }

            struct Student s;
            int valid = 0;

            /* ROLL NUMBER */
            char rollInput[20];
            while (!valid) {
                printf("Enter roll (max 8 digits): ");
                if (scanf("%s", rollInput) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                int len = strlen(rollInput);
                valid = (len > 0 && len <= 8);
                for (int i = 0; i < len && valid; i++)
                    if (!isdigit(rollInput[i])) valid = 0;

                s.roll = atoi(rollInput);
                if (s.roll <= 0) valid = 0;

                for (int i = 0; i < total && valid; i++)
                    if (students[i].roll == s.roll) valid = 0;

                if (!valid) printf("Invalid or duplicate roll.\n");
            }

            /* NAME */
            valid = 0;
            while (!valid) {
                printf("Enter full name (first middle last): ");
                if (scanf(" %[^\n]", s.name) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                int spaces = 0;
                valid = 1;
                for (int i = 0; s.name[i]; i++) {
                    if (s.name[i] == ' ') spaces++;
                    else if (!isalpha(s.name[i])) valid = 0;
                }
                if (spaces != 2) valid = 0;
                if (!valid) printf("Invalid name.\n");
            }

            /* EMAIL (digits only → auto construct) */
            rebuildEmail(&s);

            /* PHONE */
            valid = 0;
            while (!valid) {
                printf("Enter phone (+CC XXXXXXXXXX): ");
                if (scanf(" %[^\n]", s.phone) != 1) {
                    while (getchar() != '\n');
                    continue;
                }

                valid = 1;
                if (strlen(s.phone) != 14 ||
                    s.phone[0] != '+' ||
                    s.phone[3] != ' ')
                    valid = 0;

                for (int i = 1; i <= 2 && valid; i++)
                    if (!isdigit(s.phone[i])) valid = 0;
                for (int i = 4; i < 14 && valid; i++)
                    if (!isdigit(s.phone[i])) valid = 0;

                for (int i = 0; i < total && valid; i++)
                    if (strcmp(students[i].phone, s.phone) == 0)
                        valid = 0;

                if (!valid) printf("Invalid or duplicate phone.\n");
            }

            students[total++] = s;
            printf("Student added!\n");
        }

        /* ================================
                VIEW STUDENTS
           ================================ */
        else if (choice == 2) {
            if (total == 0) {
                printf("No students.\n");
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

        /* ================================
                UPDATE STUDENT
           ================================ */
        else if (choice == 3) {
            if (total == 0) {
                printf("No records to update.\n");
                continue;
            }

            unsigned int roll;
            printf("Enter roll to update: ");
            scanf("%u", &roll);

            int idx = -1;
            for (int i = 0; i < total; i++)
                if (students[i].roll == roll)
                    idx = i;

            if (idx == -1) {
                printf("Roll not found.\n");
                continue;
            }

            printf("\nWhat to update?\n");
            printf("1. Name\n");
            printf("2. Email (digits only)\n");
            printf("3. Phone\n");
            printf("Choose: ");

            int op;
            scanf("%d", &op);

            if (op == 1) {
                int valid = 0;
                while (!valid) {
                    printf("Enter full name: ");
                    if (scanf(" %[^\n]", students[idx].name) != 1) {
                        while (getchar() != '\n');
                        continue;
                    }

                    int spaces = 0; valid = 1;
                    for (int i = 0; students[idx].name[i]; i++) {
                        if (students[idx].name[i] == ' ') spaces++;
                        else if (!isalpha(students[idx].name[i])) valid = 0;
                    }
                    if (spaces != 2) valid = 0;

                    if (!valid) printf("Invalid name.\n");
                }

                rebuildEmail(&students[idx]);
                printf("Updated.\n");
            }

            else if (op == 2) {
                rebuildEmail(&students[idx]);
                printf("Updated.\n");
            }

            else if (op == 3) {
                int valid = 0;
                while (!valid) {
                    printf("Enter phone (+CC XXXXXXXXXX): ");
                    if (scanf(" %[^\n]", students[idx].phone) != 1) {
                        while (getchar() != '\n');
                        continue;
                    }

                    valid = 1;
                    if (strlen(students[idx].phone) != 14 ||
                        students[idx].phone[0] != '+' ||
                        students[idx].phone[3] != ' ')
                        valid = 0;

                    for (int i = 1; i <= 2 && valid; i++)
                        if (!isdigit(students[idx].phone[i])) valid = 0;
                    for (int i = 4; i < 14 && valid; i++)
                        if (!isdigit(students[idx].phone[i])) valid = 0;

                    if (!valid) printf("Invalid phone.\n");
                }
                printf("Updated.\n");
            }

            else printf("Invalid option.\n");
        }

        /* ================================
                DELETE STUDENT
           ================================ */
        else if (choice == 4) {
            if (total == 0) {
                printf("No records to delete.\n");
                continue;
            }

            unsigned int roll;
            printf("Enter roll to delete: ");
            scanf("%u", &roll);

            int idx = -1;
            for (int i = 0; i < total; i++)
                if (students[i].roll == roll)
                    idx = i;

            if (idx == -1) {
                printf("Roll not found.\n");
                continue;
            }

            // shift left
            for (int i = idx; i < total - 1; i++)
                students[i] = students[i + 1];

            total--;
            printf("Record deleted.\n");
        }

        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }
}
