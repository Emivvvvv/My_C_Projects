/*
 *  Programmer: Emirhan TALA             Date completed: Oct 10, 2022
 *
 *  A program to grade an n-question multiple-choice exam (for n between 5 and 50).
 *  Program provides the most frequently missed questions.
 */

#include <stdio.h>

void fget_num_of_questions(FILE*, int*);
void fget_answer_key(FILE* , char[], int[], int);
void fget_answers_and_put_report(FILE* , FILE* , char [], const char [], int [], int);

int main() {
    int num_of_questions;           // how many questions are there in this exam

    // Opens examdat(read) and report(write) files
    FILE* examdat = fopen("/Users/emivvvvv/CLionProjects/Exam_Grader/examdat.txt", "r");
    FILE* report = fopen("/Users/emivvvvv/CLionProjects/Exam_Grader/report.txt", "w");

    //  Gets number of questions
    fget_num_of_questions(examdat, &num_of_questions);

    //  Creates arrays with using number of questions
    char correct_answer_key[num_of_questions];      //  Correct answer key
    int missed_questions[num_of_questions];         //  How many times that question is missed (if 4 student did wrong question 3 missed_questions[2] = 4)
    char student_answer_key[num_of_questions];      //  Students answer key

    //  Gets correct answer key
    fget_answer_key(examdat, correct_answer_key, missed_questions, num_of_questions);

    //  Gets each student answers, calculates correctness rate, finds questions miss rate and prints to output file report.txt
    fget_answers_and_put_report(examdat, report, student_answer_key, correct_answer_key, missed_questions, num_of_questions);

    //  Closes input and output files
    fclose(examdat);
    fclose(report);
    return 0;
}

/*
 * Gets number of questions and saves num_of_quesiton variable
 * Pres: examdat file must be open, num_of_questions variable has declared and putted address of that integer as an argument.
 */
void
fget_num_of_questions(FILE* examdat, int *num_of_questions)
{

    fscanf(examdat, "%d", num_of_questions);
}

/*
 * Gets correct question key and saves it to correct_answer_key array.
 * Sets every value in missed_questions array to zero.
 *
 *  Pres: examdat file must be open, int num_of_question, int missed_questions[], char correct_answer_key[] must be declared.
 */
void
fget_answer_key(FILE* examdat, char correct_answer_key[], int missed_questions[], int num_of_questions)
{
    int iterator;

    for (iterator = 0; iterator < num_of_questions; iterator++){
        missed_questions[iterator] = 0;
    }
    for(iterator = 0; iterator < num_of_questions; iterator++){
        fscanf(examdat, " %c", &correct_answer_key[iterator]);
    }
}

/*
 * Gets each student answers, calculates correctness rate, finds questions miss rate and prints to output file report.txt
 *
 *  Pres: examdat file must be open, int num_of_question, int missed_questions[], char correct_answer_key[], char student_answer_key must be declared.
 */
void
fget_answers_and_put_report(FILE* examdat, FILE* report, char student_answer_key[], const char correct_answer_key[], int missed_questions[], int num_of_questions){
    int wrong_counter, iterator, status, student_id;
    do {
        wrong_counter = 0;
        status = fscanf(examdat, "%d", &student_id);
        if (status != EOF) {
            fprintf(report, "%d ", student_id);
            for(iterator = 0; iterator < num_of_questions; iterator++){
                fscanf(examdat, " %c", &student_answer_key[iterator]);
                if (correct_answer_key[iterator] != student_answer_key[iterator]) {
                    missed_questions[iterator]++;
                    wrong_counter++;
                }
            }
        } else {
            break;
        }
        fprintf(report, " %%%.2f\n", ((double)(num_of_questions - wrong_counter) * 100) / num_of_questions);
    } while (1);

    fprintf(report, "\nQUESTION:  1 2 3 4 5 6 7 8 9");
    fprintf(report, "\nMISSED BY:");

    for (iterator = 0; iterator < num_of_questions; iterator++){
        fprintf(report, " %d", missed_questions[iterator]);
    }
    fprintf(report, "\n");
}
