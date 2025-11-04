/*
 * Directory Operations
 * Demonstrates directory manipulation and traversal
 */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void list_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[1024];

    dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Contents of '%s':\n", path);
    printf("%-30s %-10s %s\n", "Name", "Type", "Size");
    printf("---------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Get full path
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get file stats
        if (stat(full_path, &file_stat) == 0) {
            const char *type = S_ISDIR(file_stat.st_mode) ? "DIR" : "FILE";
            printf("%-30s %-10s %ld bytes\n",
                   entry->d_name, type, file_stat.st_size);
        }
    }

    closedir(dir);
    printf("\n");
}

int main() {
    const char *test_dir = "test_directory";

    printf("=== Directory Operations ===\n\n");

    // 1. Create directory
    printf("1. Creating directory '%s'\n", test_dir);
    if (mkdir(test_dir, 0755) == 0) {
        printf("   Directory created successfully\n\n");
    } else {
        perror("   Error creating directory");
    }

    // 2. Create some test files in the directory
    printf("2. Creating test files:\n");
    char filepath[256];
    for (int i = 1; i <= 3; i++) {
        snprintf(filepath, sizeof(filepath), "%s/file%d.txt", test_dir, i);
        FILE *fp = fopen(filepath, "w");
        if (fp) {
            fprintf(fp, "Test file %d\n", i);
            fclose(fp);
            printf("   Created %s\n", filepath);
        }
    }
    printf("\n");

    // 3. List directory contents
    printf("3. Listing directory:\n");
    list_directory(test_dir);

    // 4. Get current working directory
    printf("4. Current working directory:\n");
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("   %s\n\n", cwd);
    }

    // 5. Clean up - remove files and directory
    printf("5. Cleaning up:\n");
    for (int i = 1; i <= 3; i++) {
        snprintf(filepath, sizeof(filepath), "%s/file%d.txt", test_dir, i);
        unlink(filepath);
        printf("   Removed %s\n", filepath);
    }

    rmdir(test_dir);
    printf("   Removed directory '%s'\n", test_dir);

    return 0;
}
