#include <stdio.h>

int main(void)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Elements in array: %d\n", (int) (sizeof(array) / sizeof(*array)));

    return 0;
}
