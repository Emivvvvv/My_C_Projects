/*
 *  Programmer: Emirhan TALA             Date completed: Oct 10, 2022
 *
 *  This program calculates the recidivism rate of adult offenders.
 *  This rate is calculated as the percent of offenders re-arrested within three years (36 months) of their date of release from prison.
 *
 */

#include <stdio.h>
#define MAX_OFFENDER_NUMBER 20


void get_data(FILE*, int[], int[], int[], int[], int[], int*);
double recidivism(int[], int[], int[], int[], int[], int);
void show_data(int[], int[], int[], int[], int[], double, int);

int main() {
    //  5 parallel arrays will contain infos about offenders.
    //  I could have declared a 2D array but book made me do parallel arrays for this problem.
    int offenders_ids[MAX_OFFENDER_NUMBER],
    offenders_mnth_of_relase[MAX_OFFENDER_NUMBER],
    offenders_year_of_relase[MAX_OFFENDER_NUMBER],
    offenders_mnth_of_rearrest[MAX_OFFENDER_NUMBER],
    offenders_year_of_rearrest[MAX_OFFENDER_NUMBER];

    int number_of_offender;
    double recidivism_rate;


    //  Opens offender_records file to get data
    FILE* offender_records = fopen("/Users/emivvvvv/CLionProjects/State_Justice_Department_Recidivism_Rate_Calculator/offender_records_2031.txt", "r");

    //  Gets data from the record file
    get_data(offender_records, offenders_ids, offenders_mnth_of_relase, offenders_year_of_relase, offenders_mnth_of_rearrest, offenders_year_of_rearrest, &number_of_offender);

    //  Calculates recidivisim rate
    recidivism_rate = recidivism(offenders_ids, offenders_mnth_of_relase, offenders_year_of_relase, offenders_mnth_of_rearrest, offenders_year_of_rearrest, number_of_offender);

    //  Prints the table and recidivism rate
    show_data(offenders_ids, offenders_mnth_of_relase, offenders_year_of_relase, offenders_mnth_of_rearrest, offenders_year_of_rearrest, recidivism_rate, number_of_offender);

    //  Closes offender_records file to free ram
    fclose(offender_records);
    return 0;
}

/*
 * Gets data from offender_records text file and count how many people are there
 *
 * Pre: offender_records file pointer, int offenders_ids[], int offenders_mnth_of_relase[], int offenders_year_of_relase[], int offenders_mnth_of_rearrest[], int offenders_year_of_rearrest[], double recidivism_rate, int* number_or_offender must be declared.
 */
void
get_data(FILE* offender_records,
         int offenders_ids[],
         int offenders_mnth_of_relase[],
         int offenders_year_of_relase[],
         int offenders_mnth_of_rearrest[],
         int offenders_year_of_rearrest[],
         int *number_of_offender)
{
    int status,
    iterator = 0;

    //  Gets offender data until reach END OF FILE
    do{
        status = fscanf(offender_records, "%d", &offenders_ids[iterator]);
        status = fscanf(offender_records, "%d", &offenders_mnth_of_relase[iterator]);
        status = fscanf(offender_records, "%d", &offenders_year_of_relase[iterator]);
        status = fscanf(offender_records, "%d", &offenders_mnth_of_rearrest[iterator]);
        status = fscanf(offender_records, "%d", &offenders_year_of_rearrest[iterator]);
        if (status != EOF) iterator++;
    } while (status != EOF);

    //  Saves number of offender via its pointer
    *number_of_offender = iterator;
}

/*
 * Calculates recidivism rate
 *
 * Pres: int offenders_ids[], int offenders_mnth_of_relase[], int offenders_year_of_relase[], int offenders_mnth_of_rearrest[], int offenders_year_of_rearrest[], int number_or_offender must be declared.
 * Post: double recidivism rate
 */
double
recidivism(int offenders_ids[],
           int offenders_mnth_of_relase[],
           int offenders_year_of_relase[],
           int offenders_mnth_of_rearrest[],
           int offenders_year_of_rearrest[],
           int number_of_offender)
{
    double recidivism_rate;
    int iterator, total_month_passed, recidivism_count;


    recidivism_count = 0;
    for (iterator = 0; iterator < number_of_offender; iterator++){
        //  Checks if offender rearrested again
        if (offenders_year_of_rearrest[iterator] != 0 && offenders_mnth_of_rearrest != 0){

            //  Calculates total month between releasing and rearresting
            total_month_passed = (offenders_year_of_rearrest[iterator] * 12 + offenders_mnth_of_rearrest[iterator]) - (offenders_year_of_relase[iterator] * 12 + offenders_mnth_of_relase[iterator]);
            if (total_month_passed <= 36){

                //  Increases recidivism count to use later to calculate recidivism rate
                recidivism_count++;
            }
        }
    }

    //  Calculates recidivism rate
    recidivism_rate = ((double)(recidivism_count * 100) / number_of_offender);
    return recidivism_rate;
}

/*
 * Prints all the offender data and recidivism rate to a table.
 *
 * Pres: int offenders_ids[], int offenders_mnth_of_relase[], int offenders_year_of_relase[], int offenders_mnth_of_rearrest[], int offenders_year_of_rearrest[], double recidivism_rate, int number_or_offender must be declared.
 */
void
show_data(int offenders_ids[],
          int offenders_mnth_of_relase[],
          int offenders_year_of_relase[],
          int offenders_mnth_of_rearrest[],
          int offenders_year_of_rearrest[],
          double recidivism_rate,
          int number_or_offender)
{
    //  Prints all data table
    int iterator;
    printf("OFFENDER ID       | MONTH OF RELEASE | YEAR OF RELEASE  | MONTH OF REARREST| YEAR OF REARREST |\n");
    printf("===============================================================================================\n");
    for (iterator = 0; iterator < number_or_offender; iterator++){
        printf("            %6d|            %6d|            %6d|            %6d|            %6d|\n",offenders_ids[iterator], offenders_mnth_of_relase[iterator], offenders_year_of_relase[iterator], offenders_mnth_of_rearrest[iterator], offenders_year_of_rearrest[iterator]);
    }
    printf("==============================================================================================\n");
    printf("RECIDIVISM RATE IS: %%%.1f", recidivism_rate);
}
