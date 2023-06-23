// Quadratic equation calculator
// Obtain the solution for ax^2 + bx + c = 0

#include <stdio.h>
#include <math.h>

void solve(double a, double b, double c);

int main(void)
{
    double a, b, c;

    printf("Quadratic Equation Calculator\n");

    printf("Input coefficient of x^2 (a): ");
    scanf("%lf", &a);

    printf("Input coefficient of x (b): ");
    scanf("%lf", &b);

    printf("Input constant (c): ");
    scanf("%lf", &c);

    solve(a, b, c);
}

void solve(double a, double b, double c)
{
    // Calculate discriminant (d) 
    double d = b * b - 4 * a * c;

    // If d is greater than or equal to 0
    if (d >= 0)
    {
        // Compute the two solutions
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);

        // If d is 0 there is ONE real solution
	    if (d == 0)
        {
            printf("Root: %.2lf\n", x1);
        }

        // If d is positive there is TWO real solutions
        else
        {
            printf("Root 1: %.2lf\n", x1);
            printf("Root 2: %.2lf\n", x2);
        }
    }
    // If d is < 0 then no real solution
    else
    {
        printf("No roots exist.\n");
    }
}
