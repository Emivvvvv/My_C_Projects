/*
 *  Programmer: Emirhan TALA             Date completed: Oct 10, 2022
 *
 *  This program merges two sorted array into one array.
 */

#include <stdio.h>
#define BIG_ARRAY 10
#define SMALL_ARRAY 6

int main() {
    double array_1[] = { -3.1, 4.5,  6.9, 33.1, 42.0, 6453, 34634, 47568, 96877, 253435};
    double array_2[] = {-3.4, 6.9, 4356, 96877, 2345897, 999999};
    double merged_array[BIG_ARRAY + SMALL_ARRAY] = {0};

    double min;
    int iterator, array_1_counter, array_2_counter, merged_array_counter;

    array_1_counter = 0;
    array_2_counter = 0;
    merged_array_counter = 0;


    for (iterator = 0;  iterator < (BIG_ARRAY + SMALL_ARRAY); iterator++){
        if (iterator + array_1_counter < BIG_ARRAY && iterator + array_2_counter < SMALL_ARRAY) {
            if (array_1[iterator + array_1_counter] < array_2[iterator + array_2_counter]) {
                min = array_1[iterator + array_1_counter];
                array_2_counter--;
            } else {
                min = array_2[iterator + array_2_counter];
                array_1_counter--;
            }
        } else if (iterator + array_1_counter >= BIG_ARRAY){
            min = array_2[iterator + array_2_counter];
        } else if (iterator + array_2_counter >= SMALL_ARRAY){
            min = array_1[iterator + array_1_counter];
        }

        if (min == merged_array[iterator - 1 + merged_array_counter]){
            merged_array_counter--;
        } else {
            merged_array[iterator + merged_array_counter] = min;
        }
    }

    printf("\n");
    for (iterator = 0;  iterator < SMALL_ARRAY + BIG_ARRAY; iterator++){
        printf("%.1f ", merged_array[iterator]);
    }
    return 0;
}

//  OUTPUT: -3.4 -3.1 4.5 6.9 33.1 42.0 4356.0 6453.0 34634.0 47568.0 96877.0 253435.0 2345897.0 999999.0 0.0 0.0