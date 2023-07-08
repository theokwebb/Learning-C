#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char buf[64];
    int coin_flips = 0;

    // Ensure user enters a valid number of coin flips
    do
    {
        printf("Number of coin flips: ");

        if (!fgets(buf, sizeof(buf), stdin))
        {
            return 1;
        }

        char *endptr;
        errno = 0;
        coin_flips = strtol(buf, &endptr, 10);

        // Checks whether number is too large, the conversion was incomplete
        // or there are invalid characters
        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n'))
        {
            printf("Invalid input. Please enter a valid number.\n");
        }
        else
        {
            break;
        }
    } while (1);
    
    // Counters for heads and tails
    int heads = 0;
    int tails = 0;
    srand(time(0)); // Set seed value as time value of clock

    for (int i = 0; i < coin_flips; i++)
    {        
        int r = rand() % 2; // A random num from 0-1

        if (r == 0)
        {
            heads++; // If 0, add to heads counter
        }
        else
        {
            tails++; // If 1, add to tails counter
        }
    }

    // Print results
    printf("%d heads.\n%d tails.\n", heads, tails);
    return 0;
}
