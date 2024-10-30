// write a function that accepts a positive integer between 0 and 999 inclusive and returns a string representation of that integer written in English
#include <stdio.h>
#include <string.h>



int main() {
    const char* ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    const char* teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    const char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    const char* hundreds[] = {"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};

    int pos_int;
    char result[100] = "";                 // hold the complete string

    printf("Enter a positive integer between 0 and 999 inclusive: ", pos_int);
    scanf("\n%d", &pos_int);
    
    // ensures pos_int stays within its range 0-999
    if (pos_int < 0 || pos_int > 999) {
        printf("Invalid Number!\n");
    }
    
    // int to string conversion from 0-9
    if (pos_int < 10){
        printf("String representation of %d is: %s\n", pos_int, ones[pos_int]);
        return 1;
    }

    else if (pos_int < 20){
        printf("String representation of %d is: %s\n", pos_int, teens[pos_int - 10]);
        return 2;
    }

    else if (pos_int <= 99 && pos_int >= 20){
        int tens_digit = pos_int / 10;
        strcat(result, tens[tens_digit]);
        pos_int %= 10;      //getting the ones part alone

        if (pos_int < 10){
            strcat(result, " ");
            strcat(result, ones[pos_int]);
        }

        printf("String representation of the number is: %s\n", result);
        return 3;
    }

    if (pos_int >= 100 && pos_int <= 999) {
        int hundreds_digit = pos_int / 100;
        strcat(result, hundreds[hundreds_digit]);
        pos_int %= 100;

        if(pos_int > 0){
            strcat(result, " ");

            if (pos_int < 10){
                strcat(result, ones[pos_int]);
            } else if (pos_int < 20){
                strcat(result, teens[pos_int - 10]);
            } else {
                int tens_digit = pos_int / 10;
                strcat(result, tens[tens_digit]);
                pos_int %= 10;

                if (pos_int < 10){
                    strcat(result, " ");
                    strcat(result, ones[pos_int]);
                }
            }
        }
    printf("String representation of the number is: %s\n", result);
    }
    
    return 0;
}