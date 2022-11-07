/*
 *  Programmer: Emirhan TALA             Date completed: Nov 07, 2022
 *
 *  A main file to test bssort (bubble sort and selection sort) library.
 */

#include <stdio.h>
#include "bssort.h"

#define MAX_NUMBER 100
#define DEMO_ARR_SIZE 69
#define MAX_ARR_SIZE 100

int main() {
    int random_array_max_size[MAX_ARR_SIZE];
    int random_array_demo_size[DEMO_ARR_SIZE];
    int iterator;

    randomNumberArrayGenerator(random_array_max_size, MAX_ARR_SIZE, MAX_NUMBER);
    randomNumberArrayGenerator(random_array_demo_size, DEMO_ARR_SIZE, MAX_NUMBER);

    printf("Randomly generated test array 1 for bubble sort:\n");
    printArray(random_array_max_size, MAX_ARR_SIZE);
    printf("Randomly generated test array 2 for bubble sort:\n");
    printArray(random_array_demo_size, DEMO_ARR_SIZE);

    printf("\n\nSorted with bubble sort algorithm\n");
    printf("Array 1: ");
    printArray(bubbleSort(random_array_max_size, MAX_ARR_SIZE), MAX_ARR_SIZE);
    printf("Array 2: ");
    printArray(bubbleSort(random_array_demo_size, DEMO_ARR_SIZE), DEMO_ARR_SIZE);
    printf("\n");

    randomNumberArrayGenerator(random_array_max_size, MAX_ARR_SIZE, MAX_NUMBER);
    randomNumberArrayGenerator(random_array_demo_size, DEMO_ARR_SIZE, MAX_NUMBER);

    printf("Randomly generated test array 1 for descending order bubble sort:\n");
    printArray(random_array_max_size, MAX_ARR_SIZE);
    printf("Randomly generated test array 2 for descending order bubble sort:\n");
    printArray(random_array_demo_size, DEMO_ARR_SIZE);

    printf("\n\nSorted with descending order bubble sort algorithm\n");
    printf("Array 1: ");
    printArray(bubbleSortD(random_array_max_size, MAX_ARR_SIZE), MAX_ARR_SIZE);
    printf("Array 2: ");
    printArray(bubbleSortD(random_array_demo_size, DEMO_ARR_SIZE), DEMO_ARR_SIZE);
    printf("\n");

    randomNumberArrayGenerator(random_array_max_size, MAX_ARR_SIZE, MAX_NUMBER);
    randomNumberArrayGenerator(random_array_demo_size, MAX_ARR_SIZE, MAX_NUMBER);

    printf("Randomly generated test array 1 for selection sort:\n");
    printArray(random_array_max_size, MAX_ARR_SIZE);
    printf("Randomly generated test array 2 for selection sort:\n");
    printArray(random_array_demo_size, DEMO_ARR_SIZE);

    printf("\nSorted with selection sort algorithm\n");
    printf("Array 1: ");
    printArray(selectionSort(random_array_max_size, MAX_ARR_SIZE), MAX_ARR_SIZE);
    printf("Array 2: ");
    printArray(selectionSort(random_array_demo_size, DEMO_ARR_SIZE), DEMO_ARR_SIZE);
    printf("\n");

    printf("\nTo check bubble sort and selection sort gives the same output let's give the same input:\n");
    printf("Randomly generated test array for both sorting algorithms:\n");
    randomNumberArrayGenerator(random_array_max_size, MAX_ARR_SIZE, MAX_NUMBER);
    printArray(random_array_max_size, MAX_ARR_SIZE);

    printf("Bubble sort:    ");
    printArray(bubbleSort(random_array_max_size, MAX_ARR_SIZE), MAX_ARR_SIZE);
    printf("Selection sort: ");
    printArray(selectionSort(random_array_max_size, MAX_ARR_SIZE), MAX_ARR_SIZE);

    return 0;
}


