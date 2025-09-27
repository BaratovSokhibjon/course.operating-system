/*
 * Exec Example - Process Replacement
 * Demonstrates how exec() replaces the current process image
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process - execute 'ls' command
        printf("Child: Executing ls command...\n");
        execlp("/bin/ls", "ls", "-l", NULL);

        // This line only executes if exec fails
        fprintf(stderr, "Exec failed!\n");
        return 1;
    }
    else {
        // Parent process waits for child
        int status;
        wait(&status);
        printf("Parent: Child process completed\n");
    }

    return 0;
}
