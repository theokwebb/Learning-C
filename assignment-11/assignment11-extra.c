#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1

int main(void)
{
    char choice = 'Y';
    char buf[64];
    int capacity = CAPACITY;

    long total_scores = 0;
    int score_count = 0;
    
    // Allocate memory for a score
    int *scores = malloc(CAPACITY * sizeof(int));
    if (scores == NULL)
    {
        return 1;
    }
    
    for (int i = 0; choice == 'Y'; i++)
    {
        if (i == CAPACITY) // If users opts to continue, resize to add another score
        {
            capacity++;

            int *tmp = realloc(scores, capacity * sizeof(int));
            if (tmp == NULL)
            {
                free(scores);
                return 1;
            }
            scores = tmp;
        }
        
        // Store input
        printf("Enter Test Score: ");
        if (!fgets(buf, sizeof(buf), stdin))
        {
            return 1;
        }

        char *endptr;
        errno = 0;
        scores[i] = strtol(buf, &endptr, 10);

        // Checks whether number is too large, the conversion was incomplete
        // or there are invalid characters
        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n'))
        {
            printf("Invalid input. Please enter a valid number.\n");
        }
        else
        {
            total_scores += scores[i];
            score_count++;
        }

        // Checks whether user opts to continue
        printf("Continue (Y/N)? ");
        if (!fgets(buf, sizeof(buf), stdin))
        {
            return 1;
        }
        choice = buf[0];
    }
    
    // Calculate average of scores
    float n = (float) total_scores / score_count;
    printf("%.2f is the average score.\n", n);

    free(scores);
    return 0;
}
