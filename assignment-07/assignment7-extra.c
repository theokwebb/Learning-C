// Quadratic equation calculator
// Obtain the solution for ax^2 + bx + c = 0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(double a, double b, double c);

int main(void)
{
    double a, b, c;
    char buf[1024];

    printf("Quadratic Equation Calculator\n");

    for (int i = 0; i < 3; i++)
    {
        const char *coefficient;

        switch (i)
        {
            case 0:
                coefficient = "coefficient of x^2 (a)";
                break;
            case 1:
                coefficient = "coefficient of x (b)";
                break;
            case 2:
                coefficient = "constant (c)";
                break;
        }

        do
        {
            printf("Input %s: ", coefficient);
            
            if (!fgets(buf, sizeof(buf), stdin))
            {
                // Reading input failed:
                return 1;
            }

            // Track the end of the converted portion of the input string
            char *endptr;
            double value = strtod(buf, &endptr);
            
            // Check if there are invalid characters present or the conversion was incomplete
            if (endptr == buf || (*endptr && *endptr != '\n'))
            {
                printf("Invalid input. Please enter a valid number.\n");
            }
            else
            {
                switch (i)
                {
                    case 0:
                        a = value;
                        break;
                    case 1:
                        b = value;
                        break;
                    case 2:
                        c = value;
                        break;
                }
                break;
            }
        } while (1);
    }

    solve(a, b, c);

    return 0;
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
