#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd_p1p2;
    char message[] = "a + b";

    mkfifo("C/Users/PC/Desktop/fifo_p1p2", 0666);

    fd_p1p2 = open("C/Users/PC/Desktop/fifo_p1p2", O_WRONLY);
    if (fd_p1p2 == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd_p1p2, message, strlen(message) + 1);

    close(fd_p1p2);

    return 0;
}
