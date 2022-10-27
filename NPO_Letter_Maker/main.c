/*
 *  Programmer: Emirhan TALA             Date completed: Oct 27, 2022
 *
 * A program that creates acknowledgement letters to donors for a nonprofit organization.
 */

#include <stdio.h>
#include <string.h>

#define STRLEN 30
#define LONG_STRLEN 1000
#define MAX_ARR_SIZE 100

#define TRUE 1
#define FALSE 0

typedef struct {
    char last_name[STRLEN];
    char first_name[STRLEN];
    char addr_first_line[STRLEN];
    char addr_second_line[STRLEN];
    char city[STRLEN];
    char state[STRLEN];
    int zip;
    double donation;
} donor_t;

int load_donor_table(char* input_file_name, donor_t donor_table[MAX_ARR_SIZE], double* total_donation);
void console_output(donor_t donor_table[MAX_ARR_SIZE], int array_size, double total_donation);
void donor_list_updater(donor_t donor_table[MAX_ARR_SIZE], int *array_size, double *total_donation);
void sort_and_save_db(char* input_file_name, donor_t donor_table[MAX_ARR_SIZE], int array_size);
void create_letters(donor_t donor_table[MAX_ARR_SIZE], int array_size);

int main() {
    char input_file_name[STRLEN];
    donor_t donor_table[MAX_ARR_SIZE];
    int donor_table_array_size = -1;
    double total_donation = 0;

    //  Gets the file name to get data from
    printf("Enter the input file name\n> ");
    scanf("%s", input_file_name);

    //  Cleans the stdin buffer
    int clean_buffer;
    while ((clean_buffer = getchar()) != '\n' && clean_buffer != EOF);

    //  Loads the data from input file
    donor_table_array_size = load_donor_table(input_file_name, donor_table, &total_donation);

    //  If there is no file named input_file_name, if the data inside the file is not valid or something went wrong closes the program directly to escape later errors
    if (donor_table_array_size == -1) return 1;

    //  Prints the input data with a formatted style. Prints the total amount of donation
    console_output(donor_table, donor_table_array_size, total_donation);

    //  Updates if there is any new donor
    donor_list_updater(donor_table,  &donor_table_array_size, &total_donation);

    //  Sorts the whole donor list with looking all of donor's last names and saves the data to input_file_name file
    sort_and_save_db(input_file_name, donor_table, donor_table_array_size);

    //  After the data sorted creates a letter for each donor
    create_letters(donor_table, donor_table_array_size);

    return 0;
}

/*
 *  Gets the donor data from the input file that user gave.
 *  8 lines of data from input file is for 1 donor, so 1 donor_table item has 8 line input data.
 *  Saves the total donation via its pointer.
 *  Returns the array length.
 *
 *  Pre:    All variables are defined, there is a file named input_file_name variable string, input file can't have donor data more than MAX_ARR_SIZE
 *  Post:   Return array_size, saves the total donation via its pointer.
 */
int
load_donor_table(char* input_file_name,
                 donor_t donor_table[MAX_ARR_SIZE],
                 double* total_donation)
{
    int iterator, iterator_inside;

    char str_input_from_file[STRLEN];

    //  Gets the exact file location
    char input_file_location[LONG_STRLEN] = "/Users/emivvvvv/CLionProjects/NPO_Letter_Maker/";
    strcat(input_file_location, input_file_name);

    //  Opens the file
    FILE* input_file;
    input_file = fopen(input_file_location, "r");

    //  If there is no file named user input file name returns -1 and closes the program
    if (input_file == NULL) {
        printf("File '%s' could not found. Closing the program.\n", input_file_name);
        return -1;
    }

    //  Gets the whole line and saves corresponding place in donor_t variable type donor table variable
    for (iterator = 0, iterator_inside = -1; fgets(str_input_from_file, LONG_STRLEN, input_file) != NULL && iterator < MAX_ARR_SIZE * 8; iterator++) {
        if (iterator % 8 == 0) iterator_inside++;
        switch ((iterator + 1) % 8) {
            case 1:
                sscanf(str_input_from_file, "%s", donor_table[iterator_inside].last_name);
                break;
            case 2:
                sscanf(str_input_from_file, "%s", donor_table[iterator_inside].first_name);
                break;
            case 3:
                sscanf(str_input_from_file, "%s", donor_table[iterator_inside].addr_first_line);
                break;
            case 4:
                sscanf(str_input_from_file, "%s", donor_table[iterator_inside].addr_second_line);
                break;
            case 5:
                sscanf(str_input_from_file, "%s", donor_table[iterator_inside].city);
                break;
            case 6:
                sscanf(str_input_from_file, "%s", donor_table[iterator_inside].state);
                break;
            case 7:
                sscanf(str_input_from_file, "%d", &donor_table[iterator_inside].zip);
                break;
            case 0:
                sscanf(str_input_from_file, "%lf", &donor_table[iterator_inside].donation);

                //  Sums total donation
                *total_donation += donor_table[iterator_inside].donation;
                break;
            default:
                printf("Something went wrong. Closing the program...\n");
                return -1;
        }
    }

    //  Closes the input file
    fclose(input_file);

    //  Returns array length
    return (iterator_inside + 1);
}

/*
 *  Prints the summarized donor data and the total donation.
 */
void
console_output(donor_t donor_table[MAX_ARR_SIZE],
               int array_size,
               double total_donation)
{
    int iterator;

    printf("\n");
    for (iterator = 0; iterator < array_size; iterator++){
        printf("%s, %s has donated %.2f$\n",
               donor_table[iterator].last_name,
               donor_table[iterator].first_name,
               donor_table[iterator].donation);
    }
    printf("\nTOTAL DONATION: $%.2lf\n\n", total_donation);
}

