/*
 * Alarm and Timer
 * Demonstrates using alarm() system call
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int alarm_count = 0;

void alarm_handler(int signum) {
    alarm_count++;
    printf("ALARM! Count: %d\n", alarm_count);

    if (alarm_count < 5) {
        alarm(2);  // Set another alarm for 2 seconds
    } else {
        printf("Maximum alarms reached. Exiting.\n");
        exit(0);
    }
}

int main() {
    printf("=== Alarm Example ===\n");
    printf("Setting up alarm to trigger every 2 seconds\n\n");

    // Register alarm handler
    signal(SIGALRM, alarm_handler);

    // Set first alarm for 2 seconds
    alarm(2);

    // Keep program running
    while (1) {
        printf("Working...\n");
        sleep(1);
    }

    return 0;
}
