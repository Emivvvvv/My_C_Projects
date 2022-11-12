/*  Implementation file ddslib.c
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

#include "ddslib.h"

/*
 *  Prints all the items in the int type linked list.
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
int
print_int_linked_list(int_linked_list_node_t *int_linked_list_p)
{
    int_linked_list_node_t *temp;

    if (int_linked_list_p != NULL){
        if (int_linked_list_p->link_p != NULL){
            printf("\n[");
            do {
                temp = int_linked_list_p->link_p;
                printf("%d, ", int_linked_list_p->value);
                int_linked_list_p = temp;
            } while (temp->link_p != NULL);
            printf("%d]", int_linked_list_p->value);
        } else printf("[%d]", int_linked_list_p->value);
        return 1;
    } else return 0;
}

/*
 *  Frees all the items in the int type linked list.
 *
 *  Returns NULL pointer;
 */
extern int_linked_list_node_t*
free_int_linked_list(int_linked_list_node_t *int_linked_list_p)
{
    int_linked_list_node_t *temp;

    if (int_linked_list_p != NULL) {
        do {
            temp = int_linked_list_p->link_p;
            free(int_linked_list_p);
            int_linked_list_p = temp;
        } while (temp != NULL);
    }

    return NULL;
}

/*
 *  Scans for the integer inputs separated by spaces
 *  from the user and returns the head pointer of the int linked list
 *  containing the user input integers.
 *
 *  Returns the head pointer if the process successfully completed and NULL pointer if something wrong happened.
 */
int_linked_list_node_t*
get_int_linked_list(int_linked_list_node_t *int_linked_list_p)
{
    int input_number;

    int_linked_list_node_t *new_int_linked_list_node, *loop_int_linked_list_node;
    int_linked_list_p = (int_linked_list_node_t *) malloc(sizeof (int_linked_list_node_t));
    new_int_linked_list_node = (int_linked_list_node_t *) malloc(sizeof (int_linked_list_node_t));

    int_linked_list_p->value = 31;
    int_linked_list_p->link_p = new_int_linked_list_node;
    new_int_linked_list_node->value = 69;
    new_int_linked_list_node->link_p = NULL;

    printf("Enter integers seperated by spaces and enter '%d' to finish the input process. ( 31 and 69 is already included :) )\n> ", SENT_INT);
    for (scanf("%d", &input_number); input_number != SENT_INT;scanf("%d", &input_number))
    {
        loop_int_linked_list_node = (int_linked_list_node_t *) malloc(sizeof (int_linked_list_node_t));
        loop_int_linked_list_node->value = input_number;
        loop_int_linked_list_node->link_p = NULL;
        new_int_linked_list_node->link_p = loop_int_linked_list_node;
        new_int_linked_list_node = loop_int_linked_list_node;
    }

    return int_linked_list_p;
}

/*
 *  Searches the search_value in the int linked list.
 *
 *  Returns the pointer to the value that found if the process successfully completed and NULL pointer if the item is not
 *  in the int linked list or something wrong happened.
 */
int_linked_list_node_t*
search_int_linked_list(int_linked_list_node_t *int_linked_list_p, int search_value)
{
    if (int_linked_list_p != NULL) {
        while (int_linked_list_p->value != search_value)
        {
            int_linked_list_p = int_linked_list_p->link_p;
            if (int_linked_list_p == NULL) return NULL;
        }
        return int_linked_list_p;
    } else return NULL;
}

/*
 *  Finds the length of the int type linked list.
 *
 *  Returns the length of the int type linked list if the process successfully completed and -1 if something wrong happened.
 */
int
length_int_linked_list(int_linked_list_node_t *int_linked_list_p)
{
    int length = 0;

    if (int_linked_list_p != NULL){
        do {
            length++;
            int_linked_list_p = int_linked_list_p->link_p;
        } while (int_linked_list_p != NULL);
        return length;
    } else return -1;
}

/*
 *  Adds the append_value to the end of the int linked list.
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
int
append_int_linked_list(int_linked_list_node_t *int_linked_list_p, int append_value)
{
    int_linked_list_node_t *temp, *new_node;
    new_node = (int_linked_list_node_t*)malloc(sizeof (int_linked_list_node_t));
    new_node->value = append_value;
    new_node->link_p = NULL;

    if (int_linked_list_p != NULL) {
        do {
            temp = int_linked_list_p->link_p;
            int_linked_list_p = temp;
        } while (temp->link_p != NULL);
        int_linked_list_p->link_p = new_node;
        return 1;
    } else return 0;
}

/*
 *  Deletes the first item equal to delete_value variable.
 *
 *  Returns 1 if the process successfully completed, 0 if the item couldn't find in the list and -1 if something went wrong.
 */
