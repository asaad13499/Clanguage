/*-------------------------------------------------------------------------
    Include files:
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>

/*-------------------------------------------------------------------------
    Constants and definitions:
-------------------------------------------------------------------------*/
#define N 11
#define P1_MOVE 'X'
#define P2_MOVE 'O'
#define EMPTY '_'
#define MIN_UNDO -1
#define PNUM 3

/*-------------------------------------------------------------------------
    Function declaration
-------------------------------------------------------------------------*/
void print_welcome();
void print_enter_board_size();
void print_board(char board[N][N], int n);
void print_player_turn(int player_index);
void print_error();
void print_winner(int player_index);
void print_tie();
void launch();
void Do(char board[N][N], int R, int L,int lastRM[N*N],int lastLM[N*N],int *move2, int *turn2,int move,int PMove);
void UnDo(char board[N][N],int lastRM[N*N],int lastLM[N*N],int *move2,int *turn,int move, int R);
void launch2(char board[N][N], int i, int turn);
int HorizontalWin(char board[N][N],int size);
int VerticalWin(char board[N][N],int size);
int Diagonal1(char board[N][N], int n);
int Diagonal2(char board[N][N], int n);
void movechange2(int *move, int *turn, bool plus);//Increasing/Decreasing Move Counter
void game(char board[N][N],int turn,int *turn2,int *success,int lastRM[N*N],int lastLM[N*N],int *move2,int move,int PMove, int i);
void after_check(char board[N][N],int turn, int *success,int move, int i);
int check_move(int R, int L, char board[N][N], int move);
void won(int *success);

/*-------------------------------------------------------------------------
    Implementation
-------------------------------------------------------------------------*/

//launching the game
//12 lines
int main(){
    char board[N][N] = {{0}} ;
    int lastR[N*N] = {0}, lastL[N*N] = {0};
    int i = 0, turn = 1, move = 0, success = 0;
    launch();
    if(scanf("%d", &i) == 1){
        launch2(board, i, turn);
            while(success < 1){
                int PMove = (turn == 1) ? P1_MOVE : P2_MOVE;
                game(board, turn, &turn,&success, lastR, lastL, &move, move, PMove, i);
                if(move == (i*i) && success != 1){
                    print_tie();
                    break;
                }
            }
    }

}


//Increasing/Decreasing move counter
//5 Lines
void movechange2(int *move, int *turn, bool plus){
    if(plus){
    *move += 1;
    } else {
    *move -= 1;
    }
    *turn = PNUM - *turn;
}

//Increasing success counter
//1 Line
void won(int *success){
    *success += 1;
}

//Checking Win / Tie Situations and printing according to it
//8 Lines
void check_win(char board[N][N], int i, int turn, int *success, int move){
    if(HorizontalWin(board,i) || VerticalWin(board, i) || Diagonal1(board, i) || Diagonal2(board, i)){
                won(success);
                print_board(board, i);
                print_winner(turn);
            } else if(move == (i*i)-1){
                print_board(board, i);
            }else{
                launch2(board, i, turn);
            }
}


// launching the game it self
// 11 Lines
void game(char board[N][N],int turn, int *turn2,int *success,int lastRM[N*N],int lastLM[N*N],int *move2,int move,int PMove, int i){
    int R = 0, L = 0;
    if(scanf("%d", &R) == 1 && R >= 0 && scanf("%d", &L) == 1){
        if(check_move(R, L, board, move) == 1){
            Do(board, R, L, lastRM, lastLM, move2, turn2, move, PMove);
            after_check(board, turn, success, move, i);
        } else {
            print_error();
        }
    } else if(check_move(R, L, board, move) == 1 && R < 0 && move >= -R){
        UnDo(board, lastRM,lastLM,move2,turn2,move,R);
        turn = PNUM - turn;
        launch2(board, i, turn);
    }

}

//Functions assumption
//2 Lines
void after_check(char board[N][N],int turn, int *success,int move, int i){
    turn = PNUM - turn;
    check_win(board,i,turn,success, move);
}

 //For printing
 // 2 Lines
void launch2(char board[N][N], int i,int turn){
    print_board(board, i);
    print_player_turn(turn);

}

//First Prints
// 2 Lines
void launch(){
    print_welcome();
    print_enter_board_size();

}

