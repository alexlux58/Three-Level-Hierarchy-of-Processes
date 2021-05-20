#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <errno.h>
#include    <sys/types.h>
#include    <sys/wait.h>

/*
* name: Alex Lux
* lab: Lab03
* date: 2/15/2021
*/


#define oops(m) {perror(m); exit(EXIT_FAILURE);}

int main() {
    pid_t pid;

    // fork a child process
    pid = fork();

    if (pid < 0) // error occurred
      oops("Fork Failed!");



    if (pid == 0) // child
    {
      pid_t pid2;

      pid2 = fork();

      if(pid2 < 0)
        oops("Fork Failed!");

      if (pid2 == 0){

        pid_t pid4;

        pid4 = fork();

        if (pid4 < 0)
          oops("Fork Failed!");

        if (pid4 == 0){

          printf("I am the child %d\n", getpid());

          if(execlp("./iam", "iam", "1.1.1", NULL) < 0)
            oops("Execlp Failed");

        }

        pid_t pid5;

        pid5 = fork();

        if (pid5 < 0)
          oops("Fork Failed!");

        if (pid5 == 0){

          printf("I am the child %d\n", getpid());

          if(execlp("./iam", "iam", "1.1.2", NULL) < 0)
            oops("Execlp Failed");

        }

        printf("I am the child %d\n", getpid());

        if (execlp("./iam", "iam", "1.1", NULL) < 0)
            oops("Execlp Failed!");
      }

        pid_t pid3;

        pid3 = fork();

        if(pid3 < 0)
          oops("Fork Failed!");

        if (pid3 == 0){

          pid_t pid6;

          pid6 = fork();

          if (pid6 < 0)
            oops("Fork Failed!");

      if (pid6 == 0){

        printf("I am the child %d\n", getpid());

        if(execlp("./iam", "iam", "1.2.1", NULL) < 0){
          oops("Execlp Failed");
        }
      }

      pid_t pid7;

      pid7 = fork();

      if (pid7 < 0)
        oops("Fork Failed!");

      if (pid7 == 0){

        printf("I am the child %d\n", getpid());

        if(execlp("./iam", "iam", "1.2.2", NULL) < 0)
          oops("Execlp Failed");

      }

          printf("I am the child %d\n", getpid());

          if (execlp("./iam", "iam", "1.2", NULL) < 0){
              oops("Execlp Failed!");
            }
        }


        printf("I am the child %d\n", getpid());

        if (execlp("./iam", "iam", "1", NULL) < 0)
            oops("Execlp Failed!");

            // pid > 0 ==> must be parent
            printf("I am the parent %d\n", getpid());
            /* parent will wait for the child to complete */
            if (waitpid(-1, NULL, 0) < 0)
                printf("-1 from wait() with errno = %d\n", errno);

            printf("Child terminated; parent exiting\n");
            exit(EXIT_SUCCESS);

    }

    // pid > 0 ==> must be parent
    printf("I am the parent %d\n", getpid());
    /* parent will wait for the child to complete */
    if (waitpid(-1, NULL, 0) < 0)
        printf("-1 from wait() with errno = %d\n", errno);

    printf("Child terminated; parent exiting\n");
    exit(EXIT_SUCCESS);
}
