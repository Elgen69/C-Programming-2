#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 20

bool isBalancedParentheses(char str[]) {
    int len = strlen(str);
    char stack[MAX_LENGTH];
    int top = -1;
    for(int i = 0; i < len; i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(top < 0) {
                return false;
            }
            char bracket = stack[top--];
            if((str[i] == ')' && bracket != '(') ||
               (str[i] == '}' && bracket != '{') ||
               (str[i] == ']' && bracket != '[')) {
                return false;
            }
        }
    }
    return top < 0;
}

int main() {
    char testCases[3][MAX_LENGTH] = {
        "([{}])",    // Balanced
        "{[(]}",     // Not balanced
        "{}{}([",    // Not Balanced
    };

    for(int i = 0; i < 3; i++) {
        printf("Test case %d: %s\n", i + 1, testCases[i]);
        if(isBalancedParentheses(testCases[i])) {
            printf("The parentheses are balanced!\n\n");
        } else {
            printf("The parentheses are not balanced!\n\n");
        }
    }

    return 0;
}
