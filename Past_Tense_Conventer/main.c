/*
 *  Programmer: Emirhan TALA             Date completed: Oct 13, 2022
 *
 *  This program takes verbs and forms their past tense or says that verb
 *  might be irregular past tense.
 */

#include <stdio.h>
#include <string.h>


#define MAX_STRLEN 50

int main() {
    char verb[MAX_STRLEN];      //  verb user input variable
    char temp[MAX_STRLEN];      //  temp string variable to make varies calculations on verb string varible
    int verb_length;            //  verb length

    printf("Type a verb to convert it to it's past form.\nWARNING: DON'T TYPE AYTHING LONGER THAN 47 LETTERS!!!!!!!\n> ");
    gets(verb);
    verb_length = strlen(verb);

    //  Check if verb_length bigger than 3. If not quits.
    if (verb_length >= 3){
        //  Finds last 2 letters of verb word
        strcpy(temp, &verb[verb_length - 2]);

        //  Calculates and prints output
        if (strcmp(temp, "ss") == 0 || strcmp(temp, "gh") == 0) {
            verb[verb_length - 2] = '\0';
            printf("'%s' past tense version is => ",verb);
            strcat(verb, "ed");
            printf("%s\n", verb);
        } else {
            strcpy(temp, &verb[verb_length - 1]);
            if (strcmp(temp, "e") == 0) {
                printf("'%s' past tense version is => ",verb);
                strcat(verb, "d");
                printf("%s\n", verb);
            } else {
                printf("'%s' might be an irregular past tense.", verb);
            }
        }
    } else {
        printf("'%s' is not a valid input. A verb can't be smaller than 3 letter long!", verb);
    }
    return 0;
}
