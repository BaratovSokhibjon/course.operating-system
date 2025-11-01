/*
 * File Permissions and Access Control
 * Demonstrates checking and modifying file permissions
 */

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void print_permissions(mode_t mode) {
    printf("Permissions: ");
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
    printf(" (octal: %o)\n", mode & 0777);
}

int main() {
    const char *filename = "permissions_test.txt";
    struct stat file_stat;
    int fd;

    printf("=== File Permissions Example ===\n\n");

    // 1. Create file with specific permissions
    printf("1. Creating file with permissions 0644:\n");
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error creating file");
        return 1;
    }
    write(fd, "Test content\n", 13);
    close(fd);

    stat(filename, &file_stat);
    printf("   ");
    print_permissions(file_stat.st_mode);

    // 2. Change permissions to 0755
    printf("\n2. Changing permissions to 0755:\n");
    chmod(filename, 0755);
    stat(filename, &file_stat);
    printf("   ");
    print_permissions(file_stat.st_mode);

    // 3. Check file access
    printf("\n3. Checking file access:\n");
    printf("   Readable: %s\n", access(filename, R_OK) == 0 ? "Yes" : "No");
    printf("   Writable: %s\n", access(filename, W_OK) == 0 ? "Yes" : "No");
    printf("   Executable: %s\n", access(filename, X_OK) == 0 ? "Yes" : "No");

    // 4. Display file metadata
    printf("\n4. File metadata:\n");
    printf("   Size: %ld bytes\n", file_stat.st_size);
    printf("   Inode: %lu\n", file_stat.st_ino);
    printf("   Links: %lu\n", file_stat.st_nlink);
    printf("   User ID: %d\n", file_stat.st_uid);
    printf("   Group ID: %d\n", file_stat.st_gid);

    // Clean up
    unlink(filename);
    printf("\nFile deleted.\n");

    return 0;
}
