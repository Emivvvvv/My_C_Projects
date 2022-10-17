/*
 *  Programmer: Emirhan TALA             Date completed: Oct 17, 2022
 *
 *  This program import the data file containing the names of the
 *  recommended drugs and the instructions for their administration and
 *  prints the instruction of medicine which user wanted.
 */

#include <stdio.h>
#include <string.h>

#define MAX_MEDICINE 20
#define MAX_STRLEN 200
#define TRUE 1
#define FALSE 0

void get_input_data(FILE*, char [][MAX_STRLEN], int*);
void find_medicine_and_print(char [][MAX_STRLEN],char [MAX_STRLEN], int);
void print_screen(char [MAX_STRLEN]);

int main() {
    char medicine_data[MAX_MEDICINE][MAX_STRLEN];               //  all medicine data will be saved this string array
    char user_input[MAX_STRLEN];                                //  user input to find the medicine

    int medicine_count = 0;                                     //  medicine count of the input data

    //  opens input file
    FILE* input_file;
    input_file = fopen("/Users/emivvvvv/CLionProjects/Advanced_Cardiac_LIfe_Suppport/ACLS.txt", "r");
    get_input_data(input_file, medicine_data, &medicine_count);     //  gets data from the input file and saves them medicine_data str array and saves medicine_count


    //  gets the first three letter of the user wanted medicine
    printf("WARNING: DON'T TYPE ANYTHING LONGER THAN 99 LETTERS!!!!!!!");
    printf("Enter the first 3 letter of the medicine that you want to learn how to use\n=> ");
    gets(user_input);

    //  finds the medicine if it is available in our database and prints the medicine user guide else prints couldn't find
    find_medicine_and_print(medicine_data, user_input, medicine_count);

    //  closes input file
    fclose(input_file);
    return 0;
}

/*
 * Gets all the medicine data and saves them on medicine_data string array
 * saves the medicine count to medicine_count variable
 *
 * Pre: file must be opened, all variables must be declared
 * Post: medicine_data, medicine_count
 */
void
get_input_data(FILE* input_file, char medicine_data[][MAX_STRLEN], int* medicine_count)
{
    int iterator;

    for(iterator = 0; fgets(medicine_data[iterator], MAX_STRLEN, input_file) !=  NULL; iterator++);

    *medicine_count = iterator;     //  saves medicine count to the variable via it's pointer
}

void find_medicine_and_print(char medicine_data[][MAX_STRLEN],char user_input[MAX_STRLEN], int medicine_count)
{
    int iterator, found = FALSE;
    char med_find_str[4];           //  variable to get user inputs first 3 letter
    char will_print[MAX_STRLEN];    //  the manual that going to be printed

    strncpy(med_find_str, user_input, 3);   //  gets first 3 characters of user_input
    med_find_str[3] = '\0';     //  sets last character to '\0' because it is end of the string

    for (iterator = 0; iterator < medicine_count; iterator++)
    {
        if (strncmp(medicine_data[iterator], med_find_str, 3) == 0){    //  compares first three characters
            strcpy(will_print, medicine_data[iterator]);                //  copies the data from array to a string will be printed
            print_screen(will_print);                                   //  sends the data to function that will print the data
            found = TRUE;                                               //  sets found to 1 to avoid printing couldn't find.
        }
    }
    if (!found) {
        printf("Couldn't find the medicine!");
    }
}

/*
 * Prints the validated data seperated lines
 *
 * Pre: will_print must be user wanted medicine
 */
void
print_screen(char will_print[MAX_STRLEN])
{
    char* new_line;
    int iterator;
    new_line = strtok(will_print, " "); //  omits the medicine name
    for (iterator = 0; new_line != NULL; iterator++){
        new_line = strtok(NULL, ";");   //  separates the data
        if (new_line != NULL && *new_line != '\n')
            printf(">%s\n", new_line);
    }
}