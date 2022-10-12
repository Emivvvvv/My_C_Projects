/*
 *  Programmer: Emirhan TALA             Date completed: Oct 13, 2022
 *
 *  Program that loads from a data file a list of hurricanes making landfall in the U.S.
 *  along with the year they occurred and the states affected before the storm was downgraded.
 */

#include <stdio.h>
#include <string.h>

#define MAX_HURRICANE 30
#define MAX_STRLEN 50


void print_screen(int num_of_hurricane, int sorted_years[], char* sorted_names[], char* sorted_states[]);
void get_data(FILE*, int[], char[][MAX_STRLEN], char[][MAX_STRLEN], int*);
void selection_sort(char names[][MAX_STRLEN], char* sorted_names[], char states[][MAX_STRLEN], char* sorted_states[], const int years[MAX_HURRICANE], int sorted_years[MAX_HURRICANE], int num_of_hurricane, char command);


int main() {
    int years[MAX_HURRICANE];                     //    original array declaration for years
    int sorted_years[MAX_HURRICANE];              //    sorted array declaration for years
    char names[MAX_HURRICANE][MAX_STRLEN];        //    original array declaration for names
    char* sorted_names[MAX_HURRICANE];            //    sorted array declaration for names
    char states[MAX_HURRICANE][MAX_STRLEN];       //    original array declaration for states
    char* sorted_states[MAX_HURRICANE];           //    sorted array declaration for states

    char command, clear_buffer;
    int num_of_hurricane;

    num_of_hurricane = 0;                          //   sets initial data to 0

    FILE *input_file;                              //   input file pointer

    input_file = fopen("/Users/emivvvvv/CLionProjects/Hurricanes_Making_Landfall_in_the_US/hurricane.txt", "r");

    //  Ask user to select whether the hurricanes should be sorted
    printf("Whether the hurricanes should be sorted by year of occurrence(o) or by name(n)?\n> ");

    //  Gets the command input from user
    do{
        command = getchar();

        //  Clears input buffer after getting the command
        do {
            clear_buffer = getchar();
        } while (clear_buffer != '\n');

        //  If input wasn't valid prints a warning message
        if (command != 'o' && command != 'n' && command != 'O' && command != 'N' ){
            printf("'%c' isn't a valid input. Please type 'o' or 'n'\n> ", command);
        }
    } while (command != 'o' && command != 'n' && command != 'O' && command != 'N' );    //  Loops until gets a valid loop.


    //  Gets data from the input file
    get_data(input_file, years, names, states, &num_of_hurricane);

    //  Sorts the data as user wanted
    switch (command) {
        case 'o':
        case 'O':
            selection_sort(names, sorted_names, states, sorted_states, years, sorted_years, num_of_hurricane, 'O');
            break;
        case 'n':
        case 'N':
            selection_sort(names, sorted_names, states, sorted_states, years, sorted_years, num_of_hurricane, 'N');
            break;
        default:
            printf("Upsieeeee :((((. Something went wrong. DEBUG: command = %c", command);
    }

    //  Prints sorted data
    print_screen(num_of_hurricane, sorted_years, sorted_names, sorted_states);


    //  Closes the input file
    fclose(input_file);


    return 0;
}


/*
 * Gets data from the input file and separates hurricane years, names and states which affected.
 *
 * Pre: All variables must be declared.
 *      num_of_hurricane is a pointer.
 *
 * Post: int years[] has the years of hurricanes,
 *       char names[][MAX_STRLEN] has the names of hurricanes,
 *       char states[][MAX_STRLEN] is affected states.
 *       These arrays are parallel arrays.
 *       num_of_hurricane is saved via it's pointer.
 */
void
get_data(FILE* input_file,              //  input - input file pointer
         int years[],                   //  output - years of hurricanes
         char names[][MAX_STRLEN],      //  output - names of hurricanes
         char states[][MAX_STRLEN],     //  output - states that hurricanes happened
         int* num_of_hurricane)         //  output - number of hurricanes
{

    int iterator;
    char str[MAX_STRLEN];


    for(iterator = 0; fgets(str, MAX_STRLEN, input_file) != NULL; iterator++){
        *num_of_hurricane += 1;
        sscanf(str, "%d %s %s", &years[iterator], names[iterator], states[iterator]);
    }

}


/*
 * Copies the pointers to sorted lists and sorts them by using selection sort.
 *
 * Pres: All variables are declared.
 *       input strings must be < MAX_STRLEN(50)
 *
 * Post: char* sorted_names[], char* sorted_states[], sorted_years[MAX_HURRICANE] are sorted versions of their original arrays.
 */
void
selection_sort(char names[][MAX_STRLEN],            //  input - sorted array of names
               char* sorted_names[],                //  output - sorted array of names
               char states[][MAX_STRLEN],           //  input - sorted array of states
               char* sorted_states[],               //  output - sorted array of states
               const int years[MAX_HURRICANE],      //  input - sorted array of years
               int sorted_years[MAX_HURRICANE],     //  output - sorted array of years
               int num_of_hurricane,
               char command)
{
    int iterator, iterator_inside,
    int_temp;   // temp of years

    char* temp; //  temp of a pointer to a string

    //  Copies pointers for string and integers for years to sorted_<name>[] arrays
    for (iterator = 0; iterator < num_of_hurricane; iterator++) {
        sorted_names[iterator] = names[iterator];
        sorted_years[iterator] = years[iterator];
        sorted_states[iterator] = states[iterator];
    }

    //  Basic selection sort. If command is 'N' sorts by name else sorts by year.
    for (iterator = 0; iterator < num_of_hurricane; iterator++){
        for (iterator_inside = iterator + 1; iterator_inside < num_of_hurricane; iterator_inside++){
            if (command == 'N'){
                if (strcmp(sorted_names[iterator], sorted_names[iterator_inside]) > 0){
                    temp = sorted_names[iterator];
                    sorted_names[iterator] = sorted_names[iterator_inside];
                    sorted_names[iterator_inside] = temp;
                    temp = sorted_states[iterator];
                    sorted_states[iterator] = sorted_states[iterator_inside];
                    sorted_states[iterator_inside] = temp;
                    int_temp = sorted_years[iterator];
                    sorted_years[iterator] = sorted_years[iterator_inside];
                    sorted_years[iterator_inside] = int_temp;
                }
            } else {
                if (sorted_years[iterator] > sorted_years[iterator_inside]){
                    temp = sorted_names[iterator];
                    sorted_names[iterator] = sorted_names[iterator_inside];
                    sorted_names[iterator_inside] = temp;
                    temp = sorted_states[iterator];
                    sorted_states[iterator] = sorted_states[iterator_inside];
                    sorted_states[iterator_inside] = temp;
                    int_temp = sorted_years[iterator];
                    sorted_years[iterator] = sorted_years[iterator_inside];
                    sorted_years[iterator_inside] = int_temp;
                }
            }
        }
    }
}


/*
 * Prints the sorted data to console
 *
 * Pre: All variables are declared and sorted as wanted.
 */
void
print_screen(int num_of_hurricane,   // number of hurricanes to max iteration number
             int sorted_years[],     // sorted years to print
             char* sorted_names[],   // sorted names to print
             char* sorted_states[])  // sorted states to print
{
    int iterator;

    printf("\n\n U.S Hurrıcanes by Year of Occurrence \n");
    printf("======================================\n");
    for (iterator = 0; iterator < num_of_hurricane; iterator++){
        printf("%4d%17s%17s\n", sorted_years[iterator], sorted_names[iterator], sorted_states[iterator]);
    }
}
