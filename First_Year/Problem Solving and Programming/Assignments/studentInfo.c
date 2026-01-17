#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    float marks[7];
    float percentage;
    char subjects[7][30];
};

void inputStudentData(struct Student *student) {
    printf("Enter Roll Number: ");
    scanf("%d", &student->rollNo);
    getchar();
    printf("Enter Name: ");
    fgets(student->name, sizeof(student->name), stdin);

    char predefinedSubjects[7][30] = {"LAADE", "PSP", "COAA", "GP1", "SA1", "IKS", "RAD"};

    printf("Enter marks for the following subjects:\n");

    float totalMarks = 0;
    for (int i = 0; i < 7; i++) {
        snprintf(student->subjects[i], sizeof(student->subjects[i]), "%s", predefinedSubjects[i]);

        printf("%s: ", student->subjects[i]);
        scanf("%f", &student->marks[i]);
        totalMarks += student->marks[i];
    }
    student->percentage = (totalMarks / 700) * 100;
}

void displayStudentData(struct Student student) {
    printf("\nStudent Roll Number: %d\n", student.rollNo);
    printf("Student Name: %s", student.name);
    printf("Marks in Subjects:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s: %.2f\n", student.subjects[i], student.marks[i]);
    }
    printf("Percentage: %.2f%%\n", student.percentage);
}

void modifyStudentRecord(struct Student *student) {
    printf("Modify Roll Number: ");
    scanf("%d", &student->rollNo);
    getchar();
    printf("Modify Name: ");
    fgets(student->name, sizeof(student->name), stdin);

    float totalMarks = 0;
    for (int i = 0; i < 7; i++) {
        printf("Modify marks for %s: ", student->subjects[i]);
        scanf("%f", &student->marks[i]);
        totalMarks += student->marks[i];
    }
    student->percentage = (totalMarks / 700) * 100;
}

void saveStudentToFile(struct Student student) {
    FILE *file = fopen("student_records.txt", "a");  // Open file in append mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Roll Number: %d\n", student.rollNo);
    fprintf(file, "Name: %s", student.name);  // Including newline from fgets
    fprintf(file, "Marks:\n");
    for (int i = 0; i < 7; i++) {
        fprintf(file, "%s: %.2f\n", student.subjects[i], student.marks[i]);
    }
    fprintf(file, "Percentage: %.2f%%\n\n", student.percentage);

    fclose(file);
    printf("Student information saved to student_records.txt\n");
}

int main() {
    int choice, numStudents = 0, modifyChoice;
    struct Student *students = NULL;

    do {
        printf("\n---------------------------------\n");
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
                students = realloc(students, (numStudents + 1) * sizeof(struct Student));  // Dynamically increase array size
                printf("Enter details for Student %d:\n", numStudents + 1);
                inputStudentData(&students[numStudents]);  // Insert student data
                saveStudentToFile(students[numStudents]);  // Save student data to file
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
                        saveStudentToFile(students[modifyChoice - 1]);  // Save modified record to file
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
