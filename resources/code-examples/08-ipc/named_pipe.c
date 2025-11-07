/*
 * Named Pipe (FIFO) Example
 * Demonstrates IPC using named pipes (FIFOs)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 100

int main() {
    pid_t pid;
    char buffer[BUFFER_SIZE];

    printf("=== Named Pipe (FIFO) Example ===\n\n");

    // Create named pipe (FIFO)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        // FIFO might already exist, continue anyway
    }

    printf("Named pipe '%s' created\n\n", FIFO_NAME);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // Child process - writer
        int fd;
        sleep(1);  // Ensure parent opens for reading first

        printf("Child: Opening FIFO for writing...\n");
        fd = open(FIFO_NAME, O_WRONLY);

        const char *msg = "Data from child via named pipe";
        printf("Child: Writing: '%s'\n", msg);
        write(fd, msg, strlen(msg) + 1);

        close(fd);
        exit(0);
    }
    else {
        // Parent process - reader
        int fd;

        printf("Parent: Opening FIFO for reading...\n");
        fd = open(FIFO_NAME, O_RDONLY);

        printf("Parent: Waiting for data...\n");
        read(fd, buffer, BUFFER_SIZE);

        printf("Parent: Received: '%s'\n\n", buffer);

        close(fd);

        // Wait for child
        wait(NULL);

        // Clean up - remove FIFO
        unlink(FIFO_NAME);
        printf("Named pipe removed\n");
    }

    return 0;
}
