/*
 *  Programmer: Emirhan TALA             Date completed: Oct 26, 2022
 *
 * A program for Microbiologists.
 */

#include <stdio.h>
#include <string.h>

#define STRLEN 200
#define MAX_ARR_SIZE 100

typedef struct {
    char comb_of_positives[STRLEN];
    int mpn_index;
    int lwr_bound;
    int uppr_bound;
} mpn_t;

int load_Mpn_Table(char* input_file_name, mpn_t mpn_table[MAX_ARR_SIZE], int max_array_size);
mpn_t search(mpn_t mpn_table[MAX_ARR_SIZE], int array_size, char* comb_of_positives);

int main() {
    char input_file_name[STRLEN], user_wanted_cop[STRLEN];
    mpn_t mpn_table[MAX_ARR_SIZE], user_wanted_data;
    int array_size;

    printf("Enter the input file name\n> ");
    scanf("%s", input_file_name);

    array_size = load_Mpn_Table(input_file_name, mpn_table, MAX_ARR_SIZE);
    if (array_size == -1){
        return 1;
    }
    printf("Enter the combination of positives value of the data that you want\n> ");
    scanf("%s", user_wanted_cop);

    user_wanted_data = search(mpn_table, array_size, user_wanted_cop);

    if (strcmp("-1", user_wanted_data.comb_of_positives) != 0){
        printf("For %s, MPN = %d; 95%% of samples contain between %d and %d bacteria/ml.",
               user_wanted_cop,
               user_wanted_data.mpn_index,
               user_wanted_data.lwr_bound,
               user_wanted_data.uppr_bound);
    } else {
        printf("Could not find the data for '%s' combination of positives value", user_wanted_cop);
    }

    return 0;
}

/*
 * Loads the data from the input text file and saves
 * all the data to mpn_table array. Returns the length of the array.
 */
int
load_Mpn_Table(char* input_file_name,
               mpn_t mpn_table[MAX_ARR_SIZE],
               int max_array_size)
{
    int iterator;

    char str_input_from_file[STRLEN];
    char input_file_location[STRLEN] = "/Users/emivvvvv/CLionProjects/Microbiology_MPN/";
    strcat(input_file_location, input_file_name);

    FILE* input_file;
    input_file = fopen(input_file_location, "r");

    if (input_file == NULL) {
        printf("File '%s' could not found. Closing the program.", input_file_name);
        return -1;
    }


    for (iterator = 0; fgets(str_input_from_file, STRLEN - 1, input_file) != NULL && iterator < max_array_size; iterator++) {
        sscanf(str_input_from_file,"%s %d %d %d",
               mpn_table[iterator].comb_of_positives,
               &mpn_table[iterator].mpn_index,
               &mpn_table[iterator].lwr_bound,
               &mpn_table[iterator].uppr_bound);
    }

    fclose(input_file);
    return (iterator++);
}

/*
 * Finds the data has the same comb of positives with user input.
 * Returns the table if finds it else returns not found table with all data set to -1.
 */
mpn_t
search(mpn_t mpn_table[MAX_ARR_SIZE],
       int array_size,
       char* comb_of_positives)
{
    int iterator;

    for (iterator = 0; iterator < array_size; iterator++){
        if (strcmp(comb_of_positives, mpn_table[iterator].comb_of_positives) == 0){
            return mpn_table[iterator];
        }
    }

    mpn_t not_found = {"-1", -1, -1, -1};
    return not_found;
}
