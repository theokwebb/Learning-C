#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of scores
#define MAX_SCORES 10

int main(void)
{
    long scores[MAX_SCORES];
    char buf[1024];

    long total_scores = 0;
    int score_count = 0;

    for (int i = 0; i < MAX_SCORES; i++)
    {
        do
        {
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
                break;
            }
        } while (1);

    char choice[16] = {0}; 
    printf("Continue (Y/N)? ");

    if (fgets(choice, sizeof(choice), stdin))
    {
        choice[strcspn(choice, "\n")] = '\0';    

        if (strcmp(choice, "N") == 0)
        {
            break;
        }
        else if(strcmp(choice, "Y") == 0)
        {
            continue;
        }
        else if (strlen(choice) != 1 || choice[1] != '\0')
        {
            printf("Invalid input.\n");
        }
    } 
    }

    // Calculate average of scores
    float n = (float) total_scores / score_count;
    printf("%.2f is the average score.\n", n);
}
