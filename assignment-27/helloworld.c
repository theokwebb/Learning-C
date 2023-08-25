#include <unistd.h>
#include <stdio.h>

int main(void)
{
    ssize_t total_bytes = sizeof("Hello World.\n") - 1;
        
    if (write(1, "Hello World.\n", total_bytes) != total_bytes)
    {
        return 1;
    }
}
