/*
 * User Authentication Simulator
 * Demonstrates basic authentication mechanisms
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_USERS 10
#define MAX_USERNAME 32
#define MAX_PASSWORD 64
#define MAX_ATTEMPTS 3
#define LOCKOUT_TIME 30  // seconds

typedef struct {
    char username[MAX_USERNAME];
    char password_hash[MAX_PASSWORD]; // In real system, use proper hashing
    int failed_attempts;
    time_t lockout_until;
    int is_active;
} User;

User users[MAX_USERS];
int user_count = 0;

// Simple hash function (NOT secure - for demonstration only!)
unsigned long simple_hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

int add_user(const char *username, const char *password) {
    if (user_count >= MAX_USERS) {
        printf("Error: Maximum users reached\n");
        return 0;
    }
    
    strncpy(users[user_count].username, username, MAX_USERNAME - 1);
    snprintf(users[user_count].password_hash, MAX_PASSWORD, 
             "%lu", simple_hash(password));
    users[user_count].failed_attempts = 0;
    users[user_count].lockout_until = 0;
    users[user_count].is_active = 1;
    user_count++;
    
    printf("User '%s' added successfully\n", username);
    return 1;
}

User* find_user(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

int authenticate(const char *username, const char *password) {
    User *user = find_user(username);
    
    if (!user) {
        printf("Authentication failed: User not found\n");
        return 0;
    }
    
    if (!user->is_active) {
        printf("Authentication failed: Account disabled\n");
        return 0;
    }
    
    // Check if account is locked out
    time_t now = time(NULL);
    if (user->lockout_until > now) {
        printf("Authentication failed: Account locked for %ld more seconds\n",
               user->lockout_until - now);
        return 0;
    }
    
    // Verify password
    char hash[MAX_PASSWORD];
    snprintf(hash, MAX_PASSWORD, "%lu", simple_hash(password));
    
    if (strcmp(user->password_hash, hash) == 0) {
        printf("Authentication successful! Welcome, %s\n", username);
        user->failed_attempts = 0;
        user->lockout_until = 0;
        return 1;
    } else {
        user->failed_attempts++;
        printf("Authentication failed: Invalid password (Attempt %d/%d)\n",
               user->failed_attempts, MAX_ATTEMPTS);
        
        if (user->failed_attempts >= MAX_ATTEMPTS) {
            user->lockout_until = time(NULL) + LOCKOUT_TIME;
            printf("Account locked for %d seconds due to too many failed attempts\n",
                   LOCKOUT_TIME);
        }
        return 0;
    }
}

void print_menu(void) {
    printf("\n=== Authentication System ===\n");
    printf("1. Add user\n");
    printf("2. Login\n");
    printf("3. List users\n");
    printf("4. Exit\n");
    printf("Choice: ");
}

int main(void) {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int choice;
    
    // Add some default users
    add_user("admin", "admin123");
    add_user("user1", "password");
    add_user("alice", "secret");
    
    while (1) {
        print_menu();
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("Invalid input\n");
            continue;
        }
        while (getchar() != '\n'); // Clear newline
        
        switch (choice) {
            case 1:
                printf("Enter username: ");
                if (fgets(username, sizeof(username), stdin) != NULL) {
                    username[strcspn(username, "\n")] = 0;
                    printf("Enter password: ");
                    if (fgets(password, sizeof(password), stdin) != NULL) {
                        password[strcspn(password, "\n")] = 0;
                        add_user(username, password);
                    }
                }
                break;
                
            case 2:
                printf("Username: ");
                if (fgets(username, sizeof(username), stdin) != NULL) {
                    username[strcspn(username, "\n")] = 0;
                    printf("Password: ");
                    if (fgets(password, sizeof(password), stdin) != NULL) {
                        password[strcspn(password, "\n")] = 0;
                        authenticate(username, password);
                    }
                }
                break;
                
            case 3:
                printf("\nRegistered users:\n");
                for (int i = 0; i < user_count; i++) {
                    printf("  - %s (Active: %s, Failed attempts: %d)\n",
                           users[i].username,
                           users[i].is_active ? "Yes" : "No",
                           users[i].failed_attempts);
                }
                break;
                
            case 4:
                printf("Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
