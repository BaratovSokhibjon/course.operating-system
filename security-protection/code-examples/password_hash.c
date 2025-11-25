/*
 * Password Hashing Example
 * Demonstrates secure password storage using crypt()
 * Compile with: gcc -o password_hash password_hash.c -lcrypt
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define MAX_PASSWORD_LEN 128

int main(void) {
    char password[MAX_PASSWORD_LEN];
    char *hashed_password;
    char *stored_hash = NULL;
    
    printf("Password Hashing Demo\n");
    printf("=====================\n\n");
    
    // Get password from user
    printf("Enter password to hash: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        fprintf(stderr, "Error reading password\n");
        return 1;
    }
    
    // Remove newline
    password[strcspn(password, "\n")] = 0;
    
    // Hash the password using SHA-512 with automatic salt generation
    // $6$ indicates SHA-512
    hashed_password = crypt(password, "$6$");
    
    if (hashed_password == NULL) {
        perror("crypt");
        return 1;
    }
    
    printf("\nHashed password:\n%s\n", hashed_password);
    
    // Store the hash (in a real application, save to database)
    stored_hash = strdup(hashed_password);
    
    // Clear the plaintext password from memory
    memset(password, 0, sizeof(password));
    
    // Verify password
    printf("\n--- Password Verification ---\n");
    printf("Enter password to verify: ");
    if (fgets(password, sizeof(password), stdin) == NULL) {
        fprintf(stderr, "Error reading password\n");
        return 1;
    }
    
    password[strcspn(password, "\n")] = 0;
    
    // Hash the entered password with the stored salt
    char *verify_hash = crypt(password, stored_hash);
    
    if (verify_hash == NULL) {
        perror("crypt");
        return 1;
    }
    
    // Compare hashes
    if (strcmp(stored_hash, verify_hash) == 0) {
        printf("✓ Password verified successfully!\n");
    } else {
        printf("✗ Password verification failed!\n");
    }
    
    // Clean up
    memset(password, 0, sizeof(password));
    
    return 0;
}
