#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_EMPLOYEES 2 // Total number of employees
#define BUF 64 // Buffer size

typedef struct
{
    char first_name[BUF];
    char last_name[BUF];
    char title[BUF];
    int id_number;
    int ssn; // Last 4 digits
} employee_profile;

typedef struct
{
    employee_profile employee[NUM_EMPLOYEES];
} employees;

void print_dept(employees dept);
void valid_str(char *str);
void valid_int(int *i);

int main(void)
{
    employees engr_dept;

    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("Enter employee %d's first name: ", i + 1);
        valid_str(engr_dept.employee[i].first_name);

        printf("Enter employee %d's last name: ", i + 1);
        valid_str(engr_dept.employee[i].last_name);

        printf("Enter employee %d's job title (do not include 'Engineer'): ", i + 1);
        valid_str(engr_dept.employee[i].title);

        printf("Enter employee %d's ID number: ", i + 1);
        valid_int(&(engr_dept.employee[i].id_number));

        printf("Enter the last four digits of employee %d's SSN: ", i + 1);
        valid_int(&(engr_dept.employee[i].ssn));

        // Checks if SSN is four digits
        while (!(engr_dept.employee[i].ssn >= 1000 && engr_dept.employee[i].ssn <= 9999))
        {
            printf("Please enter exactly four digits: ");
            valid_int(&(engr_dept.employee[i].ssn));
        }

        printf("\n");
    }
    print_dept(engr_dept);
}

// Prints employee details
void print_dept(employees dept)
{
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("Employee %s %s:\n", dept.employee[i].first_name, dept.employee[i].last_name);
        printf("ID: %d\n", dept.employee[i].id_number);
        printf("SSN: %d\n", dept.employee[i].ssn);
        printf("Title: %s Engineer\n\n", dept.employee[i].title);
    }
}

// Safely reads and validates user strings
void valid_str(char *str)
{
    char buf[BUF];

    do
    {
        if (fgets(buf, BUF, stdin))
        {
            // Check if the input length exceeds the maximum allowed length
            if (strlen(buf) > BUF - 1)
            {
                printf("Input is too long. Please enter 64 char or less: ");
            }
            else
            {
                buf[strcspn(buf, "\n")] = 0;
                strcpy(str, buf);
                break;
            }
        }
    } while (1);
}

// Safely reads and validates user integers
void valid_int(int *i)
{
    char buf[BUF];
    
    do
    {        
        if (!fgets(buf, sizeof(buf), stdin))
        {
            break;
        }
        
        char *endptr;
        errno = 0;
        *i = strtol(buf, &endptr, 10);

        // Check for invalid input: number too large, conversion incomplete, or invalid characters
        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n'))
        {
            printf("Invalid input. Please enter a number: ");
        }
        else
        {
            break;
        }
    } while (1);
}
