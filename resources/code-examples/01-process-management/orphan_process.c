/*
 * Orphan Process Example
 * Demonstrates what happens when parent exits before child
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process sleeps
        printf("Child (PID %d, Parent %d): Sleeping for 5 seconds\n",
               getpid(), getppid());
        sleep(5);
        printf("Child (PID %d, Parent %d): Parent changed (adopted by init)\n",
               getpid(), getppid());
    }
    else {
        // Parent exits immediately
        printf("Parent (PID %d): Exiting immediately\n", getpid());
    }

    return 0;
}
