/*
 *  Programmer: Emirhan TALA             Date completed: Oct 13, 2022
 *
 *  This program processes a data file of names in which each name is on a separate line of at most 80 characters.
 *  Program scans the names into three arrays, formats them and prints.
 */


#include <stdio.h>
#include <string.h>

#define MAX_STRLEN 80
#define MAX_PEOPLE 30
#define LAST_NAME_MAXLEN 15
#define FIRST_NAME_MAXLEN 10
#define MIDDLE_NAME_MAXLEN 10

int main() {
    char input_string[MAX_STRLEN];                      //  input file saves the line of string to this variable
    char first_names[MAX_PEOPLE][MAX_STRLEN];           //  all the first names will be in this array
    char middle_names[MAX_PEOPLE][MAX_STRLEN];          //  all the middle names will be in this array
    char last_names[MAX_PEOPLE][MAX_STRLEN];            //  all the last names will be in this array

    int iterator;

    FILE* input_file;

    //  Opens input file
    input_file = fopen("/Users/emivvvvv/CLionProjects/Name_Formatter/name_file.txt", "r");

    //  Gets data from the input file and splits the string to three parts and assign related string list. Cuts the data as wanted and prints in formatted style.
    for(iterator = 0; fgets(input_string ,MAX_STRLEN, input_file) != NULL && iterator <= MAX_PEOPLE; iterator++){
        strncpy(last_names[iterator], strtok(input_string, ", ."), LAST_NAME_MAXLEN);       //  Gets the last name and copies to related string variable.
        last_names[iterator][15] = '\0';                                                             //  Sets 16th char as '\0' to end the string if it is longer than 15
        strncpy(first_names[iterator], strtok(NULL, ",. "), FIRST_NAME_MAXLEN);             //  Gets the first name and copies to related string variable.
        first_names[iterator][10] = '\0';                                                            //  Sets 16th char as '\0' to end the string if it is longer than 15
        strncpy(middle_names[iterator], strtok(NULL, ",. "), MIDDLE_NAME_MAXLEN);           //  Gets the middle name and copies to related string variable.
        middle_names[iterator][10] = '\0';                                                           //  Sets 16th char as '\0' to end the string if it is longer than 15
        printf("%-15s  %-10s  %-10s\n", last_names[iterator], middle_names[iterator], first_names[iterator]);       //  Prints the formatted version of data
    }
    return 0;
}
