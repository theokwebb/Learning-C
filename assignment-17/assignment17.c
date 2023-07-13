#include <stdio.h>

void prints(char *s);

int main(void)
{
    char s[] = "Hello, World!";
    prints(s);
    return 0;
}

void prints(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
