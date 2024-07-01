#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

typedef struct {
    char fName[50];
    char lName[50];
    char MI;
} name;

typedef struct {
    name studentName;
    char studentAnswer[MAX];
    int studentScore;
} studentResults;

typedef struct {
    studentResults *record;
    int count;
} classRecord;

void disp(classRecord);
studentResults addstud(char[], char[], char, char[]);
void populate(classRecord *, int);
void checkExams(char[], classRecord*);

int main() {
    char answerKey[] = "TTTFFTTFTF";
    classRecord examRecords;
    int classCount;
    examRecords.count = 0;

    printf("How many students in the class? ");
    scanf("%d", &classCount);

    // Write code to only allow a class of more than 0
    if (classCount <= 0) {
        printf("Class Count has to be greater than 0");
        return 0;
    }

    // Write code to initialize array of students.
    examRecords.record = (studentResults*) malloc(classCount * sizeof(studentResults));
    examRecords.count = classCount;

    populate(&examRecords, classCount);
    checkExams(answerKey, &examRecords);

    disp(examRecords);

    free(examRecords.record); // Free allocated memory
    return 0;
}

void checkExams(char answerKey[], classRecord *examRecord) {
    // Write Code to check exams here and record the students score
    for (int i = 0; i < examRecord->count; i++) {
        examRecord->record[i].studentScore = 0;
        for (int j = 0; j < 10; j++) {
            if (answerKey[j] == examRecord->record[i].studentAnswer[j]) {
                examRecord->record[i].studentScore++;
            }
        }
    }
}

void populate(classRecord *examRecord, int classCount) {
    int i = 0;
    char fName[50];
    char lName[50];
    char MI;
    char studentAnswer[MAX];

    for (i = 0; i < classCount; i++) {
        printf("===STUDENT %d===\n\n", i + 1);

      
        printf("Input First Name: ");
        scanf("%s", fName);
        printf("Input Last Name: ");
        scanf("%s", lName);
        printf("Input Middle Initial: ");
        scanf(" %c", &MI);
        printf("Input Students Answer [10]: ");
        scanf("%s", studentAnswer);

     
        examRecord->record[i] = addstud(fName, lName, MI, studentAnswer);
    }
 
}

studentResults addstud(char fName[], char lName[], char MI, char studentAnswer[]) {
    studentResults newStudent;
    strcpy(newStudent.studentName.fName, fName);
    strcpy(newStudent.studentName.lName, lName);
    newStudent.studentName.MI = MI;
    strcpy(newStudent.studentAnswer, studentAnswer);
    newStudent.studentScore = 0; 
    return newStudent;
}

void disp(classRecord examRecords) {
    for (int i = 0; i < examRecords.count; i++) {
        printf("\n===STUDENT %d===\n\n", i + 1);
        printf("Student Name: %s, %s %c\n", examRecords.record[i].studentName.lName,
               examRecords.record[i].studentName.fName, examRecords.record[i].studentName.MI);
        printf("Student Answer: %s\n", examRecords.record[i].studentAnswer);
        printf("Student Score: %d / 10\n\n\n", examRecords.record[i].studentScore);
    }
}
