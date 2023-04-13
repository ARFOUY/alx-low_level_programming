#include <stdlib.h>
#include <stdio.h>

/**
* alloc_grid - function that returns a pointer to a 2 dimensional array.
* @width: width of the grid.
* @height: height of the grid.
*
* Return: a pointer to a 2 dimensional array of integers.
*/
int **alloc_grid(int width, int height)
{
    int **grid;
    int i, j;

    if (width <= 0 || height <= 0)
    {
        return (NULL);
    }

    grid = malloc(sizeof(int *) * height);
    if (grid == NULL)
    {
        return (NULL);
    }

    for (i = 0; i < height; i++)
    {
        grid[i] = malloc(sizeof(int) * width);
        if (grid[i] == NULL)
        {
            for (j = 0; j < i; j++)
            {
                free(grid[j]);
            }
            free(grid);
            return (NULL);
        }

        for (j = 0; j < width; j++)
        {
            grid[i][j] = 0;
        }
    }

    return (grid);
}

/**
 * print_grid - prints a grid of integers
 * @grid: the address of the two dimensional grid
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void print_grid(int **grid, int width, int height)
{
    int w;
    int h;

    h = 0;
    while (h < height)
    {
        w = 0;
        while (w < width)
        {
            printf("%d ", grid[h][w]);
            w++;
        }
        printf("\n");
        h++;
    }
}

/**
 * main - check the code for ALX School students.
 * Return: Always 0.
 */
int main(void)
{
    int **grid;

    grid = alloc_grid(6, 4);
    if (grid == NULL)
    {
        printf("Failed to allocate memory.\n");
        return (1);
    }

    print_grid(grid, 6, 4);

    return (0);
}

