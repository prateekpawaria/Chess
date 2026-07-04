#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Chessboard representation
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Function to display the chessboard
void displayBoard() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid (very basic)
int isValidMove(int startRow, int startCol, int endRow, int endCol) {
    // Basic bounds check
    if (startRow < 0 || startRow > 7 || startCol < 0 || startCol > 7 ||
        endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7) {
        return 0; // Invalid if out of bounds
    }

    // Very basic example: No piece can move to its current position
    if (startRow == endRow && startCol == endCol) {
        return 0;
    }

    if(board[startRow][startCol]=='B' || board[startRow][startCol]=='b'){
        if(board[startRow][startCol]=='b'){
            if (board[endRow][endCol]>'a' && board[endRow][endCol]<'s'){
                return 0;
            }
        }
        else{
            if (board[endRow][endCol]>'A' && board[endRow][endCol]<'S'){
                return 0;
            }
        }
        if(abs(startRow-endRow)==abs(startCol-endCol)){
            int cs=(startCol>endCol) ? -1 : 1;
            int rs=(startRow>endRow) ? -1 : 1;
            for(int i=0;i<abs(startRow-endRow);i++){
                if(board[startRow + rs][startCol + cs]!=' '){
                    return 0;
                }
                (cs==1) ? cs++ : cs--;
                (rs==1) ? rs++ : rs--;
            }

        }
        else{
            return 0;
        }

    }

    if(board[startRow][startCol]=='K' || board[startRow][startCol]=='k'){
        if(board[startRow][startCol]=='K'){
            if (board[endRow][endCol]>'A' && board[endRow][endCol]<'S'){
                return 0;
            }
        }
        else{
            if (board[endRow][endCol]>'a' && board[endRow][endCol]<'s'){
                return 0;
            }
        }
        if(abs(startRow-endRow)!=1 && abs(endCol-startCol)!=1){
            return 0;
        }
    }

    if(board[startRow][startCol]=='Q' || board[startRow][startCol]=='q'){
        if(board[startRow][startCol]=='Q'){
            if (board[endRow][endCol]>'A' && board[endRow][endCol]<'S'){
                return 0;
            }
        }
        else{
            if (board[endRow][endCol]>'a' && board[endRow][endCol]<'s'){
                return 0;
            }
        }
        
        if(endRow!=startRow && startCol==endCol){
            if (startRow>endRow){
                for (int i=startRow-1;i>endRow;i--){
                    if (board[i][startCol]!= ' '){
                        return 0;
                    }
                }
            }
            else
            {
                for (int i=startRow+1;i<endRow;i++){
                    if (board[i][startCol]!= ' '){
                        return 0;
                    }
                }
            }
        }
        else if(endCol!=startCol && endRow==startRow){
            if (startCol>endCol){
                for (int i=startCol-1;i>endCol;i--){
                    if (board[startRow][i]!= ' '){
                        return 0;
                    }
                }
            }
            else
            {
                for (int i=startCol+1;i<endCol;i++){
                        if (board[i][startCol]!= ' '){
                            return 0;
                        }

                }

            }
        }
        else if(abs(startRow-endRow)==abs(startCol-endCol)){
            int cs=(startCol>endCol) ? -1 : 1;
            int rs=(startRow>endRow) ? -1 : 1;
            for(int i=0;i<abs(startRow-endRow);i++){
                if(board[startRow + rs][startCol + cs]!=' '){
                    return 0;
                }
                (cs==1) ? cs++ : cs--;
                (rs==1) ? rs++ : rs--;
            }
            
        }
        else{
            return 0;
        }
    }

    if(board[startRow][startCol]=='N' || board[startRow][startCol]=='n'){
        int variable =0;
        if(board[startRow][startCol]=='N'){
            if (board[endRow][endCol]>'A' && board[endRow][endCol]<'S'){
                return 0;
            }
        }
        else{
            if (board[endRow][endCol]>'a' && board[endRow][endCol]<'s'){
                return 0;
            }
        }
        if((abs(startRow-endRow)==1 && abs(endCol-startCol)==2) || (abs(startRow-endRow)==2 && abs(endCol-startCol)==1) ){
            variable=1;
        }
        else{
            return 0;
        }
    }

    if (board[startRow][startCol]=='R' || board[startRow][startCol]=='r'){
        // if (startRow!=endRow && endCol!=startCol){
        //     return 0;
        // }
        if(board[startRow][startCol]=='R'){
            if (board[endRow][endCol]>'A' && board[endRow][endCol]<'S'){
                return 0;
            }
        }
        else{
            if (board[endRow][endCol]>'a' && board[endRow][endCol]<'s'){
                return 0;
            }
        }
        // if (board[endRow][endCol]>'A' && board[endRow][endCol]<'S'){
        //     return 0;
        // }
        if (endRow!=startRow){
            if (startRow>endRow){
                for (int i=startRow-1;i>endRow;i--){
                    if (board[i][startCol]!= ' '){
                        return 0;
                    }
                }
            }
            else
            {
                for (int i=startRow+1;i<endRow;i++){
                    if (board[i][startCol]!= ' '){
                        return 0;
                    }
                }
            }
        }
        if (endCol!=startCol){
            if (startCol>endCol){
                for (int i=startCol-1;i>endCol;i--){
                    if (board[startRow][i]!= ' '){
                        return 0;
                    }
                }
            }
            else
            {
                for (int i=startCol+1;i<endCol;i++){
                        if (board[i][startCol]!= ' '){
                            return 0;
                        }

                }

            }
        }

    }
    if (board[startRow][startCol]=='P'){
        if ((board[startRow-1][startCol]!=' ') && (board[startRow-1][startCol-1]==' ') && (board[startRow-1][startCol+1]==' ')){
            return 0;

        }
        else if(board[startRow-1][startCol]!=' ' &&  board[startRow-1][startCol-1]!=' ' && board[startRow-1][startCol+1]==' '){
            if ((endRow!=startRow-1) || (endCol!=startCol-1)){
                return 0;
            }
        }
        else if(board[startRow-1][startCol]!=' ' &&  board[startRow-1][startCol-1]==' ' && board[startRow-1][startCol+1]!=' '){
            if ((endRow!=startRow-1) || (endCol!=startCol+1)){
                return 0;
            }
        }
        else if(board[startRow-1][startCol]!=' ' &&  board[startRow-1][startCol-1]!=' ' && board[startRow-1][startCol+1]!=' '){
            if (((endRow!=startRow-1) || (endCol!=startCol+1))&&((endRow!=startRow-1) || (endCol!=startCol-1))){
                return 0;}
        }
        else if(board[startRow-1][startCol]==' ' &&  board[startRow-1][startCol-1]!=' ' && board[startRow-1][startCol+1]!=' '){
            if (((endRow!=startRow-1) || (endCol!=startCol+1))&&((endRow!=startRow-1) || (endCol!=startCol-1))&& ((endRow!=startRow-1)|| (endCol!=startCol))){
                return 0;
            }
        }
        else if(board[startRow-1][startCol]==' ' &&  board[startRow-1][startCol-1]!=' ' && board[startRow-1][startCol+1]==' '){
            if (((endRow!=startRow-1) || (endCol!=startCol-1))&&((endRow!=startRow-1)|| (endCol!=startCol))){
                return 0;
            }
        }
        else if(board[startRow-1][startCol]==' ' &&  board[startRow-1][startCol-1]==' ' && board[startRow-1][startCol+1]==' '){
            if ((endRow!=startRow-1)|| (endCol!=startCol)){
                return 0;
            }
        }
        else if(board[startRow-1][startCol]==' ' &&  board[startRow-1][startCol-1]==' ' && board[startRow-1][startCol+1]!=' '){
            if (((endRow!=startRow-1) || (endCol!=startCol+1))&&((endRow!=startRow-1)|| (endCol!=startCol))){
                return 0;
            }
        }
    }
    if (board[startRow][startCol]=='p'){
        if ((board[startRow+1][startCol]!=' ') && (board[startRow+1][startCol-1]==' ') && (board[startRow+1][startCol+1]==' ')){
            return 0;
        }
        else if(board[startRow+1][startCol]!=' ' &&  board[startRow+1][startCol-1]!=' ' && board[startRow+1][startCol+1]==' '){
            if ((endRow!=startRow+1) || (endCol!=startCol+1)){
                return 0;
            }
        }
        else if(board[startRow+1][startCol]!=' ' &&  board[startRow+1][startCol-1]==' ' && board[startRow+1][startCol+1]!=' '){
            if ((endRow!=startRow+1) || (endCol!=startCol+1)){
                return 0;
            }
        }
        else if(board[startRow+1][startCol]!=' ' &&  board[startRow+1][startCol-1]!=' ' && board[startRow+1][startCol+1]!=' '){
            if (((endRow!=startRow+1) || (endCol!=startCol+1))&&((endRow!=startRow+1) || (endCol!=startCol-1))){
                return 0;}
        }
        else if(board[startRow+1][startCol]==' ' &&  board[startRow+1][startCol-1]!=' ' && board[startRow+1][startCol+1]!=' '){
            if (((endRow!=startRow+1) || (endCol!=startCol+1))&&((endRow!=startRow-1) || (endCol!=startCol-1))&& ((endRow!=startRow+1)|| (endCol!=startCol))){
                return 0;
            }
        }
        else if(board[startRow+1][startCol]==' ' &&  board[startRow+1][startCol-1]!=' ' && board[startRow+1][startCol+1]==' '){
            if (((endRow!=startRow+1) || (endCol!=startCol+1))&&((endRow!=startRow+1)|| (endCol!=startCol))){
                return 0;
            }
        }
        else if(board[startRow+1][startCol]==' ' &&  board[startRow+1][startCol-1]==' ' && board[startRow+1][startCol+1]==' '){
            if ((endRow!=startRow+1)|| (endCol!=startCol)){
                return 0;
            }

        }
        else if(board[startRow+1][startCol]==' ' &&  board[startRow+1][startCol-1]==' ' && board[startRow+1][startCol+1]!=' '){
            if (((endRow!=startRow+1) || (endCol!=startCol+1))&&((endRow!=startRow+1)|| (endCol!=startCol))){
                return 0;
        }
        }
    }




    return 1; // Assume valid for now (needs more logic)
}

