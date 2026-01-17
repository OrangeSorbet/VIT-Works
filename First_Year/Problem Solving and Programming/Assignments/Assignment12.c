#include <stdio.h>
#include <stdlib.h>

struct Student {
    int prnNumber;
    char year[20];
    char stream[50];
    char division[3];
    int rollNo;
    char name[50];
};

void inputStudentData(struct Student *student) {
    printf("Enter PRN Number: ");
    scanf("%d", &student->prnNumber);
    getchar();

    printf("Enter Year (FY, SY, TY, Btech): ");
    fgets(student->year, sizeof(student->year), stdin);
    student->year[strcspn(student->year, "\n")] = '\0';

    printf("Enter Stream (CS, AIDS, CSAI, CSAIML, CSSE, CSIOT, CSDS, EnTC, IT, Instru, Mech, Chem, Civil): ");
    fgets(student->stream, sizeof(student->stream), stdin);
    student->stream[strcspn(student->stream, "\n")] = '\0';

    printf("Enter Division: ");
    fgets(student->division, sizeof(student->division), stdin);
    student->division[strcspn(student->division, "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &student->rollNo);
    getchar();

    printf("Enter Name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';
}

void displayStudentData(struct Student student) {
    printf("\nStudent PRN Number: %d\n", student.prnNumber);
    printf("Student Year: %s\n", student.year);
    printf("Student Stream: %s\n", student.stream);
    printf("Student Division: %s\n", student.division);
    printf("Student Roll Number: %d\n", student.rollNo);
    printf("Student Name: %s\n", student.name);
}

void modifyStudentRecord(struct Student *student) {
    printf("Modify PRN Number: ");
    scanf("%d", &student->prnNumber);
    getchar();

    printf("Modify Year (FY, SY, TY, Btech): ");
    fgets(student->year, sizeof(student->year), stdin);
    student->year[strcspn(student->year, "\n")] = '\0';

    printf("Modify Stream (CS, AIDS, CSAI, CSAIML, CSSE, CSIOT, CSDS, EnTC, IT, Instru, Mech, Chem, Civil): ");
    fgets(student->stream, sizeof(student->stream), stdin);
    student->stream[strcspn(student->stream, "\n")] = '\0';

    printf("Modify Division: ");
    fgets(student->division, sizeof(student->division), stdin);
    student->division[strcspn(student->division, "\n")] = '\0';

    printf("Modify Roll Number: ");
    scanf("%d", &student->rollNo);
    getchar();

    printf("Modify Name: ");
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0';
}

int main() {
    int choice, numStudents = 0, modifyChoice;
    struct Student *students = NULL;

    do {
        printf("---------------------------------\n");
        printf("VISHWAKARMA INSITUTE OF TECHNOLOGY RECORDS\n");
        printf("---------------------------------\n");
        printf("1. Insert Student Records\n");
        printf("2. Display Student Records\n");
        printf("3. Modify Student Record\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                students = realloc(students, (numStudents + 1) * sizeof(struct Student));
                printf("Enter details for Student %d:\n", numStudents + 1);
                inputStudentData(&students[numStudents]);
                numStudents++;
                break;

            case 2:
                if (numStudents == 0) {
                    printf("No records available.\n");
                } else {
                    for (int i = 0; i < numStudents; i++) {
                        printf("\nDisplaying details for Student %d:\n", i + 1);
                        displayStudentData(students[i]);
                    }
                }
                break;

            case 3:
                if (numStudents == 0) {
                    printf("No records available to modify.\n");
                } else {
                    printf("Enter the Student Record Number to modify (1 to %d): ", numStudents);
                    scanf("%d", &modifyChoice);
                    if (modifyChoice >= 1 && modifyChoice <= numStudents) {
                        modifyStudentRecord(&students[modifyChoice - 1]);
                    } else {
                        printf("Invalid Record Number!\n");
                    }
                }
                break;

            case 4:
                printf("Exiting program...\n");
                free(students);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
