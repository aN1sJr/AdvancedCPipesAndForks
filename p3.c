#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd_p2p3;
    char a[10], b[10], op[10];
    int result;

    mkfifo("C/Users/PC/Desktop/fifo_p2p3", 0666);

    fd_p2p3 = open("C/Users/PC/Desktop/fifo_p2p3", O_RDONLY);
    if (fd_p2p3 == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd_p2p3, a, sizeof(a));
    read(fd_p2p3, b, sizeof(b));
    read(fd_p2p3, op, sizeof(op));

    close(fd_p2p3);

    if (strcmp(op, "+") == 0) {
        result = atoi(a) + atoi(b);
    } else {
        printf("Opérateur non pris en charge\n");
        exit(EXIT_FAILURE);
    }

    printf("%s %s %s = %d\n", a, op, b, result);

    return 0;
}
