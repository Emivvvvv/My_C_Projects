/*  Implementation file bssort.c
 *
 *  Programmer: Emirhan TALA             Date completed: Nov 07, 2022
 *
 *  This library takes maximum of 100 random numbers with a maximum value of 100
 *  and sorts them by using bubble sort or selection sort algorithm.
 *
 *  Operators:
 *      bubbleSort, bubbleSortD, selectionSort, printArray, randomNumberArrayGenerator
 *
 */

#include "bssort.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Takes an int array and the length of it and sorts that array by using
 * bubble sort algorithm.
 *
 * Max number and the max length of the array must be 100
 * All variables must be defined in the main.
 */
int*
bubbleSort(int random_number_array[], int const array_length)
{
    int temp;
    int iterator, iterator_inside;

    for (iterator = 1; iterator < array_length; iterator++){
        for (iterator_inside = 0; iterator_inside < array_length - iterator; iterator_inside++)
        {
            if (random_number_array[iterator_inside] > random_number_array[iterator_inside + 1]){
                temp = random_number_array[iterator_inside];
                random_number_array[iterator_inside] = random_number_array[iterator_inside + 1];
                random_number_array[iterator_inside + 1] = temp;
            }
        }
    }

    return random_number_array;
}

/*
 * Takes an int array and the length of it and sorts that array by using
 * bubble sort algorithm but reversed order.
 *
 * Max number and the max length of the array must be 100
 * All variables must be defined in the main.
 */
int*
bubbleSortD(int random_number_array[], int const array_length)
{
    int temp;
    int iterator, iterator_inside;

    for (iterator = 1; iterator < array_length; iterator++){
        for (iterator_inside = array_length - 1; iterator_inside >= iterator; iterator_inside--)
        {
            if (random_number_array[iterator_inside - 1] < random_number_array[iterator_inside]){
                temp = random_number_array[iterator_inside];
                random_number_array[iterator_inside] = random_number_array[iterator_inside - 1];
                random_number_array[iterator_inside - 1] = temp;
            }
        }
    }

    return random_number_array;

}

/*
 * Takes an int array and the length of it and sorts that array by using
 * selection sort algorithm.
 *
 * Max number and the max length of the array must be 100
 * All variables must be defined in the main.
 */
int*
selectionSort(int random_number_array[], int const array_length)
{
    int temp;
    int iterator, iterator_inside;

    for (iterator = 0; iterator < array_length; iterator++){
        for (iterator_inside = iterator + 1 ; iterator_inside < array_length; iterator_inside++){
            if (random_number_array[iterator] > random_number_array[iterator_inside]){
                temp = random_number_array[iterator];
                random_number_array[iterator] = random_number_array[iterator_inside];
                random_number_array[iterator_inside] = temp;
            }
        }
    }

    return random_number_array;
}

/*
 * Prints the array with getting the length of the array and the length of it.
 */
void
printArray(int array[], int array_length)
{
    int iterator;

    printf("[");
    for (iterator = 0; iterator < array_length - 1; iterator++) printf("%d, ", array[iterator]);
    printf("%d]\n", array[iterator]);
}

/*
 * Takes an int array, the length of it and the maximum number and
 * returns the array[] with randomized numbers with length array_length.
 *
 * A random number interval is [0, max_number);
 */
void
randomNumberArrayGenerator(int array[], int array_length, int max_number)
{
    int iterator;

    for (iterator = 0; iterator < array_length; iterator++)
        array[iterator] = (rand() % max_number);
}