int
delete_int_linked_list(int_linked_list_node_t *int_linked_list_p, int delete_value)
{
    int_linked_list_node_t *check;

    if (int_linked_list_p != NULL) {
        while (int_linked_list_p->value != delete_value)
        {
            check = int_linked_list_p;
            int_linked_list_p = int_linked_list_p->link_p;
            if (int_linked_list_p == NULL) return 0;
        }
        check->link_p = int_linked_list_p->link_p;
        free(int_linked_list_p);
        return 1;
    } else return -1;
}





/*
 *  Prints all the items in the char type stack
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
int
print_char_stack_t(char_stack_t *char_stack_p)
{
    char_stack_node_t *temp;

    if (char_stack_p != NULL){
        if (char_stack_p->top_p != NULL){
            temp = char_stack_p->top_p;
            printf("\n");
            do{
                printf("|%c|\n",temp->element);
                temp = temp->link_p;
            } while (temp->link_p != NULL);
            printf("|%c|\n", temp->element);
            printf("---");
        }else printf("Stack is empty.");
        return 1;
    }else return 0;
}

/*
 *  Frees all the items in the char type stack
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
char_stack_t*
free_char_stack_t(char_stack_t *char_stack_p)
{
    char_stack_node_t *temp, *temp2;

    if (char_stack_p != NULL){
        temp = char_stack_p->top_p;
        free(char_stack_p);
        do{
            temp2 = temp->link_p;
            free(temp);
            temp = temp2;
        } while(temp2 != NULL);

        return NULL;
    }
}

/*
 *  Scans for the char inputs separated by spaces
 *  from the user and returns the head pointer of char type stack
 *  containing the user input characters. (FIRST IN LAST OUT)
 *
 *  Returns the head pointer if the process successfully completed and NULL pointer if something wrong happened.
 */
char_stack_t*
get_char_stack_t(char_stack_t *char_stack_p)
{
    char input_char;
    char_stack_node_t *char_stack_node_p;
    char_stack_p = (char_stack_t*) malloc(sizeof (char_stack_t));
    char_stack_p->top_p = NULL;

    printf("Enter characters seperated by spaces and enter '%c' to finish the input process. ( B is already included )\n> ", SENT_CHAR);
    for (scanf(" %c", &input_char); input_char != SENT_CHAR ;scanf(" %c", &input_char))
    {
        printf("\nDEBUG INTPUT CHAR %c\n", input_char);
        char_stack_node_p = (char_stack_node_t*) malloc(sizeof(char_stack_node_t));
        char_stack_node_p->element = input_char;
        char_stack_node_p->link_p = char_stack_p->top_p;
        char_stack_p->top_p = char_stack_node_p;
    }

    return char_stack_p;

}

/*
 *  Finds the length of the char type stack.
 *
 *  Returns the length of the char type stack if the process successfully completed and -1 if something wrong happened.
 */
int
length_char_stack_t(char_stack_t *char_stack_p)
{
    int length = 0;
    char_stack_node_t *temp;

    if (char_stack_p != NULL){
        temp = char_stack_p->top_p;
        while(temp != NULL){
            length++;
            temp = temp->link_p;
        }
        return length;
    } else return -1;
}

/*
 *  Puts the push_value char to the top of the stack
 *
 *  Returns 1 if the process successfully completed and 0 if something wrong happened.
 */
int
push_char_stack_t(char_stack_t *char_stack_p, char_stack_element_t push_value)
{
    char_stack_node_t *temp;

    if (char_stack_p != NULL){
        temp = (char_stack_node_t*) malloc(sizeof (char_stack_node_t));
        temp->element = push_value;
        temp->link_p = char_stack_p->top_p;
        char_stack_p->top_p = temp;
        return 1;
    } else return 0;
}

/*
 *  Pops the char from the top of the stack
 *
 *  Returns the character that popped from the stack if the process successfully completed and '\0' if something wrong happened or the stack is empty.
 */
char
pop_char_stack_t(char_stack_t *char_stack_p)
{
    char_stack_element_t pop_element;
    char_stack_node_t *temp;

    if (char_stack_p != NULL){
        if (char_stack_p->top_p != NULL){
            pop_element = char_stack_p->top_p->element;
            temp = char_stack_p->top_p;
            char_stack_p->top_p = char_stack_p->top_p->link_p;
            free(temp);
            return pop_element;
        } else return '\0';
    } else return '\0';
}