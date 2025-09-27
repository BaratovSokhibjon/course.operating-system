/*
 * Fork Example - Process Creation
 * Demonstrates how fork() creates a child process
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int x = 10;

    printf("Before fork: PID = %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        x = 20;
        printf("Child process: PID = %d, Parent PID = %d, x = %d\n",
               getpid(), getppid(), x);
    }
    else {
        // Parent process
        x = 30;
        printf("Parent process: PID = %d, Child PID = %d, x = %d\n",
               getpid(), pid, x);
    }

    printf("Process %d: x = %d (demonstrating separate address spaces)\n",
           getpid(), x);

    return 0;
}
