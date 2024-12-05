#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void printArray(int array[9]){
    int arraySize = 9;
    for(int i = 0; i < arraySize; i++){
        printf("Element at index %d: %i\n", i, array[i]);
    }
}

void printBoard(char** pointerToCharPointerarray){
    printf("Board:\n");
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%c ", **(pointerToCharPointerarray + j + (i*9)));
        }
        printf("\n");
    }
}

bool evalLine(char board[9]){
    int digitCounter[9] = { 0 };
    int arraySize = 0;
    for(int i = 0; i < 9; i++){
        if (!(board[i] == '.')){
            int index = board[i] - '0' - 1;
            digitCounter[index]++;
        }
    }

    for(int i = 0; i < 9; i++){
        if(digitCounter[i] > 1){
            return false;
        }
    }

    return true;
}

bool isValidSudoku(char** board) {
    char charBoard[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            charBoard[i][j] = **(board + j + (i*9));
        }   
    }

    // Evaluate lines
    for(int i = 0; i < 9; i++){
        if(!(evalLine(charBoard[i])))
            return false;
    }

    // Evaluate columns
    for(int i = 0; i < 9; i++){
        char column[9];
        for(int j = 0; j < 9; j++){ // Create column
            column[j] = charBoard[j][i];
        }
        if(!(evalLine(column)))
            return false;
    }

    // Evaluate squares
    for(int i = 0; i < 9; i++){
        char square[9];
        int index = 0;
        for(int j = i / 3 * 3; j < i / 3 * 3 + 3; j++){ // Create squares
            for(int k = i % 3 * 3; k < i % 3 * 3 + 3; k++){
                //printf("(%d, %d) ", j, k);
                square[index] = charBoard[j][k];
                index++;
            }
        }
        if(!(evalLine(square)))
            return false;
    }
    return true;
}

int main(){
        
    char** board[9][9] = {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
        };

    printBoard(board);

    if (isValidSudoku(board)){
        printf("The board is valid.");
    }else{
        printf("The board is not valid.");
    }

    return 0;
}
