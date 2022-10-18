/*
 *  Programmer: Emirhan TALA             Date completed: Oct 18, 2022
 *
 *  A recursive palindrome checker.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRLEN 100
#define TRUE 1
#define FALSE 0
void input_styler(char [MAX_STRLEN], char [MAX_STRLEN]);
int palindrome_checker(const char [MAX_STRLEN], int, int);

int main() {
    int is_palindrome;

    //  String variables.
    char user_input[MAX_STRLEN];            //  virgin user input.
    char styled_user_input[MAX_STRLEN];     //  styled(not virgin lol) user input.

    //  Gets the input string from the user and saves it in user_input variable.
    printf("Type a word or sentence to check if it is a palindrome!(LESS THAN 99 LETTER!!!!)\n> ");
    gets(user_input);

    //  Styles the user input.
    input_styler(user_input, styled_user_input);

    //  Checks if string is a palindrome or not.
    is_palindrome = palindrome_checker(styled_user_input,0 , strlen(styled_user_input) - 1);

    //  Prints the result to the user.
    if (is_palindrome)
        printf("\n'%s' is a palindrome!", user_input);
    else
        printf("\n'%s' is not a palindrome!", user_input);
    return 0;
}


/*
 * deletes all the not alphabet letters and number and makes all the letter lower case.
 *
 * Pre: all variables are defined and user_input has the user typed input.
 * Post: user_input is not changed and styled_user_input has the styled data
 * EX: user_input = MaDam I'm aDam  --> styled_user_input = madamimadam
 */
void
input_styler(char user_input[MAX_STRLEN], char styled_user_input[MAX_STRLEN])
{
    int input_length, iterator,
    skipped;                                    //  get increased if user input has non alphabet letter or number

    char temp_user_input[MAX_STRLEN] = {'\0'};  //  a string full of '\0' to escape bigger skipped value

    input_length = strlen(user_input);
    strncpy(temp_user_input, user_input, input_length);     //  copies the user input to temp user input to escape bigger skipped value

    skipped = 0;

    for (iterator = 0; iterator < input_length; iterator++)
    {
        if (!isalnum(temp_user_input[iterator + skipped]) && temp_user_input[iterator + skipped] != '\0'){
            skipped++;
        }
        strcpy(&styled_user_input[iterator], &temp_user_input[iterator + skipped]);
        styled_user_input[iterator] = tolower(styled_user_input[iterator]);
    }
    styled_user_input[input_length - skipped] = '\0';
}


/*
 * Starts from the first and last letter and checks if this string is a palindrome.
 *
 * Pre: styled_user_input is styled version of user input, start is 0 and the end is styled_user_input length.
 * Post: if string is palindrome returns TRUE else returns FALSE
 */
int
palindrome_checker(const char styled_user_input[MAX_STRLEN], int start, int end)
{
    int result;

    if (styled_user_input[start] != styled_user_input[end]){
        return FALSE;
    } else if ( start == end || start - 1 == end ){
        return TRUE;
    } else {
        result = palindrome_checker(styled_user_input, start + 1, end - 1);
    }

    return result;
}
