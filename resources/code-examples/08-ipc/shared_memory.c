/*
 * Shared Memory Example
 * Demonstrates inter-process communication using shared memory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok(".", 'A');
    int shmid;
    char *shared_memory;
    pid_t pid;

    printf("=== Shared Memory Example ===\n\n");

    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        return 1;
    }

    printf("Shared memory created with ID: %d\n\n", shmid);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // Child process - writer
        shared_memory = (char *)shmat(shmid, NULL, 0);
        if (shared_memory == (char *)-1) {
            perror("shmat");
            return 1;
        }

        printf("Child: Writing to shared memory...\n");
        sprintf(shared_memory, "Message from child process (PID: %d)", getpid());

        shmdt(shared_memory);
        exit(0);
    }
    else {
        // Parent process - reader
        wait(NULL);  // Wait for child to write

        shared_memory = (char *)shmat(shmid, NULL, 0);
        if (shared_memory == (char *)-1) {
            perror("shmat");
            return 1;
        }

        printf("Parent: Reading from shared memory...\n");
        printf("Parent: Received: '%s'\n\n", shared_memory);

        shmdt(shared_memory);

        // Clean up - remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            return 1;
        }

        printf("Shared memory removed\n");
    }

    return 0;
}
