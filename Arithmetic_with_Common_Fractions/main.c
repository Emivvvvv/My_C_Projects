/*
 *  Programmer: Emirhan TALA             Date completed: Oct 9, 2022
 *
 *  Adds, subtracts, multiplies and divides common fractions, displaying
 *  results in reduced form.
 */

#include <stdio.h>
#include <stdlib.h>


void scan_fraction(int *nump, int *denomp);
char get_operator(void);
void add_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp);
void multiply_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp);
void reduce_fraction(int *nump, int *denomp);
void print_fraction(int num, int denom);
int find_gcd (int n1, int n2);


int main() {
    int n1, d1;
    int n2, d2;
    char op;
    char again;
    int n_ans, d_ans;

    //  While the user wants to continue, gets and solves arthmetic problems with common fractions
    do{
        //  Gets a fraction problem
        scan_fraction(&n1, &d1);
        op = get_operator();
        scan_fraction(&n2, &d2);

        //  Computes the result
        switch (op) {
            case '+':
                add_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
                break;
            case '-':
                add_fractions(n1, d1, -n2, d2, &n_ans, &d_ans);
                break;
            case '*':
                multiply_fractions(n1, d1, n2, d2, &n_ans, &d_ans);
                break;
            case '/':
                multiply_fractions(n1, d1, d2, n2, &n_ans, &d_ans);
                break;
        }
        reduce_fraction(&n_ans, &d_ans);

        //  Displays problem and result
        printf("\n");
        print_fraction(n1, d1);
        printf(" %c ", op);
        print_fraction(n2, d2);
        printf(" = ");
        print_fraction(n_ans, d_ans);

        //  Ask user about doing another problem
        printf("\n Do you want to solve another problem? (y/n) => ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');
    return 0;
}

/*
 * Gets and returns a valid fraction as its result
 * A valid fraction is of this form: integer/positive integer
 */
void
scan_fraction(int *nump, int *denomp){
    char slash; //  character between numerator and denominator
    int status; //  status code returned by scanf indicating number of valid values obtained
    int error; //   flag indicating presence of an error
    char discard; //    unprocessed character from input line

    do{
        // No errors detected yet
        error = 0;

        //  Get a fraction from the user
        printf("Enter a common fraction as two integers separated by a slash> ");
        status = scanf("%d %c%d",nump ,&slash ,denomp);

        //  Validate the fraction
        if (status < 3) {
            error = 1;
            printf("Invalid-please read directions carefully!\n");
        } else if (slash != '/') {
            error = 1;
            printf("Invalid-separate numerator and denominator with a slash (/)!\n");
        } else if (*denomp < 0) {
            error = 1;
            printf("Invalid-denominator must be positive\n");
        }

        //  Discard extra input characters
        do {
            scanf("%c", &discard);
        } while (discard != '\n');
    } while (error);
}

/*
 * Gets and returns a valid arithmetic operator. Skips over newline
 * characters and permits reentry of operator in case of error.
 */
char
get_operator(void)
{
    char op;\

    printf("Enter an arithmetic operator (+, -, * or /)\n> ");
    for (scanf("%c", &op); op != '+' && op != '-' && op != '*' && op != '/'; scanf("%c", &op)){
        if (op != '\n') {
            printf("%c invalid, reenter operator (+, -, *, /)\n > ", op);
        }
    }
    return op;
}

/*
 * Adds fractions represented by pairs of integers.
 * Pre: n1, d1 ,n2, d2 are defined. n_ansp, and d_ansp are addresses of type int variables.
 * Post: sum of n1/d1 and n2/d2 is stored in variables pointed to by n_ansp and d_ansp. Result is nt reduced.
 */
void
add_fractions(int n1, int d1,                  // input - first fraction
              int n2, int d2,                  // input - second fraction
              int *n_ansp, int *d_ansp)        // output - produdct of 2 fractions
{
    int denom,
    numer,
    sign_factor;

    //  Finds common denominator
    denom = d1 * d2;

    //  Computes numerator
    numer = n1 * d2 + n2 * d1;

    //  Adjust sign (at most, numerator should be negative)
    if (numer * denom >= 0) sign_factor = 1;
    else sign_factor = -1;
    numer = sign_factor * abs(numer);
    denom = abs(denom);

    //  Returns result
    *n_ansp = numer;
    *d_ansp = denom;
}

/*
 * Multiplies fractions represented by pairs of integers.
 * Pre: n1, d1, n2 ,d2 are defined; n_ansp and d_ansp are addresses of type int variables.
 * Post: product of n1/d1 and n2/d2 is stored in variables pointed to by n_ansp and d_ansp.
 */
void
multiply_fractions(int n1, int d1,
                   int n2, int d2,
                   int *n_ansp,
                   int *d_ansp)
{
    int numer, denomer;
//  Multiplies n1 with n2 and d1 with d2
numer = n1 * n2;
denomer = d1 * d2;

//  Defines output arguments
*n_ansp = numer;
*d_ansp = denomer;
}

/*
 * Finds greatest common divisor of two integers
 */
int
find_gcd (int n1, int n2) // input - two integers
{
    int gcd, test_gcd;

    for (test_gcd = 1; test_gcd <= n1 && test_gcd <= n2; test_gcd++){
        if ((n1 % test_gcd == 0) && (n2 % test_gcd == 0)){
            gcd = test_gcd;
        }
    }

    return gcd;
}

/*
 * Reduces a fraction by dividing its numerator and denominator by their
 * greatest common divisor.
 */
void
reduce_fraction(int *nump,              //  input/output -
                int *denomp)            //  numerator and denominator of fraction
{
    int gcd;        //  greatest common divisor of numerator & denominator

    gcd = find_gcd(*nump, *denomp);
    *nump = *nump / gcd;
    *denomp = *denomp / gcd;
}

/*
 * Displays pair of integers as fraction.
 */
void
print_fraction(int num, int denom) // input -numerator & denominator
{
    if (denom == 1) {      //   don't writes denom if denom = 1
        printf("%d", num);
    } else {
        printf("%d/%d", num, denom);
    }
}