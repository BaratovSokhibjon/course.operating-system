/*
 * Zombie Process Example
 * Demonstrates what happens when parent doesn't wait for child
 */

#include <stdio.h>
#include <stdlib.h>
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
        // Child process exits immediately
        printf("Child (PID %d): Exiting now\n", getpid());
        exit(0);
    }
    else {
        // Parent doesn't wait for child
        printf("Parent (PID %d): Child created with PID %d\n", getpid(), pid);
        printf("Parent: Sleeping for 10 seconds (child becomes zombie)\n");
        printf("Run 'ps aux | grep Z' in another terminal to see zombie process\n");
        sleep(10);
        printf("Parent: Exiting (zombie will be cleaned up by init)\n");
    }

    return 0;
}