//Checks if the entered input is allowed or not
//10 Lines
int check_move(int R, int L, char board[N][N], int move){
    if(R >= 0 && L >= 0){
        if(board[R-1][L-1] == EMPTY){
            return 1;
        } else {
            return 0;
        }
    } else if(R < 0){
        if(R%2 == 0 || -R > move){
            print_error();
            return 0;
        }
        else return 1;
    }
    return 0;
}

//Inserting the Player move into the appropiate place in the board
//5 Lines
void Do(char board[N][N], int R, int L,int lastRM[N*N],int lastLM[N*N],int *move2,int *turn2,int move,int PMove){
        bool plus = true;
        board[R-1][L-1] = PMove;
        lastRM[move] = R;//Saving the move to use it with Undo
        lastLM[move] = L;//Saving the move to use it with Undo
        movechange2(move2, turn2, plus);
}

//Removing the player Move
// 13 Lines
void UnDo(char board[N][N],int lastRM[N*N],int lastLM[N*N],int *move2,int *turn2,int move, int R){
    bool plus = false;
    if(move > 0){
        if( R < MIN_UNDO){
            for(int i = 1; i <= -R; i++){
                int A = lastRM[move-i];
                int B = lastLM[move-i];
                board[A-1][B-1] = EMPTY;
                movechange2(move2, turn2, plus);
            }
        } else {
            int A = lastRM[move+R];
            int B = lastLM[move+R];
            board[A-1][B-1] = EMPTY;
            movechange2(move2, turn2, plus);
        }
    }
}



//Checks a Diagonal Win
//10 Lines
int Diagonal1(char board[N][N], int n){
    int won = 1, i = 0, k = n-1;
    if(board[k][i] != EMPTY){
        for(int j = 1; j < n; j++){
            if(board[k][i] != board[k-j][i+j]){
                break;
            } else {
                won += 1;
            }
        }
   }
   if(won == n){
    return 1;
   }
   return 0;
}

//Checking the other Diagonal win
//10 Lines
int Diagonal2(char board[N][N], int n) {
   int won = 1, i = 0;
   if(board[i][i] != EMPTY){
        for(int j = 1; j < n; j++){
            if(board[i][i] != board[j][j]){
                break;
            } else {
                won += 1;
            }
        }
   }
   if(won == n){
    return 1;
   }
   return 0;
}

//Checks Vertical Win
//12 Lines
int VerticalWin(char board[N][N],int n)
{
    int won = 0;
    for (int k = 0; k < n; k++){
        if(board[k][k] != EMPTY){
            for(int j = 0; j < n; j++){
                if(board[k][k] != board[j][k]){
                    won = 0;
                    break;
                } else {
                    won += 1;
                }
            }
        }
    }
    if(won == n){
        return 1;
    }
    return 0;
}

//Checks Horizontal Win
//12 Lines
int HorizontalWin(char board[N][N],int n)
{
    int won = 0, i = 0;
    for (int k = 0; k < n; k++){
        if(board[k][i] != EMPTY){
            for(int j = 0; j < n; j++){
                if(board[k][i] != board[k][j]){
                    won = 0;
                    break;
                } else {
                    won += 1;
                }
            }
            if(won == n){ // By the end of the columns loop, check win in row
                return 1;
            }
        }
    }
    return 0;
}



//print welcome message
//1 lines
void print_welcome()
{
    printf("*** Welcome to AVOIDANCE TIC-TAC-TOE game ***\n\n");
}

//print message to enter board size
//1 lines
void print_enter_board_size()
{
    printf("Please enter board size (1 to %d):\n", N);
}

//print the board
//10 lines
void print_board(char board[N][N], int n)
{
    printf("\nCurrent board:\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
        {
            if(!board[i][j]) {
             printf("%c|", EMPTY);
             board[i][j] = EMPTY;
            } else {
            printf("%c|", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

//print a request for player with index "player_index" to move
//1 lines
void print_player_turn(int player_index)
{
    printf("\nPlayer ** %d **, enter next move:\n", player_index);
}

//print error message
//1 lines
void print_error()
{
    printf("Illegal move!!!, please try again:\n");
}

//print the winner
//1 lines
void print_winner(int player_index)
{
    printf("Player %d Wins! Hooray!\n", player_index);
}

//print message to announce there is a tie (no one wins)
//1 lines
void print_tie()
{
    printf("It's a tie!\n");
}
