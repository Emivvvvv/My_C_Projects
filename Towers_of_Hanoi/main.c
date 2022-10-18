/*
 *  Programmer: Emirhan TALA             Date completed: Oct 17, 2022
 *
 * A recursive solution for towers of hanoi problem.
 */

#include <stdio.h>

void towers_of_hanoi(int n, int start, int end);

int main() {
    towers_of_hanoi(4, 1, 3);
}

void
towers_of_hanoi(int n, int start, int end)
{
    int other;

    if (n == 1)
        printf("%d => %d\n", start, end);
    else
    {
        other = 6 - (start + end);
        towers_of_hanoi(n-1, start, other);
        printf("%d => %d\n", start, end);
        towers_of_hanoi(n-1, other, end);
    }
}
