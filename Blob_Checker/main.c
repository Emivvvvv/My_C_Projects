/*
 *  Programmer: Emirhan TALA             Date completed: Oct 18, 2022
 *
 * A recursive blob checker of a grid.
 */

#include <stdio.h>

int blob_check(int grid[][5], int x, int y);

int main() {
    /*
     * Creating the demo grid[x][y]
     *
     * 5x5
     *
     *
     *  1 1 0 0 0   0
     *  0 1 1 0 0   1
     *  0 0 1 0 1   2 y
     *  1 0 0 0 1   3
     *  0 1 0 1 1   4
     *
     *  0 1 2 3 4
     *      x
     *
     */
    int grid[5][5]={{1, 0, 0, 1, 0},{1, 1, 0, 0, 1},{0, 1, 1, 0, 0},{0, 0, 0, 0, 1},{0, 0, 1, 1, 1}};

    int x, y;
    int result;

    printf("1 1 0 0 0   0\n0 1 1 0 0   1\n0 0 1 0 1   2 y\n1 0 0 0 1   3\n0 1 0 1 1   4\n\n0 1 2 3 4\n    x\n\n");
    printf("Type x and y coordinates with a space between to find blob count.\n>");
    scanf("%d%d", &x, &y);

    result = blob_check(grid, x, y);

    printf("blob count for x: %d, y: %d is %d.", x, y, result);

    return 0;
}

int
blob_check(int grid[][5], int x, int y)
{
    int result = 0;

    int iterator, iterator_inside;

    if (x < 0 || x > 4 || y < 0 || y > 4 || grid[x][y] == 0)
        return 0;
    else
    {
        result++;
        grid[x][y] = 0;
        for (iterator = -1; iterator < 2; iterator++){
            for (iterator_inside = -1; iterator_inside < 2; iterator_inside++){
                result += blob_check(grid, x + iterator, y + iterator_inside);
            }
        }
        return result;
    }
}