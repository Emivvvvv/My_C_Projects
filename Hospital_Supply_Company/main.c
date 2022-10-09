/*
 *  Programmer: Emirhan TALA             Date completed: Oct 9, 2022
 *
 *  A hospital supply company program to assist
 *  with the calculation of intravenous rates.
 */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

// Prototypes
void get_problem(int*);
void get_rate_drop_factor(void);
void get_l_hour_rate_in_ml(void);
void get_kg_rate_conc(void);
void get_units_conc(void);

void fig_drops_min(double*, int*, double*);
void fig_ml_hr(int*, int*, double*);
void by_weight(double*, int*, double*, double*);
void by_units(double*, double*, double*);

int main() {
    int problem, is_quit;

    is_quit = FALSE;

    while (!is_quit) {
        //  Get problem number from the user
        get_problem(&problem);

        //  Switch case handles selected problem
        switch (problem) {
            case 1:
                get_rate_drop_factor();
                break;
            case 2:
                get_l_hour_rate_in_ml();
                break;
            case 3:
                get_kg_rate_conc();
                break;
            case 4:
                get_units_conc();
                break;
            case 5:
                printf("Quitting...");
                is_quit = TRUE;
                break;
            default:
                printf("Something went wrong lol.");
        }
    }
    return 0;
}

/*
 * Takes problem variable's address and gets problem number input
 * from user and saves it problem variable via pointers.
 * Pre: problem integer variable is defined and problem_p is a integer pointer to problem variable.
 */
void get_problem(int* problem_p){
    int status;
    //  Prints the possible options for user
    printf("\n\n\n\nINTRAVENOUS RATE SASSISTANT\n\n");
    printf("Enter the number of the problem you wish to solve.\n");
    printf("=========================================================================\n");
    printf("    GIVEN A MEDICAL ORDER IN                            CALCULATE RATE IN\n");
    printf("(1) ml/hr & tubing drop factor                          drops / min\n");
    printf("(2) m L for n hr                                        ml / hr\n");
    printf("(3) mg/kg/hr & concentration in mg/ml                   ml / hr\n");
    printf("(4) units/hr & concentration in units/ml                ml / hr\n");
    printf("(5) QUIT\n\n");

    //  Gets problem input from user
    do {
        printf("Problem> ");
        status = scanf("%d", problem_p);
        if (*problem_p <= 0 && *problem_p > 5) {
            printf("The number typed is not in valid interval. Please chose one of the problem numbers and try again.\n");
        } else if (status != 1) {
            printf("Please try again with typing a problem number!\n");
        }
    } while (*problem_p <= 0 && *problem_p > 5 || status != 1);
}

/*
 * Calculates the drop rate per minute by using ml/hr rate and tubing's drop factor.
 */
void get_rate_drop_factor(void){
    int drops_ml;
    double ml_hr_rate, result_rate;

    // Gets necessary inputs from user
    printf("Enter rate in ml/hr => ");
    scanf("%lf", &ml_hr_rate);

    printf("Enter tubing's drop factor(drops/ml) => ");
    scanf("%d", &drops_ml);

    // Calculates the result rate and prints the final output
    fig_drops_min(&ml_hr_rate, &drops_ml, &result_rate);
    printf("The drop rate per minute is %.2f.", result_rate);
}

/*
 * Calculates the rate in millimeters per hour by getting liter and hours from user.
 */
void get_l_hour_rate_in_ml(void){
    int liter, hours;
    double result_rate;

    //  Gets necessary inputs from user
    printf("Enter total liter => ");
    scanf("%d", &liter);

    printf("Enter number of hours => ");
    scanf("%d", &hours);

    //  Calculates the result rate and prints the final output
    fig_ml_hr(&liter, &hours, &result_rate);
    printf("The rate in milliliters per hour is %.2fml.", result_rate);

}

/*
 * Calculates the rate in milliliters per hour by getting mg/kg/hr rate, patient's weight and concentration in mg/ml.
 */
void get_kg_rate_conc(void){
    double mg_kg_hr_rate, concentration_in_mg_ml, result_rate;
    int patient_weight_in_kg;

    //  Gets necessary inputs from user
    printf("Enter rate in mg/kg/hr => ");
    scanf("%lf", &mg_kg_hr_rate);

    printf("Enter patient weight in kg => ");
    scanf("%d", &patient_weight_in_kg);

    printf("Enter concentration in mg/ml => ");
    scanf("%lf", &concentration_in_mg_ml);

    //  Calculates the result rate and prints the final output
    by_weight(&mg_kg_hr_rate, &patient_weight_in_kg, &concentration_in_mg_ml, &result_rate);
    printf("The rate in milliliters per hour is %.2fml.", result_rate);

}

/*
 * Calculates the rate in milliliters per hour by getting units/hr rate and concentration in units/ml from user.
 */
void get_units_conc(void){
    double units_hr, concentration_in_units_ml, result_rate;

    //  Gets necessary inputs from user
    printf("Enter rate in units/hr => ");
    scanf("%lf", &units_hr);

    printf("Enter concentration in units/ml => ");
    scanf("%lf", &concentration_in_units_ml);

    //  Calculates the result rate and prints the final output
    by_units(&units_hr, &concentration_in_units_ml, &result_rate);
    printf("The rate in milliliters per hour is %.2fml.", result_rate);
}


/*
 * Calculates the drop rate and returns it to result_rate via result_rate pointer
 * Pre: ml_hr_rate, drops_ml, result_rate are defined and the arguments are their addresses.
 */
void fig_drops_min(double* ml_hr_rate, int* drops_ml, double* result_rate){
    *result_rate = (*ml_hr_rate / 60) * *drops_ml;
}

/*
 * Calculates the rate in milliliters per m hour and returns it to result_rate via result_rate pointer
 * Pre: liter, hours, result_rate are defined and the arguments are their addresses.
 */
void fig_ml_hr(int* liter, int* hours, double* result_rate){
    *result_rate = (*liter  * 1000 ) / *hours;
}

/*
 * Calculates the rate in milliliters by using mg/kg/hr rate, patient's weight and concentration. Returns it to result_rate via result_rate pointer
 * Pre: mg_kg_hr_rate, patient_weight_in_kg, concentration_in_mg_ml, result_rate are defined and the arguments are their addresses.
 */
void by_weight(double* mg_kg_hr_rate, int* patient_weight_in_kg, double* concentration_in_mg_ml, double* result_rate){
    *result_rate = *patient_weight_in_kg * *mg_kg_hr_rate * *concentration_in_mg_ml;
}

/*
 * Calculates the rate in milliliters by using units/hr rate and concentration in units/ml. Returns it to result_rate via result_rate pointer
 * Pre: units_hr, concentration_in_units_ml, result_rate are defined and the arguments are their addresses.
 */
void by_units(double* units_hr, double* concentration_in_units_ml, double* result_rate){
    *result_rate = *units_hr / *concentration_in_units_ml;
}
