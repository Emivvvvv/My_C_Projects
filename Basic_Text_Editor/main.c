/*
 *  Programmer: Emirhan TALA             Date completed: Oct 10, 2022
 *
 *  Performs basic text editing operations on a source string
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100
#define NOT_FOUND -1

char *delete(char *source, int index, int n);
char *do_edit(char *source, char command);
char get_command(void);
char *insert(char *source, const char *to_insert, int index);
int pos(const char *source, const char *to_find);
void print_index(const char *source);
void make_upper_or_lower(char *source, char *str, int index, char command);

int main() {
    char source[MAX_LEN], command;
    printf("Enter the source string:\n> ");
    gets(source);
    printf("\n");
    print_index(source);
    printf("New source:  %s\n\n", source);

    for (command = get_command();
         command != 'Q';
         command = get_command()){
        do_edit(source, command);
        print_index(source);
        printf("New source:  %s\n\n", source);
    }

    printf("String after editing: %s\n", source);
    return 0;
}


/*
 * Returns source after deleting n characters beginning with source[index].
 * If source is too short for full deletion, as many characters are
 * deleted as possible.
 *
 * Pre: All parameters are defined and
 *      strlen(source) - index - n < MAX_LEN
 * Post: source is modified and returned
 */
char*
delete(char *source, // i/o - string from which to delete part
       int index,    // i - index of first char to delete
       int n)        // i - number of chars to delete
{
    char rest_str[MAX_LEN]; //  Copy of source substring following characters to delete

    //  If there are no characters in source following portion to delete, delete rest of string
    if (strlen(source) <= index + n) {
        source[index] = '\0';

    //  Otherwise, copy the portion following the portion
    //  to delete and place it in source beginning at the index position
    } else {
        stpcpy(rest_str, &source[index + n]);
        strcpy(&source[index], rest_str);
    }

    return source;
}


/*
 * Performs the edit operation specified by command
 * Pre: command and source are defined.
 * Post: After scanning additional information needed, performs a deletion (command = 'D') or insertion (command = 'I') or
 * (possibly modified) source.
 */
char*
do_edit(char *source,
        char command)
{
    char str[MAX_LEN], chr; //   work string
    int index;

    switch (command) {
        case 'D':
            printf("String to delete> ");
            gets(str);
            index = pos(source, str);
            if (index == NOT_FOUND)
                printf("'%s' not found\n", str);
            else
                delete(source, index, strlen(str));
            break;

        case 'I':
            printf("String to insert> ");
            gets(str);
            printf("Position of insertion> ");
            scanf("%d", &index);
            insert(source, str, index);
            break;

        case 'F':
            printf("String to find> ");
            gets(str);
            index = pos(source, str);
            if (index == NOT_FOUND)
                printf("'%s' not found\n", str);
            else
                printf("'%s' found at position %d\n", str, index);
            break;
        case 'U':
        case 'L':
            printf("Character to make Upper/Lower case> ");
            gets(str);
            index = pos(source, str);
            if (index == NOT_FOUND)
                printf("'%s' not found\n", str);
            else if (command == 'U') {
                make_upper_or_lower(source, str, index, command);
            } else if (command == 'L') {
                make_upper_or_lower(source, str, index, command);
            }
            break;
        default:
            printf("Invalid edit command '%c'\n", command);
    }

    return source;
}


/*
 * Prompt for and get a character representing an edit command and
 * convert it to uppercase. Return the uppercase character and ignore
 * rest of input line.
 */
char
get_command(void)
{
    char command, ignore;

    printf("Enter D(Delete), I(Insert), F(Find), U(Make upper case), L(Make lower case) or Q(Quit)> ");
    scanf(" %c", &command);

    do {
        ignore = getchar();
    } while (ignore != '\n');

    return (toupper(command));
}


/*
 * Returns source after inserting to_insert at position index of
 * source. If source[index] doesn't exist, adds to_insert at end of
 * source.
 * Pre: all parameters are defined, space available for source is
 *      enough to accommodate insertion, and
 *      strlen(source) - index - n < MAX_LEN
 * Post: source is modified and returned
 */
char*
insert(char *source,
       const char *to_insert,
       int index)
{
    char rest_str[MAX_LEN]; //  copy of rest of source beginning with source[index]

    if (strlen(source) <= index) {
        strcat(source, to_insert);
    } else {
        strcpy(rest_str, &source[index]);
        strcpy(&source[index], to_insert);
        strcat(source, rest_str);
    }

    return source;
}


/*
 * Returns index of first occurrence of to_find in source or
 * value of NOT_FOUND if to_find is not in source.
 * Pre: both parameters are defined
 */
int
pos(const char *source,
    const char *to_find)
{
    int i = 0, find_len, found = 0, position;
    char substring[MAX_LEN];

    find_len = strlen(to_find);
    while (!found && i <= strlen(source) - find_len) {
        strncpy(substring, &source[i], find_len);
        substring[find_len] = '\0';

        if (strcmp(substring, to_find) == 0)
            found = 1;
        else
            ++i;
    }

    if (found)
        position = i;
    else
        position = NOT_FOUND;

    return position;
}

/*
 * Prints index number top of the characters of source string
 *
 * Pre: source is defined.
 */
void
print_index(const char *source)
{
    int i, j;

    j = 0;
    printf("            ");
    for (i = 0; i < strlen(source) + 1; i++) {
        if (i % 10 == 0 && i != 0){
            j++;
        }
        if (j != 0) {
            printf("%d", j);
        } else {
            printf(" ");
        }
    }
    printf("\n");


    j = 0;
    printf("            0");
    for (i = 0; i < strlen(source); i++) {
        if (j == 9){
            j = -1;
        }
        j++;
        printf("%d", j);
    }
    printf("\n");
}

/*
 * Returns source after making that string upper case or lower case of found str.
 *
 * Pre: All parameters are defined
 * Post: source is modified and returned
 */
void
make_upper_or_lower(char *source, char *str, int index, char command)
{
    char to_insert[MAX_LEN] = {"\0"};
    int iterator;

    for (iterator = 0; iterator < strlen(str); iterator++)
    {
        if (command == 'U') {
            str[iterator] = toupper(str[iterator]);
        } else if (command == 'L') {
            str[iterator] = tolower(str[iterator]);
        }
        to_insert[0] = str[iterator];
        to_insert[1] = '\0';
        delete(source, index + iterator, 1);
        insert(source, to_insert, index + iterator);
    }
}