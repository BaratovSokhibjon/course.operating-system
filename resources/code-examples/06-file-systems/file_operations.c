/*
 * File I/O Operations
 * Demonstrates basic file operations using system calls
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 100

int main() {
    const char *filename = "test_file.txt";
    const char *content = "Hello, Operating Systems!\nThis is a test file.\n";
    char buffer[BUFFER_SIZE];
    int fd;
    ssize_t bytes_written, bytes_read;

    printf("=== File I/O Operations ===\n\n");

    // 1. Create and write to file
    printf("1. Creating and writing to file '%s'\n", filename);
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error opening file for writing");
        return 1;
    }

    bytes_written = write(fd, content, strlen(content));
    printf("   Wrote %zd bytes\n", bytes_written);
    close(fd);

    // 2. Read from file
    printf("\n2. Reading from file:\n");
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        return 1;
    }

    bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    buffer[bytes_read] = '\0';
    printf("   Read %zd bytes:\n", bytes_read);
    printf("   Content: %s\n", buffer);
    close(fd);

    // 3. Get file information
    printf("3. File information:\n");
    struct stat file_stat;
    if (stat(filename, &file_stat) == 0) {
        printf("   File size: %ld bytes\n", file_stat.st_size);
        printf("   Permissions: %o\n", file_stat.st_mode & 0777);
        printf("   Inode number: %lu\n", file_stat.st_ino);
    }

    // 4. Append to file
    printf("\n4. Appending to file:\n");
    fd = open(filename, O_WRONLY | O_APPEND);
    const char *append_text = "Appended line.\n";
    write(fd, append_text, strlen(append_text));
    close(fd);
    printf("   Appended text\n");

    // 5. Read entire file again
    printf("\n5. Final file content:\n");
    fd = open(filename, O_RDONLY);
    bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);
    close(fd);

    // Clean up
    unlink(filename);
    printf("File deleted.\n");

    return 0;
}
