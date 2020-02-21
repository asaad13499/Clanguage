/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/



/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{

unsigned long int c = 0;
printf("Enter an encoded word and I'll do my best: \n");
scanf(" %10lu", &c);
unsigned long int newc = 0;
char q = 0;
while (c > 0) {
    newc = newc*10 + c%10;
    c = c/10;
}
if( (newc % 1000) > 96 && (newc % 1000) < 100) {
printf("The decoded word is: ");
while (newc > 0){
    if( (newc % 1000) > 96 && (newc % 1000) < 100) {
        q = (newc % 1000);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
    }
        newc = newc / 100;
    } else if( (newc % 1000) > 99 && (newc% 1000) < 123) {
        q = (newc % 1000);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
    }
        newc = newc / 1000;
    } else if( (newc % 1000) > 122) {
        q = (newc % 100);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
        }
        newc = newc/100;
    } else {
        newc = newc /100;
    }
}
printf("\nDone and even had time for coffee :)");
}else if( (newc % 1000) > 99 && (newc% 1000) < 123)  {
printf("The decoded word is: ");
while (newc > 0){
    if( (newc % 1000) > 96 && (newc % 1000) < 100) {
        q = (newc % 1000);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
    }
        newc = newc / 100;
    } else if( (newc % 1000) > 99 && (newc% 1000) < 123) {
        q = (newc % 1000);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
    }
        newc = newc / 1000;
    } else if( (newc % 1000) > 122) {
        q = (newc % 100);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
        }
        newc = newc/100;
    } else {
        newc = newc /100;
    }
}
printf("\nDone and even had time for coffee :)");
}else if( (newc % 1000) > 122 && (newc%100) > 96) {
    printf("The decoded word is: ");
while (newc > 0){
    if( (newc % 1000) > 96 && (newc % 1000) < 100) {
        q = (newc % 1000);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
    }
        newc = newc / 100;
    } else if( (newc % 1000) > 99 && (newc% 1000) < 123) {
        q = (newc % 1000);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
    }
        newc = newc / 1000;
    } else if( (newc % 1000) > 122) {
        q = (newc % 100);
        if (q < 96 || q > 122){
            newc = 0;
        }
        if( (q - 'a') > -1 && (q-'a') < 26){
        if( (q%2) == 0){
        q = q - 'a';
        q = q + 'A';
        printf("%c", q);
        } else {
        printf("%c", q);
        }
        }
        newc = newc/100;
    } else {
        newc = newc /100;
    }
}
printf("\nDone and even had time for coffee :)");
} else {
printf("\nThere is nothing there :(");
}




}
