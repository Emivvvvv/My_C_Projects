/*
 *  Programmer: Emirhan TALA             Date completed: Oct 13, 2022
 *
 *  This program displays the total number of vowels and consonants
 *  in the sentence (string) given as an input by user.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRLEN 100

int main() {

    char user_sentence[MAX_STRLEN];     //  User input sentence variable
    char temp[MAX_STRLEN];              //  Temp string for calculating various calculations on user input

    int sentence_length,                //  User input sentence length
        vowel_count = 0,                //  Vowel count of user input sentence
        consonant_count = 0,            //  Consonant count of user input sentence
        iterator;                       //  Iterator of for loop

    //  Gets input from the user
    printf("WARNING: DON'T TYPE ANYTHING LONGER THAN 99 LETTERS!!!!!!!");
    printf("Enter a sentence\n=> ");
    gets(user_sentence);

    //  Saver user input sentences length to the sentence_length variable
    sentence_length = strlen(user_sentence);

    //  Looks for each letter in the sentence and if it finds a vowel increases vowel_count variable or if it finds a consonant increases consonant_count variable.
    for (iterator = 0; iterator < sentence_length; iterator++){
        strcpy(temp, user_sentence);
        if (tolower(temp[iterator]) == 'a' || tolower(temp[iterator]) == 'e'  || tolower(temp[iterator]) == 'i' || tolower(temp[iterator]) == 'o'  || tolower(temp[iterator]) == 'u'){
            vowel_count++;
        } else if (isalpha(temp[iterator])){
            consonant_count++;
        }
    }

    //  Prints number vowel and consonant with the original user input.
    printf("'%s' contains %d vowels and %d consonants.", user_sentence, vowel_count, consonant_count);

    return 0;
}
