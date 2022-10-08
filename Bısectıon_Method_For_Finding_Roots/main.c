/*
 *  Programmer: Emirhan TALA             Date completed: Oct 6, 2022
 *
 *  Finds roots of the equations
 *          g(x) = 0 and f(x) = 0
 *  on a specified interval [x_left, x_right] using the bisection method.
 */

#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1
#define NO_ROOT -99999.0


double bisect(double x_left, double f_left, double epsilon, double f(double farg));
double g(double x);
double h(double x);



int main() {
    double x_left, x_right,             /* left, right endpoints of interval */
           epsilon,                     /* error tolerance                   */
           root;

    /* Get endpoints and error tolerance from user */
    printf("Enter interval endpoints (x_left x_right)> ");
    scanf("%lf%lf", &x_left, &x_right);
    printf("\nEnter tolerance> ");
    scanf("%lf", &epsilon);

    /* Use bisect function to look for roots of g and h */
    printf("\n\nFunction g");
    root = bisect(x_left, x_right, epsilon, g);
    if (root != NO_ROOT)
        printf("\n    g(%.7f) = %e\n", root, g(root));

    printf("\n\nFunction h");
    root = bisect(x_left, x_right, epsilon, h);
    if (root != NO_ROOT)
        printf("\n    h(%.7f) = %e\n", root, h(root));
    return 0;
}

/*
 *  Implements the bisection method for finding a root of a function f.
 *
 *  Pre: x_left, x_right, epsilon, function defined
 *  Post: Returns NO_ROOT if no sign difference between f(x_left) and f(x_right)
 *        Returns root(x_mid) when f(x_mid) = 0
 */
double
bisect(double x_left,
       double x_right,
       double epsilon,
       double f(double farg))
{
    double x_mid,                       /* midpoint of intervalj    */
           f_left,                      /* f(x_left)                */
           f_mid,                       /* f(x_mid)                 */
           f_right;                     /* f(x_right)               */

    int root_found;                     /* flag to indicate whether root is found */

    f_left = f(x_left);
    f_right = f(x_right);

    /* If no change of sign occurs on the interval there is not a unique root.
       Exit function and return NO_ROOT */
    if (f_left * f_right > 0) {         /* same sign */
        printf("\nMay be no root in [%.7f,%.7f]", x_left, x_right);
        return NO_ROOT;
    }


    /* Searches as long as interval size is large enough and no root has been found */
    root_found = FALSE;                 /* no root found yet */
    while(fabs(x_right - x_left) > epsilon && !root_found){
        x_mid = (x_left + x_right) / 2.0;
        f_mid = f(x_mid);

        if (f_mid == 0) {                       /* Here's the root */
            root_found = TRUE;
        } else if (f_mid * f_left < 0) {        /* Root in [x_left, x_mid] */
            x_right = x_mid;
        } else {                                /* Root in [x_mid, x_right] */
            x_left = x_mid;
        }

        if (root_found){
            printf("\nRoot found at x= %.7f, midpoint of [%.7f,%.7f]", x_mid, x_left, x_right);
        } else {
            printf("\nNew interval is [%.7f,%.7f]", x_left, x_right);
        }
    }

    /* If there is no root, it is the midpoint of [x_left, x_right] */
    return ((x_left + x_right) / 2.0);
}

/*   3    2
 * 5x - 2x + 3
 */
double
g(double x)
{
    return (5*pow(x, 3.0) - 2 * pow(x, 2.0) + 3);
}

/*  4    2
 * x - 3x - 8
 */
double
h(double x)
{
    return (pow(x, 4.0) - 3 * pow(x, 2.0) - 8);
}

/*
 * ==============
 * EXAMPLE OUTPUT
 * ==============
 *
 * Enter interval endpoints (x_left x_right)> -1.0 1.0
 *
 * Enter tolerance> 0.001
 *
 *
 * Function g
 * New interval is [-1.0000000,0.0000000]
 * New interval is [-1.0000000,-0.5000000]
 * New interval is [-0.7500000,-0.5000000]
 * New interval is [-0.7500000,-0.6250000]
 * New interval is [-0.7500000,-0.6875000]
 * New interval is [-0.7500000,-0.7187500]
 * New interval is [-0.7343750,-0.7187500]
 * New interval is [-0.7343750,-0.7265625]
 * New interval is [-0.7304688,-0.7265625]
 * New interval is [-0.7304688,-0.7285156]
 * New interval is [-0.7294922,-0.7285156]
 *     g(-0.7290039) = -2.697494e-05
 *
 *
 * Function h
 * May be no root in [-1.0000000,1.0000000]
 * Process finished with exit code 0
 */