#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size, end_size, current_pop, no_years = 0;
    // TODO: Prompt for start size
    do
    {
        start_size = get_int("Start size: ");
    } while(start_size < 9);

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    } while(end_size < start_size);

    current_pop = start_size;

    // TODO: Calculate number of years until we reach threshold
    while (current_pop < end_size)
    {
        current_pop += current_pop/3 - current_pop/4;
        no_years ++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", no_years);
}
