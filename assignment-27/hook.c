#define _GNU_SOURCE

#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

ssize_t write(int fd, const void *buf, size_t count)
{
    ssize_t (*new_write)(int fd, const void *buf, size_t count);
    int result;
    new_write = dlsym(RTLD_NEXT, "write");

    if (strcmp(buf, "Hello World.\n") == 0)
    {
        ssize_t total_bytes = sizeof("Goodbye, cruel world!\n") - 1;
        result = new_write(fd, "Goodbye, cruel world!\n", total_bytes);
    }
    else
    {
        result = new_write(fd, buf, count);
    }
    return result;
}
