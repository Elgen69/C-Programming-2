#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *name;
    int age;
    float grade;
} Students;

void input(Students*);
void display(Students*);

int main(void){
    Students student[2];

    input(student);
    display(student);

    free(student->name);

    return 0;
}

void input(Students* student){
    student->name = (char*) malloc(100 * sizeof(char));
    for(int i = 0; i < 2; i++){
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", student[i].name);
        getchar();
        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &student[i].age);
        getchar();
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%f", &student[i].grade);
        getchar();
    }
}

void display(Students* student){
    printf("Name\tAge\tGrade\n");
    for(int i = 0; i < 2; i++){
        printf("%s\t%d\t%.2f\n", student[i].name, student[i].age, student[i].grade);
        
    }
}