// Function to make a move
void makeMove(int startRow, int startCol, int endRow, int endCol) {
    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = ' ';
}

// Function to convert algebraic notation to coordinates
void algebraicToCoordinates(char *move, int *startRow, int *startCol, int *endRow, int *endCol) {
    *startCol = move[0] - 'a';
    *startRow = 7 - (move[1] - '1');
    *endCol = move[2] - 'a';
    *endRow = 7 - (move[3] - '1');
}

int main() {
    char move[5];
    int startRow, startCol, endRow, endCol;

    while (1) { // Basic game loop
        displayBoard();
        printf("Enter move (e.g., a2a4): ");
        // scanf("%s", move);

        // algebraicToCoordinates(move, &startRow, &startCol, &endRow, &endCol);

        // if (isValidMove(startRow, startCol, endRow, endCol)) {
        //     makeMove(startRow, startCol, endRow, endCol);
        // } else {
        //     printf("Invalid move!\n");
        // }
        fgets(move,sizeof(move),stdin);
        move[strcspn(move, "\n")] = 0;
        if(strcmp(move,"ress")==0){
            char initialBoard[8][8] = {
                {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
            };

            memcpy(board, initialBoard, sizeof(board)); // Reset board state
            printf("Board reset!\n");
            
        }
        else{
            algebraicToCoordinates(move, &startRow, &startCol, &endRow, &endCol);

            if (isValidMove(startRow, startCol, endRow, endCol)) {
                if(board[endRow][endCol]=='k'){
                    printf("Game over. Player 1 wins.");
                    break;
                }
                else if(board[endRow][endCol]=='K'){
                    printf("Game over. Player 2 wins");
                    break;
                }
                else{
                    makeMove(startRow, startCol, endRow, endCol);
                }
                    
            }
            else {
                printf("Invalid move!\n");
            }
        }
    }

    return 0;
}
