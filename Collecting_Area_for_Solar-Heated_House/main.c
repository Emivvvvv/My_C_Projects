/*
 *  Programmer: Emirhan TALA             Date completed: Oct 9, 2022
 *
 *  Estimate necessary solar collecting area size for a particular type of
 *  construction in a given location.
 */

#include <stdio.h>

int days_in_month(int);
int nth_item(FILE *, int);

int main(void) {
    int heat_deg_days,                      //  average for coldest month
        solar_insol,                        //  average daily solar radiation per ft^2 for coldest month
        coldest_mon,                        //  coldest month number in range 1..12
        heating_req,                        //  BTU/degree day ft^2 requirement for given type of construction
        efficiency,                         //  % of solar insolation converted to usable heat
        collect_area,                       //  ft^2 needed to provide heat for coldest month
        ct,                                 //  position in file
        status,                             //  file status variable
        next_hdd;                           //  one heating degree days value

    double floor_space,                     //  ft^2
           heat_loss,                       //  BTUs lost in coldest month
           energy_resrc;                    //  BTUs heat obtained from 1 ft^2 collecting area in coldest month

    FILE *hdd_file;                         //  average heating degree days for each of 12 months
    FILE *solar_file;                       //  average solar insolation for each of 12 months

    //  Get average heating degree days for coldest month from file
    hdd_file = fopen("/Users/emivvvvv/CLionProjects/Collecting_Area_for_Solar-Heated_House/hdd.txt", "r");
    fscanf(hdd_file, "%d", &heat_deg_days);
    coldest_mon = 1;
    ct = 2;
    status = fscanf(hdd_file, "%d", &next_hdd);
    while(status == 1) {
        if (next_hdd > heat_deg_days){
            heat_deg_days = next_hdd;
            coldest_mon = ct;
        }
        ++ct;
        status = fscanf(hdd_file, "%d", &next_hdd);
    }
    fclose(hdd_file);

    //  Get corresponding average daily solar insolation from other file
    solar_file = fopen("/Users/emivvvvv/CLionProjects/Collecting_Area_for_Solar-Heated_House/solar.txt", "r");
    solar_insol = nth_item(solar_file, coldest_mon);
    fclose(solar_file);

    //Get from user specifics of this house
    printf("What is the approximate heating requirement (BTU / degree day ft^2)\n");
    printf("of this type of construction?\n=>");
    scanf("%d", &heating_req);
    printf("What percent of solar insolation will be converted to usable heat?\n=>");
    scanf("%d", &efficiency);
    printf("What is the floor space (ft^2)?\n=>");
    scanf("%lf", &floor_space);

    // Project collecting area needed
    heat_loss = heating_req * floor_space * heat_deg_days;
    energy_resrc = efficiency * 0.01 * solar_insol * days_in_month(coldest_mon);
    collect_area = (int) (heat_loss / energy_resrc + 0.5);

    //  Display results
    printf("To replace heat loss of %.0f BTU in the", heat_loss);
    printf("coldest month (month %d)\nwith available ", coldest_mon);
    printf("solar insolation of %d BTU / ft^2 / day,", solar_insol);
    printf(" and an\nefficiency of %d percent", efficiency);
    printf(" use a solar collecting are of %d", collect_area);
    printf(" ft^2.\n");

    return 0;
}

/*
 * Given a month number ( 1 = January, 2 = February, ..., 12 = December ),
 * return the number of days in the month (nonleap year).
 *
 * Pre: 1 <= monthNumber <= 12
 */
int days_in_month( int month_number )
{
    int ans;

    switch (month_number) {
        case 2:
            ans = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ans = 30;
            break;
        default:
            ans = 31;
    }

    return ans;
}

/*
 * Finds and returns the nth integer in a file.
 * Pre: data_file accesses a file of at least n integers (n >= 1).
 */
int nth_item(FILE *data_file, int n)
{
    int i, item;

    for (i = 1; i <= n; ++i){
        fscanf(data_file, "%d", &item);
    }

    return item;
}
