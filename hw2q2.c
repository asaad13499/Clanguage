/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
#define NUM_UNIT 10 /* NUMBER OF ARMY UNITS */


/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/

void print_warriors_details();
void print_army_size(int size);
void print_biggest_platoon_and_size(int index, int size);
void print_active_platoons_and_avg(int size, double avg);
void print_show_army();
void print_number(int num);
void print_enter();
void print_star();
void print_space();

int main()
{
    int N, details = 0, demand = 0, size = 0, total = 0, i = 0;
    int max = 0, k = 0;
    int UNIT_SIZE[NUM_UNIT] = {0};
    int star[NUM_UNIT] = {0};
    print_warriors_details();

    while(scanf(" %d", &details) != EOF){
        if(details < 5){
            demand = details;
            break;
        } else {
            while(details > 0) {// takes demand
                total = details%10 + total;
                details = details/10;
            }
            UNIT_SIZE[total%10]++;//add SOLDIER to UNIT
            star[total%10]++;
            size = size + 1;
            total = 0;
        }
    }

    switch(demand) {
        case 1: print_army_size(size); break;
        case 2:
            max = UNIT_SIZE[0];
            for (i = 0; i < 10; i++){
                if(UNIT_SIZE[i] > 0) {// Avoiding Un-necessary math
                    for (N = 1; N < 10; N++) {//Running from index 1 to 9
                        if(UNIT_SIZE[N] > max){// Comparing the current max with the indexes
                            max = UNIT_SIZE[N];
                            k = N;
                        } else if(UNIT_SIZE[N] == max) {
                            max = max;
                            k = N;
                        }
                    }
                }
            }
            if (max == 0)
                print_biggest_platoon_and_size(9, max);
            else
                print_biggest_platoon_and_size(k, max);
            break;
        case 3:
            for ( i = 0; i < 10; i++){
                if(UNIT_SIZE[i] > 0){
                    max = max + UNIT_SIZE[i];
                    k++;
                }
            }
            if(k == 0)
                print_active_platoons_and_avg(0, 0);
            else
                print_active_platoons_and_avg(k, (double)max/k);
            break;
        case 4:
            print_show_army();
            for(i = 0; i < 10; i++)
                print_number(i);
            print_enter();
            for(N = 0; N < NUM_UNIT; N++){//Checking all Units
                    while(star[N] > 0) {//Checking if the unit has any soldiers
                        for(i = 0; i < 10; i++){
                            if(star[i] > 0){
                            print_star();
                            star[i]--;
                            } else {
                            print_space();
                            }
                        }
                        print_enter();
                    }

            }
            break;
        default: break;
    }

	return 0;
}

void print_warriors_details(){
	printf("Enter warriors id and demand at the end:\n\n");
}

void print_army_size(int size){
	printf("The army size is: %d\n", size);
}

void print_biggest_platoon_and_size(int index, int size){
	printf("The biggest platoon index is: %d and its size is: %d\n", index, size);
}

void print_active_platoons_and_avg(int size, double avg){
	printf("There are %d active platoons \n\nThe avg size of a platoon is: %.2f\n", size, avg);
}

void print_show_army(){
	printf("Show army!\n\n");
}

void print_number(int num){
	printf("%d", num);
}

void print_enter(){
	printf("\n");
}

void print_star(){
	printf("*");
}

void print_space(){
	printf(" ");
}
