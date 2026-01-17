#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_YEAR_LENGTH 10
#define MAX_STREAM_LENGTH 20
#define MAX_DIVISION_LENGTH 5

struct Student {
    int prnNumber;
    char year[MAX_YEAR_LENGTH];
    char stream[MAX_STREAM_LENGTH];
    char division[MAX_DIVISION_LENGTH];
    int rollNo;
    char name[MAX_NAME_LENGTH];
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

void writeStudentToFile(const char *filename, struct Student *student) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "----------------------------------\n");
    fprintf(file, "PRN: %d\n", student->prnNumber);
    fprintf(file, "Year: %s\n", student->year);
    fprintf(file, "Stream: %s\n", student->stream);
    fprintf(file, "Division: %s\n", student->division);
    fprintf(file, "Roll No: %d\n", student->rollNo);
    fprintf(file, "Name: %s\n", student->name);

    fclose(file);
}

void readStudentsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Student student;

    while (fscanf(file,
                  "----------------------------------\n"
                  "PRN: %d\n"
                  "Year: %[^ \n]\n"
                  "Stream: %[^ \n]\n"
                  "Division: %[^ \n]\n"
                  "Roll No: %d\n"
                  "Name: %[^\n]\n",
                  &student.prnNumber,
                  student.year,
                  student.stream,
                  student.division,
                  &student.rollNo,
                  student.name) == 6) {
        printf("----------------------------------\n");
        printf("PRN: %d\n", student.prnNumber);
        printf("Year: %s\n", student.year);
        printf("Stream: %s\n", student.stream);
        printf("Division: %s\n", student.division);
        printf("Roll No: %d\n", student.rollNo);
        printf("Name: %s\n", student.name);
        printf("\n");
    }

    fclose(file);
}

void deleteRecordFromFile(const char *filename, int prnToDelete) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

   struct Student student;
   bool recordFound = false;

   while (fscanf(file,
                 "----------------------------------\n"
                 "PRN: %d\n"
                 "Year: %[^ \n]\n"
                 "Stream: %[^ \n]\n"
                 "Division: %[^ \n]\n"
                 "Roll No: %d\n"
                 "Name: %[^\n]\n",
                 &student.prnNumber,
                 student.year,
                 student.stream,
                 student.division,
                 &student.rollNo,
                 student.name) == 6) {
       if (student.prnNumber != prnToDelete) {
           writeStudentToFile("temp.txt", &student);
       } else {
           recordFound = true;
       }
   }

   fclose(file);
   fclose(tempFile);

   remove(filename);
   rename("temp.txt", filename);

   if (!recordFound) {
       printf("Record with PRN %d not found.\n", prnToDelete);
   } else {
       printf("Record with PRN %d deleted successfully.\n", prnToDelete);
   }
}

void modifyRecordInFile(const char *filename, int prnToModify) {
   FILE *file = fopen(filename, "r");
   FILE *tempFile = fopen("temp.txt", "w");

   if (file == NULL || tempFile == NULL) {
       perror("Error opening file");
       return;
   }

   struct Student student;
   bool recordFound = false;

   while (fscanf(file,
                 "----------------------------------\n"
                 "PRN: %d\n"
                 "Year: %[^ \n]\n"
                 "Stream: %[^ \n]\n"
                 "Division: %[^ \n]\n"
                 "Roll No: %d\n"
                 "Name: %[^\n]\n",
                 &student.prnNumber,
                 student.year,
                 student.stream,
                 student.division,
                 &student.rollNo,
                 student.name) == 6) {
       if (student.prnNumber == prnToModify) {
           printf("Modifying record for PRN %d:\n", prnToModify);
           inputStudentData(&student);
           recordFound = true;
       }

       writeStudentToFile("temp.txt", &student);
   }

   fclose(file);
   fclose(tempFile);

   remove(filename);
   rename("temp.txt", filename);

   if (!recordFound) {
       printf("PRN %d not found. Please enter a valid PRN number.\n", prnToModify);
   } else {
       printf("Record with PRN %d modified successfully.\n", prnToModify);
   }
}

int main() {
   const char *filename = "students.txt";

   int choice;

   do {
       printf("\n---------------------------------\n");
       printf("VISHWAKARMA INSTITUTE OF TECHNOLOGY RECORDS\n");
       printf("---------------------------------\n");
       printf("1. Insert Student Records\n");
       printf("2. Display Student Records\n");
       printf("3. Modify Student Record\n");
       printf("4. Delete Student Record\n");
       printf("5. Exit\n");
       printf("---------------------------------\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               {
               struct Student newStudent;
               inputStudentData(&newStudent);
               writeStudentToFile(filename, &newStudent);
               break;
               }
           case 2:
               readStudentsFromFile(filename);
               break;
           case 3:
               {
                   int prnToModify;
                   printf("Enter PRN number to modify: ");
                   scanf("%d", &prnToModify);
                   modifyRecordInFile(filename, prnToModify);
                   break;
               }
           case 4:
               {
                   int prnToDelete;
                   printf("Enter PRN number to delete: ");
                   scanf("%d", &prnToDelete);
                   deleteRecordFromFile(filename, prnToDelete);
                   break;
               }
           case 5:
               printf("Exiting...\n");
               break;
           default:
               printf("Invalid choice! Please try again.\n");
       }
   } while (choice != 5);

   return 0;
}
