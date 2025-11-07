/*
 * Pipe Example - Inter-Process Communication
 * Demonstrates communication between parent and child using pipes
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main() {
    int pipefd[2];  // pipefd[0] = read end, pipefd[1] = write end
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[BUFFER_SIZE];

    printf("=== Pipe Example ===\n\n");

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // Child process - reader
        close(pipefd[1]);  // Close write end

        printf("Child: Waiting to read from pipe...\n");
        ssize_t n = read(pipefd[0], read_msg, BUFFER_SIZE);
        read_msg[n] = '\0';

        printf("Child: Received: '%s'\n", read_msg);

        close(pipefd[0]);
    }
    else {
        // Parent process - writer
        close(pipefd[0]);  // Close read end

        printf("Parent: Writing to pipe: '%s'\n", write_msg);
        write(pipefd[1], write_msg, strlen(write_msg));

        close(pipefd[1]);
        wait(NULL);  // Wait for child
        printf("Parent: Child finished\n");
    }

    return 0;
}
