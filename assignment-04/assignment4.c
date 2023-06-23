// Area of a Circle Calculator

#include <stdio.h>
#include <stdlib.h>

// Value of PIE
#define PI 3.14

int main(void)
{
    float radius;

    printf("Radius of circle: ");
    scanf("%f", &radius);

    float area = radius * radius * PI;

    printf("Area of circle %f\n", area);

    return 0;
}
