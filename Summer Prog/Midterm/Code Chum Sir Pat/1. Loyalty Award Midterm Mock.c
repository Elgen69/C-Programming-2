#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX 50
#define LIST_MAX 10
typedef struct{
	int month;
	int year;
}currentDate;
typedef struct{
	int hireMonth;
	int hireYear;
}hiringDetails;

typedef struct{
	char fName[STRING_MAX];
}empDetails;

typedef struct{
	hiringDetails dateOfHire;
	empDetails employeeInfo;
}employee;

typedef struct{
	employee employeeList[LIST_MAX];
	int count;
}employeeRecords;

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate);
void display(employee *loyalList,int loyalListCount);

int main(){
	employeeRecords record;
	int employeeCount;
	int loyalListCount=0;
	record.count=0;
	employee *loyalList;
	currentDate date={07,2023};
	
	int i=0;
	printf("Input Number of Employees:" );
    scanf("%d",&employeeCount);
    record.count = employeeCount;
    
    printf("\nInput Details for Employees: \n");
    for(i=0;i<employeeCount;i++){
    	printf("\n\n===Employee %d===\n",i+1);
    	printf("Input First Name: ");
    	scanf("%s", record.employeeList[i].employeeInfo.fName);
        getchar();
    	printf("Input Month of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);
    	printf("Input Year of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireYear);
	}
	
	loyalList=getLoyalList(record,&loyalListCount,date);
    
	display(loyalList, loyalListCount);
	
	return 0;
}

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate){
    int i = 0, count = 0;
    
    for(i = 0; i < record.count; i++){
        int years_worked = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        int months_worked = currDate.month - record.employeeList[i].dateOfHire.hireMonth;
        if(years_worked > 5 || (years_worked == 5 && months_worked >= 0)){
            count++;
        }
    }
    
    if(count == 0){
        printf("There are currently no Employees who are eligible for the reward.");
        exit(0);
    }
    
    *loyalListCount = count;
    
    employee *loyalList = malloc(count * sizeof(employee));
    
    count = 0;
    for(i = 0; i < record.count; i++){
        int years_worked = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        int months_worked = currDate.month - record.employeeList[i].dateOfHire.hireMonth;
        if(years_worked > 5 || (years_worked == 5 && months_worked >= 0)){
            loyalList[count++] = record.employeeList[i];
        }
    }
    
    return loyalList;
}

void display(employee *loyalList,int loyalListCount){
    printf("Loyal List: \n\n");
    for(int i = 0; i < loyalListCount; i++){
        printf("Name: %s -- Hire Date:%d-%d\n", 
        loyalList[i].employeeInfo.fName, 
        loyalList[i].dateOfHire.hireMonth, 
        loyalList[i].dateOfHire.hireYear);
    }
}
