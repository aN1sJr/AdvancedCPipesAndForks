#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
  int choix = 1;
  int i= 0;
  while (fork()==0 && choix == 1){
    printf("vous avez le processus numero %d \n si vous vouler continuer taper 1 sinon 0 : ",i+1);
    scanf("%d", &choix);
    i++;
  }

  exit (0);
}