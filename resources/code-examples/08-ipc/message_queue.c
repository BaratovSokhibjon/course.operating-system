/*
 * Message Queue Example
 * Demonstrates IPC using message queues
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_TEXT 512

// Message structure
struct message {
    long msg_type;
    char msg_text[MAX_TEXT];
};

int main() {
    key_t key = ftok(".", 'B');
    int msgid;
    struct message msg;
    pid_t pid;

    printf("=== Message Queue Example ===\n\n");

    // Create message queue
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid < 0) {
        perror("msgget");
        return 1;
    }

    printf("Message queue created with ID: %d\n\n", msgid);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // Child process - sender
        sleep(1);  // Ensure parent is waiting

        msg.msg_type = 1;
        sprintf(msg.msg_text, "Hello from child process (PID: %d)", getpid());

        printf("Child: Sending message: '%s'\n", msg.msg_text);

        if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        exit(0);
    }
    else {
        // Parent process - receiver
        printf("Parent: Waiting for message...\n");

        if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0) == -1) {
            perror("msgrcv");
            return 1;
        }

        printf("Parent: Received message: '%s'\n\n", msg.msg_text);

        wait(NULL);  // Wait for child

        // Clean up - remove message queue
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            return 1;
        }

        printf("Message queue removed\n");
    }

    return 0;
}
