/*
 * Common System Calls
 * Demonstrates frequently used system calls
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    printf("=== System Call Examples ===\n\n");

    // getpid() and getppid()
    printf("1. Process Information:\n");
    printf("   Current Process ID: %d\n", getpid());
    printf("   Parent Process ID: %d\n\n", getppid());

    // getuid() and getgid()
    printf("2. User/Group Information:\n");
    printf("   User ID: %d\n", getuid());
    printf("   Group ID: %d\n\n", getgid());

    // sleep()
    printf("3. Sleep for 2 seconds...\n");
    sleep(2);
    printf("   Woke up!\n\n");

    // fork() and wait()
    printf("4. Creating child process:\n");
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("   Child: My PID is %d\n", getpid());
        sleep(1);
        exit(42);  // Exit with status 42
    }
    else {
        // Parent process
        int status;
        printf("   Parent: Created child with PID %d\n", pid);
        wait(&status);

        if (WIFEXITED(status)) {
            printf("   Parent: Child exited with status %d\n\n",
                   WEXITSTATUS(status));
        }
    }

    // getcwd()
    printf("5. Current Working Directory:\n");
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("   %s\n\n", cwd);
    }

    // chdir()
    printf("6. Changing directory to /tmp:\n");
    if (chdir("/tmp") == 0) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("   New directory: %s\n", cwd);
        }
    }

    return 0;
}
