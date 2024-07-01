#include <stdio.h>

// add your structure here
typedef struct plane{
    int x, y;
} Plane;

// add your function prototypes here
Plane createPoint(int, int);
int identifyPoint();
void displayPoint(int, int);

void main() {
    int x, y;

    printf("Enter x - coordinate: ");
    scanf("%d", &x);
    printf("Enter y - coordinate: ");
    scanf("%d", &y);

    //insert code here
    Plane plane = createPoint(x, y);
    displayPoint(x, y);
    switch(identifyPoint(plane)){
        case 0: 
            printf("Origin.");
            break;
        case 1: 
            printf("Q1.");
            break;
        case 2: 
            printf("Q2.");
            break;  
        case 3: 
            printf("Q3.");
            break;
        case 4: 
            printf("Q4.");
            break;
        case 5:
            printf("x-axis.");
            break;
        case 6: 
            printf("y-axis.");
            break;
    }
}

// add your function definitions here
Plane createPoint(int x, int y){
    Plane temp = {x, y};
    return temp;
}

void displayPoint(int x, int y){
    printf("The point (%d, %d) is in ", x, y);
}

int identifyPoint(Plane plane){
    if(plane.x == 0 && plane.y == 0){
        return 0;
    } else if(plane.x > 0 && plane.y > 0){
        return 1;
    } else if(plane.x < 0 && plane.y > 0){
        return 2;
    } else if(plane.x < 0 && plane.y < 0){
        return 3;
    } else if(plane.x > 0 && plane.y < 0){
        return 4;
    } else if(plane.x != 0 && plane.y == 0){
        return 5;
    } else if(plane.x == 0 && plane.y != 0){
        return 6;
    }
}