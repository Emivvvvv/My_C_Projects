/*
 *  Programmer: Emirhan TALA             Date completed: Oct 18, 2022           Professor: Mustafa Bülent MUTLUOĞLU
 *
 *  This program is a running race simulator. Each athlete has acceleration and top speed attributes.
 *  User will enter attributes for two athletes and the race length (in meters) and program will determine the winner of the race.
 */

#include <stdio.h>
#include <math.h>

#define ATHLETE1 1
#define ATHLETE2 2
#define TIE 0

double calculateAccelerationTime(double athlete_acc, double athlete_top_spd);
double calculateDistanceAccelerating(double athlete_acc, double acc_time);
double calculateTimeTopSpeed(double athlete_top_spd, double remaining_dst_after_top_spd);
int findWinner(int race_length, double athlete1_acc, double athlete1_top_spd, double athlete2_acc, double athlete2_top_spd);

int main() {
    int race_length;                            //  length of the racetrack
    int winner;                                 //  winner will be set to this variable

    double athlete1_acc, athlete1_top_spd;      //  attributes of athlete 1
    double athlete2_acc, athlete2_top_spd;      //  attributes of athlete 2

    //  Gets the length of the racetrack from the user
    printf("Type the length of the race track in meters\n(integer) > ");
    scanf("%d", &race_length);

    //  Gets the acceleration and top speed values from the user
    printf("\nType the acceleration rate and the top speed of athlete 1 with a space between\n(float) > ");
    scanf("%lf %lf", &athlete1_acc, &athlete1_top_spd);
    printf("\nType the acceleration rate and the top speed of athlete 1 with a space between\n(float) > ");
    scanf("%lf %lf", &athlete2_acc, &athlete2_top_spd);

    //  Finds and returns winner or if is tie returns TIE(0).
    winner = findWinner(race_length, athlete1_acc, athlete1_top_spd, athlete2_acc, athlete2_top_spd);

    //  Prints who won or prints tie if they equally finished.
    if (winner == ATHLETE1)
        printf("\nAthlete 1 won!");
    else if (winner == ATHLETE2)
        printf("\nAthlete 2 won!");
    else if (winner == TIE)
        printf("\nIt is a tie!");

    return 0;
}

/*
 * This function returns the time (in seconds) needed for an athlete to reach top speed
 *
 * Pre: all variables must be defined
 * Post: a float value which is the time needed to reach top speed in seconds
 */
double
calculateAccelerationTime(double athlete_acc, double athlete_top_spd)
{
    return athlete_top_spd / athlete_acc;
}

/*
 * This function calculates and returns the distance
 * (in meters) covered by an athlete until reaching top speed.
 *
 * Pre: all variables must be defined
 * Post: returns a float value which is the distance
 * (in meters) covered by an athlete until reaching top speed.
 */
double
calculateDistanceAccelerating(double athlete_acc, double acc_time)
{
    return ( athlete_acc / 2 ) * pow(acc_time, 2);
}

/*
 * This function calculates and returns the time (in seconds)
 * needed for an athlete to finish the race after reaching top speed.
 *
 * Pre: all variables must be defined
 * Post: returns a float value which is the time needed to finish the race after reaching top speed.
 */
double
calculateTimeTopSpeed(double athlete_top_spd, double remaining_dst_after_top_spd)
{
    return remaining_dst_after_top_spd / athlete_top_spd;
}

/*
 * This function finds and returns the winner of the race.
 *
 * Pre: all variables must be defined
 *      all athletes must be reach their top speed before finishing the race
 *
 * Post: returns winner(1 or 2) or returns tie(0).
 */
int
findWinner(int race_length, double athlete1_acc, double athlete1_top_spd, double athlete2_acc, double athlete2_top_spd)
{
    double athlete1_total_time, athlete2_total_time;
    double athlete1_acc_time, athlete2_acc_time;

    //  Gets acceleration times of all athletes to use after
    athlete1_acc_time = calculateAccelerationTime(athlete1_acc, athlete1_top_spd);
    athlete2_acc_time = calculateAccelerationTime(athlete2_acc, athlete2_top_spd);

    //  Calculates the total race time with adding acceleration time and the time spend with full speed.
    athlete1_total_time = athlete1_acc_time + calculateTimeTopSpeed(athlete1_top_spd, race_length - calculateDistanceAccelerating(athlete1_acc, athlete1_acc_time));
    athlete2_total_time = athlete2_acc_time + calculateTimeTopSpeed(athlete2_top_spd, race_length - calculateDistanceAccelerating(athlete2_acc, athlete2_acc_time));

    //  Returns the winner or tie if they finished with an equal time.
    if (athlete1_total_time < athlete2_total_time)
        return ATHLETE1;
    else if (athlete2_total_time < athlete1_total_time)
        return ATHLETE2;
    else if (athlete1_total_time == athlete2_total_time)
        return TIE;
}