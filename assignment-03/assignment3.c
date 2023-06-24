#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *first = NULL;
    char *second = NULL;

    printf("First name: ");
    scanf("%ms", &first);
    printf("Second name: ");
    scanf("%ms", &second);

    printf("Hi %s %s.\n", first, second);

    free(first);
    free(second);
}
