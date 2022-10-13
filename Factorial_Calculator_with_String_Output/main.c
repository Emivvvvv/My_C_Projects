/*
 *  Programmer: Emirhan TALA             Date completed: Oct 13, 2022
 *
 *  Calculates the factorial and saves the whole process in a string and prints it
 */

#include <stdio.h>
#include <string.h>

#define MAX_N_VALUE 9
#define MAX_STRLEN 100
#define TRUE 1
#define FALSE 0


void fact_calc(int n, char string_output[], char string_outline[]);


int main() {

    char string_output[MAX_STRLEN];     //  string output of factorial calculation
    char string_outline[MAX_STRLEN];    //  outline to string output made by '*'s

    int n;                              //  user input number to calculate factorial
    int calculator_is_on = TRUE;        //  main loop controller
    char should_continue,               //  ask user if they want to make another calculation
    clear_buffer;                       //  buffer cleaning code's trash variable.


    while(calculator_is_on){

        //  Gets the n value input from user
        printf("Welcome to the factorial calculator. Please type a number between 0 and 9.\n> ");
        do{
            scanf("%d", &n);

            //  Clears input buffer after getting the command
            do {
                clear_buffer = getchar();
            } while (clear_buffer != '\n');

            //  If input wasn't valid prints a warning message
            if (n > MAX_N_VALUE){
                printf("\n'%d' isn't a valid input. Please type a number that makes this expression true 0 <= n <= 9\n> ", n);
            }
        } while (n >= MAX_N_VALUE);    //  Loops until gets a valid input.

        //  Makes factorial calculation and returns it.
        //  Also calculations outline lenght and return it.
        fact_calc(n, string_output, string_outline);

        //  Prints factorial output to the console
        printf("\n%s\n%s\n%s\n\n", string_outline, string_output, string_outline);


        //  Checks if user want's to calculate another factorial or not. Continues the process until getting a valid data.
        printf("Do you want to make an another calculation? (y/n)\n> ");
        do{
            scanf("%c", &should_continue);

            //  Clears input buffer after getting the command
            do {
                clear_buffer = getchar();
            } while (clear_buffer != '\n');

            if (should_continue != 'y' && should_continue != 'Y' && should_continue != 'N' && should_continue != 'n'){
                printf("'%c' is not a valid input! Please type 'y' or 'n'.\n> ", should_continue);
            }

        } while (should_continue != 'y' && should_continue != 'Y' && should_continue != 'N' && should_continue != 'n');

        if (should_continue == 'n' || should_continue == 'N'){
            calculator_is_on = FALSE;
            printf("Closing the calculator...");
        }

        printf("\n\n");
    }


    return 0;
}

/*
 * Calculates the factorial of number n and returns the calculation in a string format.
 * returns the string output compatible border made by '*'s too.
 *
 * Pre: All variables must be declared.
 *      n's interval must be [0, 9]
 *
 * Post: string_output[] has the calculation and string_outline[] has the right width to cover the calculation.
 */
void
fact_calc(int n,                   // input - the number to calculate the factorial
          char string_output[],    // output - string output of the factorial calculation
          char string_outline[])   // output - string border made by '*'s for factorial calculation
{
    int iterator;
    int result = 1;
    char temp[MAX_STRLEN];

    strcpy(string_outline, "******");
    sprintf(string_output, "* %d! =", n);
    for (iterator = n; iterator != 1; iterator--){
        result *= iterator;
        sprintf(temp, " %d x", iterator);
        strcat(string_output, temp);
        strcat(string_outline, "****");
    }
    sprintf(temp, " %d = %d *", iterator, result);
    strcat(string_output, temp);
    if( n >= 7 ){
        strcat(string_outline, "*************");
    } else {
        strcat(string_outline, "**********");
    }
}
