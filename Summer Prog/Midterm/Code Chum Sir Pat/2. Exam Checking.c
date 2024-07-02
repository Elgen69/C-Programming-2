#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char fName[50];
    char lName[50];
    char middleInitial;
} name;

typedef struct {
    name studentName;
    int idNum;
    int studentGrades[3];
} studentDetail;

typedef struct {
    studentDetail student[MAX];
    int count;
} classRecord;

typedef struct {
    classRecord classList;
    classRecord examRetake[3];
} classResults;

void populate(classRecord *record, int classCount);
studentDetail addStudent(char *fName, char *lName, char mi, int idNum, int grades[3]);
void checkExams(classResults *results);
void display(classResults *results);

int main() {
    int classCount;
    classResults results;
    results.classList.count = 0;

    results.examRetake[0].count = 0;
    results.examRetake[1].count = 0;
    results.examRetake[2].count = 0;

    printf("Input Number of Students in Class:");
    scanf("%d", &classCount);
    if (classCount > MAX) {
        printf("Maximum Number of Students per Class is only 10");
        return 1; 
    }
    populate(&results.classList, classCount);

    checkExams(&results);

    display(&results);
    return 0;
}
void populate(classRecord *record, int classCount) {
    char fName[50];
    char lName[50];
    char MI;
    int idNum;
    int grades[3];

    for (int i = 0; i < classCount; i++) {
        printf("===STUDENT %d===\n\n", i + 1);
        printf("Input First Name: ");
        scanf("%s", fName);
        printf("Input Last Name: ");
        scanf("%s", lName);
        printf("Input Middle Initial: ");
        scanf(" %c", &MI);
        printf("Input ID Number: ");
        scanf("%d", &idNum);
        printf("Input Exam Score 1: ");
        scanf("%d", &grades[0]);
        printf("Input Exam Score 2: ");
        scanf("%d", &grades[1]);
        printf("Input Exam Score 3: ");
        scanf("%d", &grades[2]);

        record->student[i] = addStudent(fName, lName, MI, idNum, grades);
        record->count++;
    }
}

studentDetail addStudent(char *fName, char *lName, char mi, int idNum, int grades[3]) {
    studentDetail details;

    details.studentName.middleInitial = mi;
    strcpy(details.studentName.fName, fName);
    strcpy(details.studentName.lName, lName);

    details.idNum = idNum;

    for (int i = 0; i < 3; i++) {
        details.studentGrades[i] = grades[i];
    }

    return details;
}
void checkExams(classResults *results) {
    for (int i = 0; i < results->classList.count; i++) {
        // Check each exam score for each student
        for (int j = 0; j < 3; j++) {
            if (results->classList.student[i].studentGrades[j] < 60) {
                // If score is less than 60, add student to retake list for exam j+1
                results->examRetake[j].student[results->examRetake[j].count] = results->classList.student[i];
                results->examRetake[j].count++;
            }
        }
    }
}


void display(classResults *results) {
    int i, j;
    printf("Retakers Needed for Exam 1:");
    int exam1Needed = 0;
    for (i = 0; i < results->classList.count; i++) {
        if (results->classList.student[i].studentGrades[0] < 60) {
            exam1Needed++;
            if(exam1Needed == results->classList.count - 1) printf("All Students Have to Retake Exam 1");
            break;
        }
    }
    if(exam1Needed != results->classList.count - 1){
    for (i = 0; i < results->classList.count; i++) {
        if (results->classList.student[i].studentGrades[0] < 60) {
            printf("%s ", results->classList.student[i].studentName.fName);
            }
        }
    }
    if (!exam1Needed) {
        printf("No Retakers for Exam 1");
    }
    printf("\n\n");

    printf("Retakers Needed for Exam 2:");
    int exam2Needed = 0;
    for (i = 0; i < results->classList.count; i++) {
        if (results->classList.student[i].studentGrades[1] < 60) {
            exam2Needed++;
            if(exam2Needed == results->classList.count - 1) printf("All Students Have to Retake Exam 2");
            break;
        }
    }
    if(exam2Needed != results->classList.count - 1){
    for (i = 0; i < results->classList.count; i++) {
        if (results->classList.student[i].studentGrades[1] < 60) {
            printf("%s ", results->classList.student[i].studentName.fName);
            }
        }
    }
    if (!exam2Needed) {
        printf("No Retakers for Exam 2");
    }
    printf("\n\n");

    printf("Retakers Needed for Exam 3:");
    int exam3Needed = 0;
    for (i = 0; i < results->classList.count; i++) {
        if (results->classList.student[i].studentGrades[2] < 60) {
            exam3Needed++;
            if(exam3Needed == results->classList.count - 1) printf("All Students Have to Retake Exam 3");
            break;
        }
    }
    if(exam3Needed != results->classList.count - 1){
    for (i = 0; i < results->classList.count; i++) {
        if (results->classList.student[i].studentGrades[2] < 60) {
            printf("%s ", results->classList.student[i].studentName.fName);
            }
        }
    }
    if (!exam3Needed) {
        printf("No Retakers for Exam 3");
    }
    printf("\n\n");
}


