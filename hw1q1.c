#include <stdio.h>

int main()
{
    char c = 0; int res = 0;
    printf("Please enter the letter C for calculating CheckDigit and the letter V for validating an ID by its CheckDigit:\n");
    scanf(" %c", &c);
    switch(c){
    case 'c': res = 1; break;
    case 'C': res = 1; break;
    case 'V': res = 2; break;
    case 'v': res = 2; break;
    default: printf("\nERROR"); break;
    }
    if(res == 1){
        int id = -1, id1 = -1, id2 =-1, id3= -1, id4 = -1, id5 =-1, id6 = -1, id7 = -1;
        printf("\nCalculating CheckDigit, please enter 8 digits:\n");
        if(scanf(" %1d%1d%1d%1d%1d%1d%1d%1d", &id, &id1, &id2, &id3, &id4, &id5, &id6, &id7) !=8) {
            printf("\nERROR");
            return 0;
        } else {
            int num1 = id;
            int num2 = id1;
            num2 = num2 * 2;
            if(num2 > 10){
                num2 = (num2%10) + 1;
            }
            int num3 = id2;
            int num4 = id3;
            num4 = num4 * 2;
            if(num4 > 10) {
                num4 = (num4%10) + 1;
            }
            int num5 = id4;
            int num6 = id5;
            num6 = num6 * 2;
            if(num6 > 10) {
                num6 = (num6%10) + 1;
            }
            int num7 = id6;
            int num8 = id7;
            num8 = num8 * 2;
            if(num8 > 10){
                num8 = (num8%10) + 1;
            }
            int sum = num1+num2+num3+num4+num5+num6+num7+num8;
            if (sum < 130) {
                sum = sum % 10;
                if (sum > 0){
                sum = 10 - sum;
                } else {
                    sum = sum;
                }
                printf("\nCheckDigit = %d\n", sum);
            } else if (sum <= 10){
                if (sum > 0){
                sum = 10 - sum;
                } else {
                    sum = sum;
                }
                printf("\nCheckDigit = %d\n", sum);
            }
        }
    } else if(res == 2){
        printf("\nValidating ID, please enter 9 digits ID:\n");
        int id = -1, id1 = -1, id2 =-1, id3= -1, id4 = -1, id5 =-1, id6 = -1, id7 = -1, id8 = -1;
        if(scanf(" %1d%1d%1d%1d%1d%1d%1d%1d%1d", &id, &id1, &id2, &id3, &id4, &id5, &id6, &id7, &id8) != 9) {
            printf("\nERROR");
            return 0;
        } else {
        int numc = id8;
        int num1 = id;
            int num2 = id1;
            num2 = num2 * 2;
            if(num2 > 10){
                num2 = (num2%10) + 1;
            }
            int num3 = id2;
            int num4 = id3;
            num4 = num4 * 2;
            if(num4 > 10) {
                num4 = (num4%10) + 1;
            }
            int num5 = id4;
            int num6 = id5;
            num6 = num6 * 2;
            if(num6 > 10) {
                num6 = (num6%10) + 1;
            }
            int num7 = id6;
            int num8 = id7;
            num8 = num8 * 2;
            if(num8 > 10){
                num8 = (num8%10) + 1;
            }
            int sum = num1+num2+num3+num4+num5+num6+num7+num8;
            printf("\nYou have entered CheckDigit = %d\n", numc);
            if (sum < 130) {
                sum = sum % 10;
                if (sum > 0){
                sum = 10 - sum;
                } else {
                    sum = sum;
                }
                printf("Calculated CheckDigit = %d\n\n", sum);
            } else if (sum <= 10){
                if (sum > 0){
                sum = 10 - sum;
                } else {
                    sum = sum;
                }
                printf("Calculated CheckDigit =%d\n\n", sum);
            }
            if (numc == sum) {
                printf("Legal ID :)");
            } else {
                printf("Illegal ID :(");
            }

    }
    }
    }



