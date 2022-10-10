/*
 *  Programmer: Emirhan TALA             Date completed: Oct 10, 2022
 *
 *  Selection sort algorithm written in C
 */

#include <stdio.h>
#define MAX_INDEX 10


int main() {
    int temp;
    int array[MAX_INDEX] = {6,7,2,9,5,4,0,1,8,3};
    int iterator, iterator_inside;

    for (iterator = 0; iterator < MAX_INDEX; iterator++){
        for (iterator_inside = iterator + 1 ; iterator_inside < MAX_INDEX; iterator_inside++){
            if (array[iterator] > array[iterator_inside]){
                temp = array[iterator];
                array[iterator] = array[iterator_inside];
                array[iterator_inside] = temp;
            }
        }
    }

    //  Prints result
    for (iterator = 0; iterator < MAX_INDEX; iterator++){
        printf("%d ",array[iterator]);
    }
    return 0;
}
