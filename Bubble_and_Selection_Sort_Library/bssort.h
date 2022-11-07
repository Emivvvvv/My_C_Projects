/*  Header file bssort.h
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

#ifndef BUBBLE_AND_SELECTION_SORT_LIBRARY_BSSORT_H
#define BUBBLE_AND_SELECTION_SORT_LIBRARY_BSSORT_H

/*
 * Takes an int array and the length of it and sorts that array by using
 * bubble sort algorithm.
 *
 * Max number and the max length of the array must be 100
 * All variables must be defined in the main.
 */
extern int*
bubbleSort(int random_number_array[], int const array_length);

/*
 * Takes an int array and the length of it and sorts that array by using
 * bubble sort algorithm but reversed order.
 *
 * Max number and the max length of the array must be 100
 * All variables must be defined in the main.
 */
extern int*
bubbleSortD(int random_number_array[], int const array_length);

/*
 * Takes an int array and the length of it and sorts that array by using
 * selection sort algorithm.
 *
 * Max number and the max length of the array must be 100
 * All variables must be defined in the main.
 */
extern int*
selectionSort(int random_number_array[], int const array_length);

/*
 * Prints the array with getting the length of the array and the length of it.
 */
extern void
printArray(int array[], int array_length);

/*
 * Takes an int array, the length of it and the maximum number and
 * returns the array[] with randomized numbers with length array_length.
 *
 * A random number interval is [0, max_number);
 */
extern void
randomNumberArrayGenerator(int array[], int array_length, int max_number);

#endif //BUBBLE_AND_SELECTION_SORT_LIBRARY_BSSORT_H
