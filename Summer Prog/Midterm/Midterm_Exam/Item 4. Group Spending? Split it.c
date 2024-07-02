#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

typedef struct{
	char fName[20];
	char lName[20];
}name;

typedef struct{
	name personName;
	int id;
}personInfo;

typedef struct{
	personInfo person;
	float Lent_or_Borrowed;
}userDetails;

typedef struct{
	float paymentValue;
	char payerName[20];
}transaction;

userDetails addUser(char fName[],char lName[],int idNumber,int initialValue); //Helper Func
userDetails* initUsers(); //Helper Func
transaction addRecord(float payment,char payerName[]); //Helper Func
transaction* initRecords(); //Helper Func


void calculateSplits(transaction* records, userDetails* users, int recordCount, int userCount);
void display(userDetails* users, int userCount);

int main() {
    transaction* records = initRecords();
    int recordCount = 20;

    userDetails* users = initUsers();
    int userCount = 3;

    calculateSplits(records, users, recordCount, userCount);
    display(users, userCount);

    // free(records);
    // free(users);
}

void calculateSplits(transaction* records, userDetails* users, int recordCount, int userCount) {
    for (int i = 0; i < recordCount; i++) {
        float amount = records[i].paymentValue;
        char* payer = records[i].payerName;

        for (int j = 0; j < userCount; j++) {
            if (strcmp(users[j].person.personName.fName, payer) == 0) {
                users[j].Lent_or_Borrowed += amount - (amount / userCount);
            } else {
                users[j].Lent_or_Borrowed -= amount / userCount;
            }
        }
    }
}


void display(userDetails* users, int userCount) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].Lent_or_Borrowed > 0) {
            printf("%s is owed %.2f by the group\n", users[i].person.personName.fName, users[i].Lent_or_Borrowed);
        } else if (users[i].Lent_or_Borrowed < 0) {
            printf("%s owes %.2f to the group\n", users[i].person.personName.fName, -users[i].Lent_or_Borrowed);
        }
    }
}