/*
 *  Ask user if he/she wants to add a new donor or not.
 *  If user types 'q' or donor table has the maximum donor count
 *  updater closes else user must type new donor data with correct style.
 *  Updates the total donation and array size variables via their pointers.
 *
 *  Pre:    All variables must be defined.
 *  Post:   donor_table is updated if user enters the new donors data
 */
void
donor_list_updater(donor_t donor_table[MAX_ARR_SIZE],
                   int *array_size,
                   double *total_donation)
{

    int should_continue = TRUE;
    char str_input_from_user[LONG_STRLEN];


    while (should_continue)
    {
        printf("\n\nType the new donor data as template shows or enter 'q' to quit update panel.\n");
        printf("Examle input =>\nTala,Emirhan,Atasehir Kayisdagi,YU Erkek yurdu,Istanbul,IST,34000,69000\n> ");
        gets(str_input_from_user);
        if(strcmp(str_input_from_user, "q") == 0 || *array_size == MAX_ARR_SIZE){                               //  If user typed 'q' or the data table has the maximum donor already quits updater function
            should_continue = FALSE;
            if (*array_size == MAX_ARR_SIZE) printf("\nReached maximum number of donor.");
            printf("\nSaving data.");
        } else {                                                                                                //  Else parses the string and saves the donor data corresponding field
            strcpy(donor_table[*array_size].last_name, strtok(str_input_from_user, ","));
            strcpy(donor_table[*array_size].first_name, strtok(NULL, ","));
            strcpy(donor_table[*array_size].addr_first_line, strtok(NULL, ","));
            strcpy(donor_table[*array_size].addr_second_line, strtok(NULL, ","));
            strcpy(donor_table[*array_size].city, strtok(NULL, ","));
            strcpy(donor_table[*array_size].state, strtok(NULL, ","));
            sscanf(strtok(NULL, ","), "%d", &donor_table[*array_size].zip);
            sscanf(strtok(NULL, ","), "%lf", &donor_table[*array_size].donation);

            //  Updates total donation
            *total_donation += donor_table[*array_size].donation;

            //  Prints a simple information about new user and the new donation
            printf("%s, %s has added to the database!\nNew total donation is: %.2f\n",
                   donor_table[*array_size].last_name,
                   donor_table[*array_size].first_name,
                   *total_donation);

            //  Increases array size
            *array_size += 1;
        }
    }
}

/*
 *  Opens input file again but this time opens to write.
 *  Sorts the donor_table with donor's last names.
 *  Saves the sorted donor_table to the input file.
 *
 *  Pre:    all variables must be declared.
 *  Post:   sorted donor_table, updated input file with sorted donor_table.
 */
void
sort_and_save_db(char* input_file_name,
                 donor_t donor_table[MAX_ARR_SIZE],
                 int array_size)
{
    int iterator, iterator_inside;
    donor_t temp;

    //  Gets the exact file location
    char input_file_location[LONG_STRLEN] = "/Users/emivvvvv/CLionProjects/NPO_Letter_Maker/";
    strcat(input_file_location, input_file_name);

    //  Opens the input file
    FILE* input_file;
    input_file = fopen(input_file_location, "w");

    //  Sorts all the donor data with their last names
    for (iterator = 0; iterator < array_size; iterator++){
        for (iterator_inside = iterator + 1 ; iterator_inside < array_size; iterator_inside++){
            if (strcmp(donor_table[iterator].last_name, donor_table[iterator_inside].last_name) > 0){
                temp = donor_table[iterator];
                donor_table[iterator] = donor_table[iterator_inside];
                donor_table[iterator_inside] = temp;
            }
        }
    }

    //  Saves all the sorted data to the input file.
    for (iterator = 0; iterator < array_size; iterator++)
    {
        fprintf(input_file, "%s\n%s\n%s\n%s\n%s\n%s\n%d\n%.2lf\n",
                donor_table[iterator].last_name,
                donor_table[iterator].first_name,
                donor_table[iterator].addr_first_line,
                donor_table[iterator].addr_second_line,
                donor_table[iterator].city,
                donor_table[iterator].state,
                donor_table[iterator].zip,
                donor_table[iterator].donation);
    }

    //  Closes the input file
    fclose(input_file);
}

/*
 *  Creates a letter for each donor.
 *
 *  Pres:   all variables must be defined.
 */
void
create_letters(donor_t donor_table[MAX_ARR_SIZE],
               int array_size)
{
    int iterator;
    char letter_message[LONG_STRLEN] = "\f\n\n\n\n\n\n\n\n\n\nDear ";                                                   //  Creates new page with \f and puts 10 blank lines with \n
    char temp_str[LONG_STRLEN];

    //  Opens file
    FILE* letter_file;
    letter_file = fopen("/Users/emivvvvv/CLionProjects/NPO_Letter_Maker/thank_you_letters.txt", "w");

    //  Creates the letter for each donor as styled.
    for (iterator = 0; iterator < array_size; iterator++){
        strcat(letter_message, donor_table[iterator].first_name);
        strcat(letter_message, " ");
        strcat(letter_message, donor_table[iterator].last_name);
        strcat(letter_message, "\n\nWe would like to say a big thank you from our hearts.\nYou donated $");
        sprintf(temp_str, "%.2f", donor_table[iterator].donation);
        strcat(letter_message, temp_str);
        strcat(letter_message, ".\n\nUntil next time take care.\nEmirhan TALA\n");
        fprintf(letter_file, "%s", letter_message);
        strcpy(letter_message, "\f\n\n\n\n\n\n\n\n\n\nDear ");
    }

    //  Closes the letter file
    fclose(letter_file);
}
