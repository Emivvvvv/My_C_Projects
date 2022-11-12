/*  Test file ddslib.c
 *
 *  Programmer: Emirhan TALA             Date completed: Nov 11, 2022
 *
 *  Test Program of "ddslib.h" (Dynamic Data Structures Library)
 */

#include <stdio.h>
#include "ddslib.h"

#define TEST_INT 420
#define TEST_INT_2 9999
#define TEST_CHAR '&'

int main() {
    int success_code;
    char element;

    /*
     *  ==================================================================================================================
     *  TEST CODES FOR int_linked_list_node_t DATA TYPE AND ITS OPERATION FUNCTIONS.
     *  ==================================================================================================================
     */
    int_linked_list_node_t *int_linked_list = NULL, *search_result_int_linked_list = NULL;

    int_linked_list = get_int_linked_list(int_linked_list);

    success_code = print_int_linked_list(int_linked_list);
    printf("\nSuccess code of 'print_int_linked_list' function: %d\n", success_code);

    search_result_int_linked_list = search_int_linked_list(int_linked_list, TEST_INT);
    if (search_result_int_linked_list != NULL) printf("\nIf this '%d' equals to '%d' the code works correct.\n", search_result_int_linked_list->value, TEST_INT);
    else printf("\nIf 12 is not in your linked list code works.\n");

    success_code = length_int_linked_list(int_linked_list);
    if (success_code != -1) printf("\nThe lenght of 'int_linked_list' is '%d'\n", success_code);
    else printf("\nSomething went wrong. Success code is '%d'.\n",success_code);

    success_code = append_int_linked_list(int_linked_list, TEST_INT_2);
    printf("\nSuccess code of 'append_int_linked_list' function: %d", success_code);
    success_code = print_int_linked_list(int_linked_list);
    printf("\nSuccess code of 'print_int_linked_list' function: %d\n", success_code);

    success_code = delete_int_linked_list(int_linked_list, TEST_INT_2);
    printf("\nSuccess code of 'delete_int_linked_list' function: %d", success_code);
    success_code = print_int_linked_list(int_linked_list);
    printf("\nSuccess code of 'print_int_linked_list' function: %d\n", success_code);

    int_linked_list = free_int_linked_list(int_linked_list);
    if (int_linked_list == NULL) printf("\nFREE works.");



    /*
     *  ==================================================================================================================
     *  TEST CODES FOR char_stack_t , char_stack_element_t AND char_stack_node_t DATA TYPES AND THEIR OPERATION FUNCTIONS.
     *  ==================================================================================================================
     */

    char_stack_t *char_stack = NULL;

    char_stack = get_char_stack_t(char_stack);

    success_code = print_char_stack_t(char_stack);
    printf("\nSuccess code of 'print_char_stack_t' function: %d\n", success_code);

    success_code = length_char_stack_t(char_stack);
    if (success_code != -1) printf("\nThe lenght of 'char_stack' is '%d'\n", success_code);
    else printf("\nSomething went wrong. Success code is '%d'.\n",success_code);

    success_code = push_char_stack_t(char_stack, TEST_CHAR);
    print_char_stack_t(char_stack);
    printf("\nSuccess code of 'push_char_stack_t' function: %d\n", success_code);
    printf("\nSuccess code of 'print_char_stack_t' function: %d\n", success_code);

    success_code = length_char_stack_t(char_stack);
    if (success_code != -1) printf("\nThe lenght of 'char_stack' is '%d'\n", success_code);
    else printf("\nSomething went wrong. Success code is '%d'.\n",success_code);

    element = pop_char_stack_t(char_stack);
    printf("\nIf this '%c' equals to '%c' the code works correct.", element, TEST_CHAR);
    print_char_stack_t(char_stack);
    printf("\nSuccess code of 'print_char_stack_t' function: %d\n", success_code);

    success_code = length_char_stack_t(char_stack);
    if (success_code != -1) printf("\nThe lenght of 'char_stack' is '%d'\n", success_code);
    else printf("\nSomething went wrong. Success code is '%d'.\n",success_code);

    char_stack = free_char_stack_t(char_stack);
    if (char_stack == NULL) printf("\nFREE works.");

    return 0;
}