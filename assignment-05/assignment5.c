// Convert seconds to the total time in hours, minutes, and seconds

#include <stdio.h>

int main(void)
{
    int seconds;

    printf("Number of seconds: ");
    scanf("%i", &seconds);

    // Total number of seconds / by number of seconds in an hour
    int hours = seconds / 3600;

    // Take the remainder of the previous step and / by 60 to get the number of minutes
    int minutes = (seconds % 3600) / 60;

    // Take the remainder of the first step and mod by 60 to get the number of seconds 
    int remaining_seconds = (seconds % 3600) % 60;

    printf("%i is equal to %i hour, %i minutes, and %i seconds.\n", seconds, hours, minutes, remaining_seconds);

    return 0;
}
