#include <stdio.h>

int main(void)
{
    int number = 1;

    int *ptr = &number;

    // ptr's value is number's memory address
    printf("ptr's value is: %p.\n", ptr);

    printf("number's memory address is: %p.\n", &number);

    return 0;
}
