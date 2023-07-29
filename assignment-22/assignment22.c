#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PLAYERS 5 // Total players
#define BUF 64 // Buffer size

typedef struct
{
    int points;
    int games;
    float average;
} stats;

stats player[PLAYERS];

void valid_int(int *i);
void print_av(void);

int main(void)
{
    // Prompts for each players total points/games
    for(int i = 0; i < PLAYERS; i++)
    {
        printf("Enter player %d's points total: ", i + 1);
        valid_int(&(player[i].points));

        printf("Enter player %d's games total: ", i + 1);
        valid_int(&(player[i].games));
        
        // Calculates the players scoring average
        player[i].average = (float)player[i].points / player[i].games;
    }
    print_av();
}

// Safely reads and validates user integers
void valid_int(int *i)
{
    char buf[BUF];
    
    do
    {        
        if (!fgets(buf, sizeof(buf), stdin))
        {
            break;
        }
        
        char *endptr;
        errno = 0;
        *i = strtol(buf, &endptr, 10);

        // Check for invalid input: number too large, conversion incomplete, or invalid characters
        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n'))
        {
            printf("Invalid input. Please enter a number: ");
        }
        else
        {
            break;
        }
    } while (1);
}

// Prints each players average
void print_av(void)
{
    printf("\n");
    for(int i = 0; i < PLAYERS; i++)
    {
        printf("Player %d's average was %.2f ppg.\n", i + 1, player[i].average);
    }
}
