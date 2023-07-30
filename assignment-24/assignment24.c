#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h> // needed for mode_t mode

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
        return 0;
    }
}
