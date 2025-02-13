#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("out.txt", O_CREAT);
    close(fd);
    fd = open("out.txt", O_WRONLY);
    write(fd, "aaa", 3);
    close(fd);
    fd = open("out.txt", O_WRONLY | O_TRUNC);
    write(fd, "bb", 2);
    close(fd);
}