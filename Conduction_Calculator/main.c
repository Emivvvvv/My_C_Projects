/*
 *  Programmer: Emirhan TALA             Date completed: Oct 9, 2022
 *
 * This program solves simple conduction problems with using this formula
 *      kA(T2-T1)       A: side area
 * H = -----------      (T2 - T1): temperature difference between two sides
 *          x           x: distance between two sides
 *                      k: coefficient of thermal conductivity for particular substance
 *                      H: rate of heat transfer
 */

#include <stdio.h>
#include <math.h>

void get_data(double *, double **);

int main() {
    double h, k ,a ,t1, t2, x;
    double* unknown_variable;

    unknown_variable = &h;

    //  Prints information about unknown variable
    printf("Respond to the prompts with the data known. For the unknown quantity, enter a question mark (?).\n");

    //  Gets known and unknown data from user.
    printf("\nRate of heat transfer (watts) >> ");
    get_data(&h, &unknown_variable);

    printf("\nCoefficient of thermal conductivity (W/m-k) >> ");
    get_data(&k, &unknown_variable);

    printf("\nCross-sectional area of conductor (m^2) >> ");
    get_data(&a, &unknown_variable);

    printf("\nTemperature on one side (K) >> ");
    get_data(&t2, &unknown_variable);

    printf("\nTemperature on other side (K) >> ");
    get_data(&t1, &unknown_variable);

    printf("\nThickness of conductor (m) >> ");
    get_data(&x, &unknown_variable);

    //  Prints formula
    printf("\n     kA(T2 - T1) \n");
    printf("H = -------------\n");
    printf("          X      \n");

    //  if-else conditions to find the formula that calculates unknown variable
    //  and prints unknown variable
    if (*unknown_variable == h) {
        h = (k * a * (t2 - t1)) / x;
        printf("Rate of heat transfer (watts) is %f\n", h);
    } else if (*unknown_variable == k) {
        k = 1/(( a * (t2 - t1)) / (x * h));
        printf("Coefficient of thermal conductivity (W/m-k) is %f\n", h);
    } else if (*unknown_variable == a) {
        a = 1/(( k * (t2 - t1)) / (x * h));
        printf("Cross-sectional area of conductor (m^2) is %f\n", h);
    } else if (*unknown_variable == t1) {
        t1 = fabs(((h * x) / (k * a)) - t2);
        printf("Temperature on the other side is %f K.\n", t1);
    } else if (*unknown_variable == t2) {
        t2 = fabs(((h * x) / (k * a)) + t1);
        printf("Temperature on the other side is %f K.\n", t2);
    } else if (*unknown_variable == x) {
        x = (k * a * (t2 - t1)) / h;
        printf("Thickness of conductor (m) is %f\n", h);
    } else {
        printf("You already know every variable :) or something went wrong :(\n");
    }

    //  Prints final output
    printf("H = %21.5f\n", h);
    printf("k = %21.5f\n", k);
    printf("A = %21.5f\n", a);
    printf("T2 = %20.5f\n", t2);
    printf("T1 = %20.5f\n", t1);
    printf("x = %21.5f\n", x);

    return 0;
}

/*
 * Gets data from user and saves the variable that user typed ? to unknown_variable via it's pointer.
 */
void
get_data(
        double* variable,
        double** unknown_variable
        )
{
    int status;
    status = scanf("%lf", variable);
    if (status == 0) {          //  if scanf() couldn't find anything it sets unknown_variable pointer as that variables address
        while (getchar() != '\n');
        *unknown_variable = variable;
        *variable = 0;
    }
}

