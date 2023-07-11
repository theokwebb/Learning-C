#include <stdio.h>

int main (void)
{
    int variable = 9;

    int *ptr = &variable;

    printf("Value of int variable is: %d.\n", variable);
    printf("Value of the pointer to the int variable is: %p.\n", ptr);
    printf("Memory address of the int variable is: %p.\n", &variable);
    printf("Value held at the memory location that the pointer is pointing to is: %d.\n", *ptr);
}
