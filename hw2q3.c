/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define MAX_MAT 25 // matrix's max number of lines and rows

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/

void print_enter_matrix_size();
void print_enter_first_matrix();
void print_enter_second_matrix();
void print_invalid_input();
void print_enter_required_operation();
void print_number(int number);
void print_enter();

int main()
{
    int SIZE, ROW, LINE, TOTAL, N;// N : Number of rows/lines for the multiplcation
    int first[MAX_MAT][MAX_MAT], second[MAX_MAT][MAX_MAT], RESULT[MAX_MAT][MAX_MAT];
    char OPERATION;
    print_enter_matrix_size();
    scanf(" %d", &SIZE);
    print_enter_first_matrix();
    for(ROW = 0; ROW < SIZE; ROW++) {
            for(LINE = 0; LINE < SIZE; LINE++){
                if(scanf(" %d", &first[ROW][LINE]) == 1);//Checking if the user inserting allowed input
                else{
                    print_invalid_input();
                    return 0;
                }
            }
    }
    print_enter_second_matrix();
    for(ROW = 0; ROW < SIZE; ROW++) {
            for(LINE = 0; LINE < SIZE; LINE++){
                if(scanf(" %d", &second[ROW][LINE]) ==1);
                else {
                    print_invalid_input();
                    return 0;
                }
            }
    }
    print_enter_required_operation();
    scanf(" %c", &OPERATION);
    switch(OPERATION){
        case '+':
            for (ROW = 0; ROW < SIZE ; ROW++ ){//Looping Rows
                for(LINE = 0; LINE < SIZE; LINE++){//Looping lines
                    RESULT[ROW][LINE] = first[ROW][LINE] + second[ROW][LINE];//Applying the operation
                    print_number(RESULT[ROW][LINE]);
                }
                if( LINE == SIZE){//To make the result in Matrix shape
                    print_enter();
                }
            }
            break;
        case '*':
            for (ROW = 0; ROW < SIZE ; ROW++ ){
                for(LINE = 0; LINE < SIZE; LINE++){
                    for(N = 0; N < SIZE; N++){
                        TOTAL = TOTAL + first[ROW][N]*second[N][LINE];//Applying the operation and saving in TOTAL
                    }
                    RESULT[ROW][LINE] = TOTAL; //Adding Result in its place
                    print_number(RESULT[ROW][LINE]);// Printing Result
                    TOTAL = 0;
                }
                if(LINE == SIZE){//Shaping Result into Matrix
                    print_enter();
                }
            }
            break;
        default: print_invalid_input(); break;
    }
    return 0;
}

void print_enter_matrix_size(){
	printf("Please enter the matrix size:\n");
}

void print_enter_first_matrix(){
	printf("Please enter the first matrix:\n");
}

void print_enter_second_matrix(){
	printf("Please enter the second matrix:\n");
}

void print_invalid_input(){
	printf("Invalid input.");
}

void print_enter_required_operation(){
	printf("Please enter the required operation:\n");
}

void print_number(int number){
	printf("%d ", number);
}

void print_enter(){
	printf("\n");
}
