#include <stdio.h>

typedef struct
{
    char *name;
    int age;
    float height;
} person;

int main (void)
{
    person people[1];

    people[0].name = "who";
    people[0].age = 9;
    people[0].height = 1.2;

    printf("%s is %d at a height of %.1f.\n", people[0].name, people[0].age, people[0].height);

    return 0;
}
