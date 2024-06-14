#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct {
    int roll_no;
    char name[50];
    float marks[3]; // marks in three subjects
} Student;

Student students[MAX_STUDENTS];
int num_students = 0;

void add_student() {
    if (num_students < MAX_STUDENTS) {
        printf("Enter roll number: ");
        scanf("%d", &students[num_students].roll_no);
        printf("Enter name: ");
        scanf("%s", students[num_students].name);
        printf("Enter marks in three subjects: ");
        scanf("%f%f%f", &students[num_students].marks[0], &students[num_students].marks[1], &students[num_students].marks[2]);
        num_students++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached!\n");
    }
}

void delete_student() {
    int roll_no;
    printf("Enter roll number of student to delete: ");
    scanf("%d", &roll_no);
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_no == roll_no) {
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void display_students() {
    printf("Student Records:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f, %.2f, %.2f\n",
               students[i].roll_no, students[i].name, students[i].marks[0], students[i].marks[1], students[i].marks[2]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Student Record System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                display_students();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}