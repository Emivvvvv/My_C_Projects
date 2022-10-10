/*
 *  Programmer: Emirhan TALA             Date completed: Oct 10, 2022
 *
 *  Binary_Search algorithm written in C
 */

#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define MAX_INDEX 11

int main() {
    int bottom_index, top_index, middle_index, try_count;
    int sorted_array[MAX_INDEX] = {2, 6, 8, 94, 645, 3654, 11364, 76458, 98768, 345547, 999999};
    int iterator;

    for (iterator = 0; iterator < MAX_INDEX; iterator++)
    {
        int number = sorted_array[iterator];
        int found = FALSE;

        bottom_index = 0;
        top_index = MAX_INDEX - 1;
        while (!found) {
            try_count++;
            middle_index = bottom_index + (top_index - bottom_index) / 2;
            if (sorted_array[middle_index] == number) {
                found = TRUE;
            } else if (sorted_array[middle_index] > number){
                top_index = middle_index - 1;
            } else {
                bottom_index = middle_index + 1;
            }
        }
        printf("Found %d in %d tries!\n", number, try_count);
        try_count = 0;
    }

    return 0;
}
