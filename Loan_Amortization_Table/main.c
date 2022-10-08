/*
 * Programmer: Emirhan TALA                 Date completed: Oct 8, 2022
 *
 * Gets the amount borrowed(the principal), the annual interest rate, and the number of payments
 * to calculate the monthly payment.
 */

#include <stdio.h>
#include <math.h>

double payment_calculator(double principal, double monthly_interest_rate, int num_of_payments);
double how_the_debt_is_paid_of_table(double interest, double principle, double monthly_interest_rate);

int main() {
    double principal, annual_interest_rate, monthly_interest_rate, payment;
    int num_of_payments;

    printf("Enter the amount you borrowed> ");
    scanf("%lf", &principal);
    printf("Enter the annual interest rate> ");
    scanf("%lf", &annual_interest_rate);
    printf("Enter the number of payments> ");
    scanf("%d", &num_of_payments);

    monthly_interest_rate= (annual_interest_rate / 100) / 12; /* calculates monthly interest rate with annual interest rate */

    payment = payment_calculator(principal, monthly_interest_rate, num_of_payments);  /* gets monthly payment of debt */

    printf("\n\n==============================================================================\n");
    printf("Principal            %5.2f$                      Payment             %5.2f$\n", principal, payment);
    printf("Annual interest         %5.1f                      Term           %5d months\n", annual_interest_rate, num_of_payments);
    printf("==============================================================================\n");

    printf("Payment            Interest            Principal             Principal Balance\n");
    payment = how_the_debt_is_paid_of_table(principal, monthly_interest_rate, payment); /* prints the monthly table and returns last payment */
    printf("Final payment    $%.2f", payment);
    return 0;
}

/*
 * Calculates monthly payment with this formula:
 *
 *              (monthly_interest_rate * principal)
 * -------------------------------------------------------------- = Monthly payment
 *                                          -num_of_payments
 *               1 - (1 + monthly_interest_rate)
 *
 * Pre: principal, monthly_interest_rate, num_of_payments must be defined
 * Post: Monthly payment
 */
double
payment_calculator(
        double principal,
        double monthly_interest_rate,
        int num_of_payments)
{
    double payment = (monthly_interest_rate * principal) / (1 - (1 / pow((1 + (monthly_interest_rate)), num_of_payments))); /* monthly payment formula */
    payment = round(payment * 100) / 100;
    return payment;
}

/*
 * Draws the table that shows how the debt is paid of
 *
 * Pre: principal, monthly_interest_rate, payment
 * Post: payment
 */
double
how_the_debt_is_paid_of_table(
        double principal,
        double monthly_interest_rate,
        double payment)
{
    double interest, monthly_principal;
    for (int payment_count = 0; payment_count < 6; payment_count++){
        interest = principal * monthly_interest_rate; /* calculates the interest money */
        monthly_principal = round((payment - interest) * 100) / 100; /* rounds monthly principal to .XX  */
        if (principal < monthly_principal){ /* last payment might be lower. If left principal is lower than monthly principal last payment */
            payment = payment + principal - monthly_principal; /* decrease last payment with */
            monthly_principal = principal; /* last monthly principal is equal to left principal */
            principal = 0;  /* sets principal to 0 because all the debt is closed */

        } else {
            principal -= monthly_principal; /* decreases principal after monthly principal payed */
        }
        printf("%d     %21.2f%21.2f         %21.2f\n", payment_count + 1, interest, monthly_principal, principal);
    }
    return payment;
}

/*
* ==============
* Example Output
* ==============
*
* ==============================================================================
* Principal            1000.00$                      Payment             171.07$
* Annual interest           9.0                      Term               6 months
* ==============================================================================
* Payment            Interest            Principal             Principal Balance
* 1                      7.50               163.57                        836.43
* 2                      6.27               164.80                        671.63
* 3                      5.04               166.03                        505.60
* 4                      3.79               167.28                        338.32
* 5                      2.54               168.53                        169.79
* 6                      1.27               169.79                          0.00
* Final payment    $171.06
*/