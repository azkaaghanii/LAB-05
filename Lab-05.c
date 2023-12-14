//QUESTION NO 1:
//Write a program to create a new text file and write some text into it. Open the file in append mode and add more text to it. Read the contents of the file and display them on the console.

//#include <stdio.h>
//
//int main() {
//    FILE *file;
//    char text[] = "This is some text.";
//
//    file = fopen("example.txt", "w");
//    if (file == NULL) {
//        printf("Error opening file!\n");
//        return 1;
//    }
//    fprintf(file, "%s\n", text);
//    fclose(file);
//
//
//    file = fopen("example.txt", "a");
//    if (file == NULL) {
//        printf("Error opening file!\n");
//        return 1;
//    }
//    fprintf(file, "This is additional text.\n");
//    fclose(file);
//
//
//    char ch;
//    file = fopen("example.txt", "r");
//    if (file == NULL) {
//        printf("Error opening file!\n");
//        return 1;
//    }
//    printf("Contents of the file:\n");
//    while ((ch = fgetc(file)) != EOF) {
//        printf("%c", ch);
//    }
//    fclose(file);
//
//    return 0;
//}



//QUESTION NO 2:
//Create a program that reads a text file and counts the number of words in it. Display the total number of words at the end.

//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//int main() {
//    FILE *file;
//    char filename[100];
//    int ch;  // Change the data type from char to int
//    int words = 0;
//    int inWord = 0;
//
//    printf("Enter the filename: ");
//    scanf("%s", filename);
//
//    file = fopen(filename, "r");
//
//    if (file == NULL) {
//        printf("Could not open file %s\n", filename);
//        return 1;
//    }
//
//    while ((ch = fgetc(file)) != EOF) {
//        if (isspace(ch) || ch == '\t' || ch == '\n' || ch == '\r') {
//            inWord = 0;
//        } else if (inWord == 0) {
//            inWord = 1;
//            words++;
//        }
//    }
//
//    fclose(file);
//
//    printf("Total number of words in the file: %d\n", words);
//
//    return 0;
//}

//
//QUESTION NO 3:
//Implement a student database system using a file. Include features to add, delete, modify, and display student records.

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_NAME_LENGTH 50
//#define FILENAME "student_database.txt"
//
//struct Student {
//    int id;
//    char name[MAX_NAME_LENGTH];
//    float grade;
//};
//
//void addStudent(FILE *file) {
//    struct Student newStudent;
//    printf("Enter student ID: ");
//    scanf("%d", &newStudent.id);
//
//    printf("Enter student name: ");
//    scanf(" %[^\n]s", newStudent.name);
//
//    printf("Enter student grade: ");
//    scanf("%f", &newStudent.grade);
//
//    fwrite(&newStudent, sizeof(struct Student), 1, file);
//    printf("Student added successfully.\n");
//}
//
//void displayStudents(FILE *file) {
//    struct Student student;
//    rewind(file);
//    printf("\n-- Student Records --\n");
//    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
//        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
//    }
//    printf("---------------------\n");
//}
//
//void deleteStudent(FILE *file, int id) {
//    struct Student student;
//    FILE *tempFile = fopen("temp.txt", "w");
//    rewind(file);
//
//    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
//        if (student.id != id) {
//            fwrite(&student, sizeof(struct Student), 1, tempFile);
//        }
//    }
//    fclose(file);
//    fclose(tempFile);
//    remove(FILENAME);
//    rename("temp.txt", FILENAME);
//    printf("Student with ID %d deleted successfully.\n", id);
//}
//
//void modifyStudent(FILE *file, int id) {
//    struct Student student;
//    int found = 0;
//    rewind(file);
//
//    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
//        if (student.id == id) {
//            found = 1;
//            printf("Enter new name: ");
//            scanf(" %[^\n]s", student.name);
//
//            printf("Enter new grade: ");
//            scanf("%f", &student.grade);
//
//            fseek(file, -sizeof(struct Student), SEEK_CUR);
//            fwrite(&student, sizeof(struct Student), 1, file);
//            printf("Student with ID %d modified successfully.\n", id);
//            break;
//        }
//    }
//
//    if (!found) {
//        printf("Student with ID %d not found.\n", id);
//    }
//}
//
//int main() {
//    FILE *file = fopen(FILENAME, "ab+");
//    if (file == NULL) {
//        printf("Error opening file.\n");
//        return 1;
//    }
//
//    int choice;
//    int id;
//    while (1) {
//        printf("\n-- Student Database System --\n");
//        printf("1. Add student\n");
//        printf("2. Display all students\n");
//        printf("3. Delete a student\n");
//        printf("4. Modify a student\n");
//        printf("5. Exit\n");
//        printf("Enter your choice: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//            case 1:
//                addStudent(file);
//                break;
//            case 2:
//                displayStudents(file);
//                break;
//            case 3:
//                printf("Enter ID of student to delete: ");
//                scanf("%d", &id);
//                deleteStudent(file, id);
//                break;
//            case 4:
//                printf("Enter ID of student to modify: ");
//                scanf("%d", &id);
//                modifyStudent(file, id);
//                break;
//            case 5:
//                fclose(file);
//                exit(0);
//            default:
//                printf("Invalid choice. Please enter a valid option.\n");
//        }
//    }
//    return 0;
//}
