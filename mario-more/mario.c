#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height < 1 || height > 8);

    for (int no_hash = 1; no_hash < height + 1; no_hash++)
    {
        int total_singleline_dots = height - no_hash;
        for (int dot_single_line = 0; dot_single_line < total_singleline_dots; dot_single_line ++)
        {
            printf(" ");
        }
        for (int single_line = 0; single_line < no_hash; single_line++)
        {
            printf("#");
        }
        printf("  ");
        for (int single_line = 0; single_line < no_hash; single_line++)
        {
            printf("#");
        }

        printf("\n");
    }
}