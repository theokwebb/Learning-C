// Check whether or not there is a remainder

#include <stdio.h>

int main(void)
{
    int numerator, denominator, ans;
    
    printf("Numerator: ");
    scanf("%i", &numerator);

    printf("Denominator: ");
    scanf("%i", &denominator);

    ans = numerator % denominator;

    if (ans <= 0)
    {
        printf("There is NO remainder.\n");
    }
    else
    {
        printf("There is a remainder.\n");
    }
    return 0;
}
