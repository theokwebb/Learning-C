#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char *cptr;
    cptr = malloc(10 * sizeof(char));
    if (cptr == NULL)
    {
        printf("Could not allocate memory.\n");
        return 1;
    }
    else
    {
        printf("Successfully allocated memory.\n");
    }
    free(cptr);
    return 0;
}
