/*
 *  Programmer: Emirhan TALA             Date completed: Oct 10, 2022
 *
 *  Hangman game written in C
 */


#include <stdio.h>
#define TRUE 1
#define FALSE 0

int check(int word_length, char guessed_character, const char word[], char guessed[], int mistake_counter);
void print_screen(int mistake_counter, int word_length, char guessed[]);
int game_status(int word_length, int mistake_counter, const char guessed[]);

int main() {
    char word[] = {'g','o','o','f','y','a','s','s'};
    char guessed[] = {'_','_','_','_','_','_','_','_'};
    char guessed_character;
    int mistake_counter = 0;    //  increases if user makes a mistake

    int word_length = 8;        //  hidden words length
    int is_game_on = TRUE;      //  controls game's while loop

    printf("Welcome to the Hangman game!\nYou can make 5 mistakes. If you do 6th one you die XO.\nPlease just enter lower case characters.\n\n");

    while (is_game_on){
        //  Gets guess from the user
        printf("Guess a character > ");
        scanf(" %c", &guessed_character);

        //  Checks user's input if it is valid or not
        mistake_counter = check(word_length, guessed_character, word, guessed, mistake_counter);

        //  Prints game screen
        print_screen(mistake_counter, word_length, guessed);

        //  Checks is game finished or not
        is_game_on = game_status(word_length, mistake_counter, guessed);
    }
    return 0;
}

/*
 * Checks player guessed_character if it is inside the word.
 * If no increments mistake_counter and returns it.
 *
 * Pres: int mistake_counter, int word_length, char guessed[], char word[] are must be declared
 * Post: returns int mistake_counter.
 */
int check(int word_length, char guessed_character, const char word[], char guessed[], int mistake_counter)
{
    int found_any, iterator;

    found_any = FALSE;
    for (iterator = 0; iterator < word_length; iterator++){
        if (guessed_character == word[iterator]){
            guessed[iterator] = word[iterator];
            found_any = TRUE;
        }
    }
    if (found_any) {
        printf("\nYESSS!!! '%c' IS IN THE WORD\n\n", guessed_character);
    } else {
        printf("\nBUZZ!!! '%c' ISN'T IN THE WORD\n\n", guessed_character);
        mistake_counter++;
    }

    return mistake_counter;
}

/*
 * Checks if player won or lose. Controls the game should continue or not.
 *
 * Pres: int mistake_counter, int word_length, char guessed[] are must be declared
 */
int game_status(int word_length, int mistake_counter, const char guessed[])
{
    int won_check, iterator, is_game_on;

    is_game_on = TRUE;

    //checks if player won
    won_check = TRUE;
    for (iterator = 0; iterator < word_length; iterator++){
        if (guessed[iterator] == '_'){
            won_check = FALSE;
        }
    }
    if (won_check) {
        printf("\n\nCONGRALATIOTIONS YOU WON!!!\nYou made %d mistakes.", mistake_counter);
        is_game_on = FALSE;
    }

    //checks if player lost
    if (mistake_counter == 6){
        printf("\n\nYOU DIED! BRUHHHH\n");
        is_game_on = FALSE;
    }

    return is_game_on;
}

/*
 * Prints game screen as fallows => man, hidden word
 *
 * Pres: int mistake_counter, int word_length, char guessed[] are must be declared
 */
void print_screen(int mistake_counter, int word_length, char guessed[])
{
    int iterator;

    //prints
    switch (mistake_counter) {
        case 0:
            printf(" |======\n");
            printf(" |   |  \n");
            printf(" |      \n");
            printf(" |      \n");
            printf("_|_     \n");
            break;
        case 1:
            printf(" |======\n");
            printf(" |   |  \n");
            printf(" |   O  \n");
            printf(" |      \n");
            printf("_|_     \n");
            break;
        case 2:
            printf(" |======\n");
            printf(" |   |  \n");
            printf(" |   O  \n");
            printf(" |   |  \n");
            printf("_|_     \n");
            break;
        case 3:
            printf(" |======\n");
            printf(" |   |  \n");
            printf(" |   O  \n");
            printf(" |  /|  \n");
            printf("_|_     \n");
            break;
        case 4:
            printf(" |======\n");
            printf(" |   |  \n");
            printf(" |   O  \n");
            printf(" |  /|\\ \n");
            printf("_|_     \n");
            break;
        case 5:
            printf(" |======\n");
            printf(" |   |  \n");
            printf(" |   O  \n");
            printf(" |  /|\\ \n");
            printf("_|_ /    \n");
            break;
        case 6:
            printf(" |======\n");
            printf(" |   |  \n");
            printf(" |   O  \n");
            printf(" |  /|\\ \n");
            printf("_|_ / \\ \n");
            break;
        default:
            printf("BRUUUHUHUHUHUUHHH!!!!! SOMETHING WENT WRONG!!!!!");
    }
    for (iterator = 0; iterator < word_length; iterator++){
        printf("%c ", guessed[iterator]);
    }
    printf("\n");
}