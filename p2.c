#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd_p1p2, fd_p2p3;
    char message[100];
    char a[10], b[10], op[10];
    
    mkfifo("C/Users/PC/Desktop/fifo_p1p2", 0666);

    fd_p1p2 = open("C/Users/PC/Desktop/fifo_p1p2", O_RDONLY);
    if (fd_p1p2 == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd_p1p2, message, sizeof(message));

    sscanf(message, "%s %s %s", a, op, b);

    close(fd_p1p2);

    mkfifo("C/Users/PC/Desktop/fifo_p2p3", 0666);

    fd_p2p3 = open("C/Users/PC/Desktop/fifo_p2p3", O_WRONLY);
    if (fd_p2p3 == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd_p2p3, a, strlen(a) + 1);
    write(fd_p2p3, b, strlen(b) + 1);
    write(fd_p2p3, op, strlen(op) + 1);

    close(fd_p2p3);

    return 0;
}
