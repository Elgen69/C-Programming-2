#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char type[50]; //spear, sword, shield, helmet, armor  3 only
    int gearLevel; // 1-25
}equipment;

typedef struct{
    char type[50]; //barbarian, fighter, cleric,wizard
    char role[50]; //tank, healer, DPS
}Profession;

typedef struct{
    char name[50];
    Profession profession;
    equipment* gear;
    int gearscore;
}adventurer;

typedef struct Node{
    struct Node* next;
    adventurer Adventurer;
}Node;

void insertend(Node** head, char p_type[], char role[], int num_gear, int gear_levels[], char name[]);
void printlist(Node* head, int num_gear);
void sort(Node* head);

int main(void){
    Node* head = NULL;
    int size = 0;
    char p_type[20], role[20], a_name[20];
    int gear_levels[25], n_gear = 0;
    
    printf("Enter number of adventurers: ");
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) {
        printf("\nEnter Name Of Adventurer: ");
        scanf("%s", a_name);
        printf("Enter Type Of Profession: ");
        scanf("%s", p_type);
        printf("Enter Profession Role: ");
        scanf("%s", role);
        printf("Enter Number Of Gears: ");
        scanf("%d", &n_gear);
        printf("Enter %d Gear Levels: ", n_gear);
        for (int j = 0; j < n_gear; j++) {
            scanf("%d", &gear_levels[j]);
        }
        insertend(&head, p_type, role, n_gear, gear_levels, a_name);
    }
    sort(head);
    printlist(head, n_gear);
}

void insertend(Node** head, char p_type[], char role[], int num_gear, int gear_levels[], char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->Adventurer.name, name);
    strcpy(newNode->Adventurer.profession.type, p_type);
    strcpy(newNode->Adventurer.profession.role, role);
    
    newNode->Adventurer.gear = (equipment*)malloc(num_gear * sizeof(equipment));
    
    printf("Enter %d Adventurer Gears: ", num_gear);
    for(int i = 0; i < num_gear; i++){
        scanf("%s", newNode->Adventurer.gear[i].type);
        newNode->Adventurer.gear[i].gearLevel = gear_levels[i];
    }
    
    int j = 0;
    
    
    while(j != num_gear){
    newNode->Adventurer.gearscore += newNode->Adventurer.gear[j].gearLevel;
    j++;
    }
    
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printlist(Node* head, int num_gear){
    Node* curr = head;
    
    if(head == NULL){
        printf("\nLinked List is Empty");
        return;
    }
    
    printf("\n\nList of Adventurers: ");
    while(curr != NULL){
        printf("\nName: %s", curr->Adventurer.name);
        printf("\nType of Profession: %s", curr->Adventurer.profession.type);
        printf("\nProfession Role: %s", curr->Adventurer.profession.role);
        printf("\nAdventurer Gears and Levels: \n");
        for(int i = 0; i < num_gear; i++){
            printf("%s ", curr->Adventurer.gear[i].type);
            printf("%d ", curr->Adventurer.gear[i].gearLevel);
        }
        printf("\nGear Score: ");
        printf("%d", curr->Adventurer.gearscore);
        curr = curr->next;
    }
    printf("\n");
}

void sort(Node* head) {
    int temp = 0;
    
    for (Node* trav1 = head; trav1 != NULL; trav1 = trav1->next) {
        for (Node* trav2 = trav1->next; trav2 != NULL; trav2 = trav2->next) {
            if (trav1->Adventurer.gearscore > trav2->Adventurer.gearscore) {
                temp = trav1->Adventurer.gearscore;
                trav1->Adventurer.gearscore = trav2->Adventurer.gearscore;
                trav2->Adventurer.gearscore = temp;
            }
        }
    }
}
