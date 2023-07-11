#include <stdio.h>

int main(void)
{
    int number = 1;

    int *ptr = &number;

    printf("ptr's value is %d.\n", *ptr);

    return 0;
}
