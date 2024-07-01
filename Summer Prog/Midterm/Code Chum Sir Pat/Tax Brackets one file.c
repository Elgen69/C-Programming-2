#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define bracket1Rate 0.10
#define bracket2Rate 0.15
#define bracket3Rate 0.20

typedef struct{
    char fName[20];
    char lName[20];
    char MI;
}name;

typedef struct{
    name empName;
    int idNum;
    int grossSalary;
    int rate;
    int hrsWorked;
    float takeHomeSalary;
}employeeInfo;

typedef struct{
    employeeInfo *employees;
    int count;
}employeeRecord;

typedef struct{
    employeeRecord employeeList;
    employeeRecord bracket1;
    employeeRecord bracket2;
    employeeRecord bracket3;
}companyRecord;

employeeRecord populate(int);
employeeInfo newEmployee(int,int,int,name);
name addName(char[],char[],char);
void taxBracketSeparation(companyRecord *);
void disp(companyRecord);

int main(){
    companyRecord companyLists;
    int employeeInitialCount;

    printf("Input how many employees: ");
    scanf("%d", &employeeInitialCount);

    companyLists.employeeList = populate(employeeInitialCount);
    taxBracketSeparation(&companyLists);
    disp(companyLists);

    return 0;
}

employeeRecord populate(int count){
    employeeRecord list;
    list.employees = malloc(sizeof(employeeInfo) * count);
    list.count = 0;

    for(int i = 0; i < count; i++){
        printf("\n\n===EMPLOYEE %d===\n\n", i + 1);
        char fName[20], lName[20], MI;
        int idNum, rate, hrsWorked;

        printf("Input First Name: ");
        scanf("%s", fName);
        printf("Input Last Name: ");
        scanf("%s", lName);
        printf("Input Middle Initial: ");
        scanf(" %c", &MI);
        printf("Input Id Number: ");
        scanf("%d", &idNum);
        printf("Input Rate: ");
        scanf("%d", &rate);
        printf("Input Hours Worked: ");
        scanf("%d", &hrsWorked);

        list.employees[i] = newEmployee(idNum, rate, hrsWorked, addName(fName, lName, MI));
        list.count++;
        if(i==count-1) printf("\n===============\n\n");
    }

    return list;
}

void taxBracketSeparation(companyRecord *companyList){
    companyList->bracket1.employees = malloc(companyList->employeeList.count * sizeof(employeeInfo));
    companyList->bracket2.employees = malloc(companyList->employeeList.count * sizeof(employeeInfo));
    companyList->bracket3.employees = malloc(companyList->employeeList.count * sizeof(employeeInfo));

    companyList->bracket1.count = 0;
    companyList->bracket2.count = 0;
    companyList->bracket3.count = 0;

    for(int i = 0; i < companyList->employeeList.count; i++){
        if(companyList->employeeList.employees[i].grossSalary < 15000){
            companyList->bracket1.employees[companyList->bracket1.count] = companyList->employeeList.employees[i];

            companyList->bracket1.employees[companyList->bracket1.count++].takeHomeSalary = companyList->bracket1.employees[companyList->bracket1.count].grossSalary * (1 - bracket1Rate);
            
         }
        else if(companyList->employeeList.employees[i].grossSalary >= 15000 && companyList->employeeList.employees[i].grossSalary < 26000){
            companyList->bracket2.employees[companyList->bracket2.count] = companyList->employeeList.employees[i];
            
            companyList->bracket2.employees[companyList->bracket2.count++].takeHomeSalary = companyList->bracket2.employees[companyList->bracket2.count].grossSalary * (1 - bracket2Rate);
                
        }
        else{
            companyList->bracket3.employees[companyList->bracket3.count] = companyList->employeeList.employees[i];
            
            companyList->bracket3.employees[companyList->bracket3.count++].takeHomeSalary = companyList->bracket3.employees[companyList->bracket3.count].grossSalary * (1 - bracket3Rate);

        }
    }
    
}

employeeInfo newEmployee(int idNum, int rate, int hrsWorked, name employeeName){
    employeeInfo newEmp;
    newEmp.empName = employeeName;
    newEmp.idNum = idNum;
    newEmp.rate = rate;
    newEmp.hrsWorked = hrsWorked;
    newEmp.grossSalary = rate * hrsWorked;
    newEmp.takeHomeSalary = 0.0; // Will be calculated later
    return newEmp;
}

name addName(char fName[], char lName[], char MI){
    name employeeName;
    strcpy(employeeName.fName, fName);
    strcpy(employeeName.lName, lName);
    employeeName.MI = MI;
    return employeeName;
}

void disp(companyRecord companyLists) {
    int bracketsWithCount = 0; 

    if (companyLists.bracket1.count > 0) {
        bracketsWithCount++;
        if (bracketsWithCount > 0) {
            printf("\n");
        }
        printf("\n===BRACKET 1===\n");
        for (int i = 0; i < companyLists.bracket1.count; i++) {
            printf("%d - %s,%s %c --- Php %.2f\n", companyLists.bracket1.employees[i].idNum,
                   companyLists.bracket1.employees[i].empName.lName,
                   companyLists.bracket1.employees[i].empName.fName,
                   companyLists.bracket1.employees[i].empName.MI,
                   companyLists.bracket1.employees[i].takeHomeSalary);
        }
    } 
    
    if (companyLists.bracket2.count > 0) {
        bracketsWithCount++;
        if (bracketsWithCount > 0) {
            printf("\n");
        }
        printf("\n===BRACKET 2===\n");
        for (int i = 0; i < companyLists.bracket2.count; i++) {
            printf("%d - %s,%s %c --- Php %.2f\n", companyLists.bracket2.employees[i].idNum,
                   companyLists.bracket2.employees[i].empName.lName,
                   companyLists.bracket2.employees[i].empName.fName,
                   companyLists.bracket2.employees[i].empName.MI,
                   companyLists.bracket2.employees[i].takeHomeSalary);
        }
    } 
    
    if (companyLists.bracket3.count > 0) {
        bracketsWithCount++;
        if (bracketsWithCount > 0) {
            printf("\n");
        }
        printf("\n===BRACKET 3===\n");
        for (int i = 0; i < companyLists.bracket3.count; i++) {
            printf("%d - %s,%s %c --- Php %.2f\n", companyLists.bracket3.employees[i].idNum,
                   companyLists.bracket3.employees[i].empName.lName,
                   companyLists.bracket3.employees[i].empName.fName,
                   companyLists.bracket3.employees[i].empName.MI,
                   companyLists.bracket3.employees[i].takeHomeSalary);
        }
    } 
}