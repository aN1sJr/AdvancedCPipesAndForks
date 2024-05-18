#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int pipefd[2];
  pid_t pid; 

  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(1);
  }

  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  if (pid == 0) { 
    char messageRecu[500];
    char messageInverse[500];

    read(pipefd[0], messageRecu, 500);

    int i, j;
    for (i = 0, j = strlen(messageRecu) - 1; i < strlen(messageRecu); i++, j--) {
      messageInverse[i] = messageRecu[j];
    }
    messageInverse[strlen(messageRecu)] = '\0';

    write(pipefd[1], messageInverse, strlen(messageInverse) + 1);

  } else { 
    char message[500];

    printf("Entrez un message : ");
    fgets(message, 500, stdin);

    write(pipefd[1], message, strlen(message) + 1);

    char messageInverse[500];
    read(pipefd[0], messageInverse, 500);

    printf("Message inversé : %s\n", messageInverse);
  }

  close(pipefd[0]);
  close(pipefd[1]);

  return 0;
}
