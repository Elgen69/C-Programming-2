#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];  
    int roll_number; 
    int age;
} Student;

void disp_sort(Student *students, int num);

int main(void) {
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student *students = malloc(num_students * sizeof(Student));

    for (int i = 0; i < num_students; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_number);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
    }

    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].roll_number > students[j + 1].roll_number) {
                // Swap students[j] and students[j+1]
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
  
    disp_sort(students, num_students);

    free(students);

    return 0;
}

void disp_sort(Student *students, int num) {
    printf("\nStudents sorted by roll number:\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t%s\t%d\n", students[i].roll_number, students[i].name, students[i].age);
    }
}
