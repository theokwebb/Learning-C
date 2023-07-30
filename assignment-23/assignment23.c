#include <stdio.h>

typedef struct
{
    int i;
}st;

int main(void)
{
    // ptr of struct
    st *ptr = NULL;
    // instance of struct
    st instance;
    // ptr points to instance
    ptr = &instance;
    // assign a value by using standard dot-notation on the instance and then print the value
    instance.i = 9;
    printf("%d.\n", instance.i);
    // assign a value by using standard dot-notation for the pointer initialized to the instance
    if (ptr != NULL)
    {
        (*ptr).i = 1;
        printf("%d.\n", (*ptr).i);
    }
    // assign a value by using the arrow operator (->) between the pointer name and the structure member
    if (ptr != NULL)
    {
        ptr->i = 7;
        printf("%d.\n", ptr->i);
    }
    return 0;
}
