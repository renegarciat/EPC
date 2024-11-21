#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct testData {
    char *testString;
    int expectedTestResult;
} testData_t;

/*Macros*/
#define SIZEARRAY 6
#define STACK_SIZE 100

/*Function prototypes*/
int testRun(testData_t testData);
bool isValid(char* s);
void _updateToBeClosed(char c);
void stack_push(char c);
char stack_pop();
char stack_peek();

/*Global variables*/
char _toBeClosed = '\n';
char stack[STACK_SIZE] ={0};
int stackIndex = -1;
int testStatus = EXIT_SUCCESS;

/*Main*/
int main(int argc, char const *argv[]){
    testData_t myTestData [SIZEARRAY] = {
    {"()",true},
    {"()[]{}",true},
    {"([])",true},
    {"(]",false},
    {"()[]{}[{]}",false},
    {"(1)+[(2)(3)]-{([]}",false}};

    for (size_t i = 0; i < SIZEARRAY; i++){
    testStatus |= testRun(myTestData[i]);
    }
    if (testStatus) printf("At least 1 test failed! \n");
    return testStatus;
}


/// @brief 
/// @return 0 for success, 1 for failed.
int testRun(testData_t testData){
    char* testString = testData.testString;
    bool ret = isValid(testString);
    if (ret == testData.expectedTestResult){
        printf("\tTest passed\n");
        return EXIT_SUCCESS;
    }
    else {
        printf("\tTest failed\n");
        return EXIT_FAILURE;
    }
}
bool isValid(char* s){
    stackIndex = -1;
    /** Iterate over the string and have a counter for each of the three separators.
     * ( + 1
     * ) - 1
     * [ + 1
     * ] - 1
     * { + 1
     * } - 1
    */
   int parentheses = 0;
   int brackets = 0;
   int braces = 0;
    //If any value goes to 0 before function termination, fail
    // null chaising loop
    size_t i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        switch (s[i]){
        case '(':
            parentheses++;
            stack_push(s[i]);
            i++;
            continue;
        case '[':
            brackets++;
            stack_push(s[i]);
            i++;
            continue;
        case '{':
            braces++;
            stack_push(s[i]);
            i++;
            continue;
        default:
            break;
        }
        switch (s[i]){
            case ')':
                if (')' == stack_peek()){
                    stack_pop();
                    parentheses--;
                    break;
                }
                else {
                    return false;
                }
            case ']':
                if (']' == stack_peek()){
                    stack_pop();
                    brackets--;
                    break;
                }
                else {
                    return false;
                }
            case '}':
                if ('}' == stack_peek()){
                    stack_pop();
                    braces--;
                    break;
                }
                else {
                    return false;
                }
            default: //The character is not in the expected data set. Continue.
                break;
            }
        i++;
        if (parentheses < 0 || brackets < 0 || braces < 0) return false; // Early termination if any number becomes less than 0.
    }
   //After loop execution, all values should be equal to 0
    if (parentheses || brackets || braces){
        return false;
    } else {
   return true;
    }
}

/*Actually pushes the closing brace when the open one is passed as parameter*/
void stack_push(char c){
    stackIndex++;
    if (stackIndex >= STACK_SIZE){
        printf("Stack full!");
        exit(EXIT_FAILURE);
    }
    else {
        switch (c){
        case '(':
            stack[stackIndex] = ')';
            break;
        case '[':
            stack[stackIndex] = ']';
            break;
        case '{':
            stack[stackIndex] = '}';
            break;
        default:
            break;
        }
    }
    return;
}

char stack_pop(void){
    char temp = stack_peek();
    if (stackIndex < 0){ //stack empty!
        printf("Stack empty!");
        exit(EXIT_FAILURE);
    }
    else{
        stackIndex--;
        return temp;
    }
}

char stack_peek(void){
    if (stackIndex < 0){ //stack empty!
    printf("Stack empty!");
    exit(EXIT_FAILURE);
    }
    else{
        return stack[stackIndex];
    }
}