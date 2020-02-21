/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define WORD_END '!'
#define C_CONDITION 's'
#define C_NUM_CONDITION 6
#define A_NUM_CONDITION 4

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/

int print_enter_enemy_name();
int print_dragonA_sent();
int print_dragonB_sent();
int print_dragonC_sent();
int print_no_dragon_sent();
void send_dragon();

int main()
{
	char enemy_name;
    print_enter_enemy_name();
    scanf(" %c", &enemy_name);
    int s = 0, i = 0, total = 0, sdra = 0, check = 0;
    while( enemy_name != WORD_END) {
        if(enemy_name == C_CONDITION){
            s = C_CONDITION;
        }
        if (enemy_name > sdra) {
            check = check + 1;
        }
        i = i + 1;
        sdra = enemy_name;
        total = total + enemy_name;
        scanf(" %c", &enemy_name);
    }
    send_dragon(total, check, s, i);

    return 0;
}

void send_dragon(int total, int check_B, int check_C, int NUM){
    int A_CONDITION = (total%5);
    if(check_C != C_CONDITION && NUM < C_NUM_CONDITION){
        print_dragonC_sent();
    } else if( check_B == NUM){
        print_dragonB_sent();
    } else if(  A_CONDITION != 0 || NUM > A_NUM_CONDITION) {
        print_dragonA_sent();
    } else {
        print_no_dragon_sent();
    }
}

int print_enter_enemy_name(){
	return printf("Please enter enemy name:\n");
}

int print_dragonA_sent(){
	return printf("\nKhalisi sent dragonA into the battle!!!\n");
}

int print_dragonB_sent(){
	return printf("\nKhalisi sent dragonB into the battle!!!\n");
}

int print_dragonC_sent(){
	return printf("\nKhalisi sent dragonC into the battle!!!\n");
}

int print_no_dragon_sent(){
	return printf("\nNO Dragon has been sent into the battle!!!\n");
}
