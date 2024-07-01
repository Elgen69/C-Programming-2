#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
typedef struct{
    char title[15];
    char author[10];
    char genre[10];
    int pubyear;
}Book;

Book* Library[MAX_BOOKS]; 
int numBooks = 0;

void addBooks();
void dispBooks();
void titBooks(char*);
void pubYear(int);

int main(void){
    char title[100];
    int year;
    int choice;
    
    do{
        printf("\n====== Library Management System ======\n");
        printf("1. Add a new book\n");
        printf("2. Display all books\n");
        printf("3. Search for a book by title\n");
        printf("4. Search for books published in a specific year\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d", &choice);
        
        switch(choice){
            case 1:
                addBooks();
                break;
            case 2:
                dispBooks();
                break;
            case 3:
                printf("Enter title of book: ");
                scanf(" %[^\n]", title);
                titBooks(title);
                break;
            case 4:
                printf("Enter publication year to search: ");
                scanf("%d", &year);
                pubYear(year);
                break;
            case 5:
                printf("Exiting the program...");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
            }
        }while(choice != 5);
        for(int i = 0; i < numBooks; i++) free(Library[i]);
    }

void addBooks(){
    if(numBooks<MAX_BOOKS){
        Library[numBooks] = malloc(sizeof(Book));
        printf("Enter title of book: ");
        scanf(" %[^\b]", Library[numBooks]->title);
        printf("Enter author of book: ");
        scanf(" %[^\b]", Library[numBooks]->author);
        printf("Enter genre of book: ");
        scanf(" %[^\b]", Library[numBooks]->genre);
        printf("Enter publication year of book: ");
        scanf("%d", &Library[numBooks]->pubyear);
        numBooks++;
        printf("Book added successfully.\n");
    }else printf("Library is full\n");
}

void dispBooks(){
    if(numBooks == 0) printf("Library is empty.\n"); return;
    for(int i = 0; i < numBooks; i++){
        printf("Title: %s\n", Library[numBooks]->title);
        printf("Author: %s\n", Library[numBooks]->author);
        printf("Genre: %s\n", Library[numBooks]->genre);
        printf("Publication Year: %d\n\n", Library[numBooks]->pubyear);
    }
}
void titBooks(char * title){
    int found = 0;
    for(int i = 0; i < numBooks; i++){
        if(strcmp(Library[i]->title, title) == 0){
            printf("\nBook Found\n");
            printf("Title: %s\n", Library[numBooks]->title);
            printf("Author: %s\n", Library[numBooks]->author);
            printf("Genre: %s\n", Library[numBooks]->genre);
            printf("Publication Year: %d\n\n", Library[numBooks]->pubyear);
            found = 1;
            break;
        }
    }
    if(!found) printf("Book not found");
}
void pubYear(int year){
     int found = 0;
     for(int i = 0; i < numBooks; i++){
         if(Library[i]->pubyear==year) printf("Books published in year %d: \n", year);
         printf("Title: %s\n", Library[numBooks]->title);
            printf("Author: %s\n", Library[numBooks]->author);
            printf("Genre: %s\n", Library[numBooks]->genre);
            printf("Publication Year: %d\n\n", Library[numBooks]->pubyear);
            found = 1;
     }
     if(!found) printf("No Books found for the year");
}

