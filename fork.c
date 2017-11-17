#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int randnum () {
  rand();
  return rand()%16 + 5;
}

int main() {
    srand(time(NULL));
    pid_t childone, childtwo;
    int status;

    printf ("This is the parent process before the fork.\n");
    printf ("      pid = %d\n\n", getpid());

    childone = fork();
    if (childone == 0) { //first child
      printf ("This is the first child process.\n");
      printf ("      pid = %d\n\n", getpid());
      rand();
      int i = randnum();
      sleep (i);
      printf("First child process slept for %d seconds! \n\n", i);
      return i;
    } else {
      int childtwo = fork();
      if (childtwo == 0) { //second child
        printf("This is the second child process.\n");
        printf ("      pid = %d\n\n", getpid());
        int i = randnum();
        sleep(i);
        printf("Second child process slept for %d seconds! \n\n", i);
        return i;
      } else { //parent
        int child = wait(&status);
        printf("This is the parent. I waited %d seconds for my child %d to wake up!\n\n", WEXITSTATUS(status), child);
      }

    }

    return 0;
}
