/*
 * Programmer: Emirhan TALA                 Date completed: Oct 8, 2022
 *
 * Finds the area under the curve y = f(x) between the lines x = a and x = b
 * with using trapezoidal rule approximation.
 */

#include <stdio.h>
#include <math.h>

double approxımate_area(double f(double x), double a, double b, double n);
double sigma_notation_for_finding_are(double initial, double last, double f(double x), double h, double a);
double h(double x);
double g(double x);


int main() {
    double area_of_g, area_of_h;
    int n;

    printf("Type how much sub-intervals do you want (example 256)> ");                              /* gets the sub-interval number */
    scanf("%d", &n);

    area_of_g = approxımate_area(g, 0, 3.14159, n);
    area_of_h = approxımate_area(h, -2, 2, n);

    printf("Area of function g is %f\nArea of function h is %f\n\n",area_of_g, area_of_h);

    printf("Difference of h function approximation and real value is %f.\nArea of function h should be 6.283185. You can compare this with trapezoidal rule approximation", fabs(area_of_h - 6.283185));

    return 0;
}

/*
 * Approximates are under the curve y = f(x) between the lines x = a and x = b with using formula
 *           h                                 n - 1
 *  Area = -----  *   (f(a) + f(b) + 2 * sigma_notation f(x1))
 *           2                                 i = 1
 *
 *  Pre: f(x), a, b
 *  Post: Area
 */
double
approxımate_area(
        double f(double x),
        double a,
        double b,
        double n
        )
{
    double h;



    h = (b - a) / n;                /* finds the width of a sub-interval */

    return (h / 2) * (f(a) + f(b) + 2 * sigma_notation_for_finding_are(1, n-1, f, h, a));
}


/*
 * Sigma notation for finding area
 *
 * Pre: initial, last, f(x)
 * Past: sum
 */
double
sigma_notation_for_finding_are(
        double initial,
        double last,
        double f(double x),
        double h,
        double a
        )
{
    double sum;

    sum = 0;                        /* assign value 0 to sigma notation's result*/
    for (initial = 1; initial <= last; initial++){
        sum += f(a);
        a += h;                    /* increases a with h(the width of a sub-interval) to calculate next sub-interval */
    }
    return sum;
}


/*
 * Functions that we will calculate approximate areas
 */
double
g(double x)
{
    return pow(x, 2) * sin(x);
}

double
h(double x)
{
    return sqrt(4 - pow(x, 2));
}