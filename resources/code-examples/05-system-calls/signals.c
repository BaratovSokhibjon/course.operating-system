/*
 * Signal Handling
 * Demonstrates handling signals like SIGINT, SIGTERM
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t keep_running = 1;

void sigint_handler(int signum) {
    printf("\nCaught SIGINT (Ctrl+C)! Signal number: %d\n", signum);
    printf("Cleaning up...\n");
    keep_running = 0;
}

void sigterm_handler(int signum) {
    printf("\nCaught SIGTERM! Signal number: %d\n", signum);
    printf("Terminating gracefully...\n");
    exit(0);
}

void sigusr1_handler(int signum) {
    printf("\nReceived SIGUSR1! Signal number: %d\n", signum);
}

int main() {
    // Register signal handlers
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);
    signal(SIGUSR1, sigusr1_handler);

    printf("=== Signal Handling Example ===\n");
    printf("Process ID: %d\n", getpid());
    printf("Press Ctrl+C to send SIGINT\n");
    printf("Send SIGUSR1 with: kill -USR1 %d\n", getpid());
    printf("Send SIGTERM with: kill -TERM %d\n\n", getpid());

    int count = 0;
    while (keep_running) {
        printf("Running... (count: %d)\n", count++);
        sleep(2);
    }

    printf("Exiting gracefully.\n");
    return 0;
}
