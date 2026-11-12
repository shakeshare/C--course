#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("/dev/edu", O_RDONLY);
    if (fd == -1)
    {
        perror("can not open");
        return -1;
    }
    int ret = ioctl(fd, 0, 10);
    printf("ioctl write1: %d\n", 10);
    sleep(1);
    ret = ioctl(fd, 1, 0);
    printf("ioctl read1: %d\n", ret);
    ret = ioctl(fd, 0, 5);
    printf("ioctl write2: %d\n", 5);
    sleep(1);
    ret = ioctl(fd, 1, 0);
    printf("ioctl read2: %d\n", ret);
    close(fd);
    return 0;
}