#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    int filedescriptor = open("testfile.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (filedescriptor < 0)
    {
        printf("Open operation failed.\n");
        return 1;
    }
    else
    {
        printf("Open operation succeeded.\n");
        
        ssize_t total_bytes = sizeof("Hello World.\n") - 1;
        
        if (write(filedescriptor, "Hello World.\n", total_bytes) != total_bytes)
        {
            printf("There was an error writing to the file.\n");
            return 1;
        }
        else
        {
            printf("Text was successfully written to the file.\n");
        }
        
        if (close(filedescriptor) < 0)
        {
            printf("Close operation failed.\n");
            return 1;
        }
        else
        {
            printf("Close operation succeeded.\n");
        }
        return 0;
    }
}
