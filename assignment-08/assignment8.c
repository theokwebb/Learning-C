#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long number;
    char buf[1024];

    do
    {
        printf("Enter a number between 1-500: ");

        if (!fgets(buf, sizeof(buf), stdin))
        {
            // Reading input failed:
            return 1;
        }

        char *endptr;
        errno = 0;
        number = strtol(buf, &endptr, 10);

        // Checks whether number is too large, the conversion was incomplete, or there are invalid characters
        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n'))
        {
            printf("Invalid input. Please enter a valid number.\n");
        }
        else
        {
            // Checks if the number is within the range and provides appropriate feedback based on the result
            if (number > 1 && number <= 500)
            {
                int lower = ((number - 1) / 100) * 100 + 1;
                int upper = lower + 99;
                printf("Your number is between %d-%d.\n", lower, upper);
            }
            else
            {
                printf("Your number was not in the range 1-500.\n");
            }
            break;
        }
    } while (1);
}
