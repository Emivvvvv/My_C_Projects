/*  Header file ddslib.h
 *
 *  Programmer: Emirhan TALA             Date completed: Nov 12, 2022
 *
 *
 *
 *  Type int_linked_list_node_t has these components:
 *      int value, int_linked_list_node_s *link_p
 *
 *  Type int_linked_list_node_t Operators:
 *      print_int_linked_list, free_int_linked_list, get_int_linked_list, search_int_linked_list, length_int_linked_list, append_int_linked_list, delete_int_linked_list
 *
 *
 *  Type char_stack_element_t is char
 *
 *  Type char_stack_node_t has these components:
 *      char_stack_element_t element, char_stack_node_s *link_p
 *
 *  Type char_stack_t has these components:
 *      char_stack_node_t *top_p
 *
 *  Type char_stack_t Operators:
 *      print_char_stack_t, free_char_stack_t, get_char_stack_t, length_char_stack_t, push_char_stack_t, pop_char_stack_t
 *
 */

#ifndef DYNAMIC_DATA_STRUCTURES_LIBRARY_DDSLIB_H
#define DYNAMIC_DATA_STRUCTURES_LIBRARY_DDSLIB_H

#include <stdio.h>
#include <stdlib.h>

#define SENT_INT -999
#define SENT_CHAR 'q'


typedef struct int_linked_list_node_s {
    int value;
    struct int_linked_list_node_s *link_p;
} int_linked_list_node_t;


/*
 *  Prints all the items in the int type linked list.
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
extern int
print_int_linked_list(int_linked_list_node_t *int_linked_list_p);

/*
 *  Frees all the items in the int type linked list.
 *
 *  Returns NULL pointer to prevent further errors.
 */
extern int_linked_list_node_t*
free_int_linked_list(int_linked_list_node_t *int_linked_list_p);

/*
 *  Scans for the integer inputs separated by spaces
 *  from the user and returns the head pointer of the int linked list
 *  containing the user input integers.
 *
 *  Returns the head pointer if the process successfully completed and NULL pointer if something wrong happened.
 */
extern int_linked_list_node_t*
get_int_linked_list(int_linked_list_node_t *int_linked_list_p);

/*
 *  Searches the search_value in the int linked list.
 *
 *  Returns the pointer to the value that found if the process successfully completed and NULL pointer if the item is not
 *  in the int linked list or something wrong happened.
 */
extern int_linked_list_node_t*
search_int_linked_list(int_linked_list_node_t *int_linked_list_p, int search_value);

/*
 *  Finds the length of the int type linked list.
 *
 *  Returns the length of the int type linked list if the process successfully completed and -1 if something wrong happened.
 */
extern int
length_int_linked_list(int_linked_list_node_t *int_linked_list_p);

/*
 *  Adds the append_value to the end of the int linked list.
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
extern int
append_int_linked_list(int_linked_list_node_t *int_linked_list_p, int append_value);

/*
 *  Deletes the first item equal to delete_value variable.
 *
 *  Returns 1 if the process successfully completed and 0 if the item couldn't find in the list.
 */
extern int
delete_int_linked_list(int_linked_list_node_t *int_linked_list_p, int delete_value);


typedef char char_stack_element_t;

typedef struct char_stack_node_s {
    char_stack_element_t element;
    struct char_stack_node_s *link_p;
} char_stack_node_t;

typedef struct {
    char_stack_node_t *top_p;
} char_stack_t;

/*
 *  Prints all the items in the char type stack
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
extern int
print_char_stack_t(char_stack_t *char_stack_p);

/*
 *  Frees all the items in the char type stack
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
extern char_stack_t*
free_char_stack_t(char_stack_t *char_stack_p);

/*
 *  Scans for the char inputs separated by spaces
 *  from the user and returns the head pointer of char type stack
 *  containing the user input characters. (FIRST IN LAST OUT)
 *
 *  Returns the head pointer if the process successfully completed and NULL pointer if something wrong happened.
 */
extern char_stack_t*
get_char_stack_t(char_stack_t *char_stack_p);

/*
 *  Finds the length of the char type stack.
 *
 *  Returns the length of the char type stack if the process successfully completed and -1 if something wrong happened.
 */
extern int
length_char_stack_t(char_stack_t *char_stack_p);

/*
 *  Puts the push_value char to the top of the stack
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
extern int
push_char_stack_t(char_stack_t *char_stack_p, char_stack_element_t push_value);

/*
 *  Pops the char from the top of the stack
 *
 *  Returns the character that popped from the stack if the process successfully completed and '\0' if something wrong happened or the stack is empty.
 */
extern char
pop_char_stack_t(char_stack_t *char_stack_p);

#endif //DYNAMIC_DATA_STRUCTURES_LIBRARY_DDSLIB_H
