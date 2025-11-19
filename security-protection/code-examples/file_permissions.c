/*
 * File Permission Checker
 * Demonstrates how to check file permissions in Unix/Linux
 */

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

void print_permissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

void print_special_permissions(mode_t mode) {
    if (mode & S_ISUID) printf(" SUID");
    if (mode & S_ISGID) printf(" SGID");
    if (mode & S_ISVTX) printf(" Sticky");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    
    if (stat(argv[1], &file_stat) == -1) {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Permissions: ");
    print_permissions(file_stat.st_mode);
    printf(" (%04o)", file_stat.st_mode & 07777);
    print_special_permissions(file_stat.st_mode);
    printf("\n");

    // Get owner information
    struct passwd *pw = getpwuid(file_stat.st_uid);
    struct group *gr = getgrgid(file_stat.st_gid);
    
    printf("Owner: %s (UID: %d)\n", 
           pw ? pw->pw_name : "unknown", file_stat.st_uid);
    printf("Group: %s (GID: %d)\n", 
           gr ? gr->gr_name : "unknown", file_stat.st_gid);
    printf("Size: %ld bytes\n", file_stat.st_size);
    
    // Check if current user can access the file
    printf("\nAccess checks for current user:\n");
    printf("  Read:    %s\n", (access(argv[1], R_OK) == 0) ? "Yes" : "No");
    printf("  Write:   %s\n", (access(argv[1], W_OK) == 0) ? "Yes" : "No");
    printf("  Execute: %s\n", (access(argv[1], X_OK) == 0) ? "Yes" : "No");

    return 0;
}
