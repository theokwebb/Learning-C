#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define GAMES 4
#define PLAYERS 5

int main(void)
{
    int player[GAMES][PLAYERS];
    int player_total_score[PLAYERS] = {0};
    
    char buf[256];

    // Collect scores for each player and game
    for(int i = 0; i < GAMES; i++)
    {
        printf("Game %d\n", (i + 1));
        for(int j = 0; j < PLAYERS; j++)
        {
            do
            {
                printf("Score total for player %d: ", (j + 1));

                if (!fgets(buf, sizeof(buf), stdin))
                {
                    return 1;
                }

                char *endptr;
                errno = 0;
                player[i][j] = strtol(buf, &endptr, 10);

                // Check for invalid input: number too large, conversion incomplete, or invalid characters
                if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n'))
                {
                    printf("Invalid input. Please enter a valid number.\n");
                }
                else
                {
                    player_total_score[j] += player[i][j]; // Update player's total score
                    break;
                }
            } while (1);
        }
    }

    float player_av[PLAYERS] = {0}; // Array to store each player's average score
    float highest_av = 0; // Highest average found
    int player_id = 0; // Player with the highest average

    // Calculate each player's average score
    for(int i = 0; i < PLAYERS; i++)
    {
        player_av[i] = player_total_score[i] / GAMES;

        // Check if the current player's average is higher than the highest average found so far
        if (player_av[i] > highest_av)
        {
            highest_av = player_av[i];
            player_id = (i + 1); // // Update the player with the highest average
        }  
    }

    // Print the player with the highest average and their average points per game
    printf("Player %d had the highest average at %.2f points per game.\n", player_id, highest_av);

    return 0;
}
