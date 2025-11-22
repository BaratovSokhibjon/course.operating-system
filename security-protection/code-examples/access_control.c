/*
 * Access Control List (ACL) Simulator
 * Demonstrates role-based access control concepts
 */

#include <stdio.h>
#include <string.h>

#define MAX_RESOURCES 10
#define MAX_ROLES 5
#define MAX_NAME 32

// Permission flags
#define PERM_NONE    0
#define PERM_READ    1
#define PERM_WRITE   2
#define PERM_EXECUTE 4
#define PERM_DELETE  8

typedef struct {
    char name[MAX_NAME];
    int permissions[MAX_ROLES];  // Permissions for each role
} Resource;

typedef struct {
    char name[MAX_NAME];
} Role;

Resource resources[MAX_RESOURCES];
Role roles[MAX_ROLES];
int resource_count = 0;
int role_count = 0;

const char* perm_to_string(int perm) {
    static char buffer[16];
    snprintf(buffer, sizeof(buffer), "%c%c%c%c",
             (perm & PERM_READ)    ? 'r' : '-',
             (perm & PERM_WRITE)   ? 'w' : '-',
             (perm & PERM_EXECUTE) ? 'x' : '-',
             (perm & PERM_DELETE)  ? 'd' : '-');
    return buffer;
}

int add_role(const char *name) {
    if (role_count >= MAX_ROLES) {
        printf("Error: Maximum roles reached\n");
        return -1;
    }
    
    strncpy(roles[role_count].name, name, MAX_NAME - 1);
    printf("Role '%s' created (ID: %d)\n", name, role_count);
    return role_count++;
}

int find_role(const char *name) {
    for (int i = 0; i < role_count; i++) {
        if (strcmp(roles[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int add_resource(const char *name) {
    if (resource_count >= MAX_RESOURCES) {
        printf("Error: Maximum resources reached\n");
        return -1;
    }
    
    strncpy(resources[resource_count].name, name, MAX_NAME - 1);
    
    // Initialize all permissions to NONE
    for (int i = 0; i < MAX_ROLES; i++) {
        resources[resource_count].permissions[i] = PERM_NONE;
    }
    
    printf("Resource '%s' created\n", name);
    return resource_count++;
}

int find_resource(const char *name) {
    for (int i = 0; i < resource_count; i++) {
        if (strcmp(resources[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void set_permission(const char *resource_name, const char *role_name, int perm) {
    int res_id = find_resource(resource_name);
    int role_id = find_role(role_name);
    
    if (res_id < 0) {
        printf("Error: Resource '%s' not found\n", resource_name);
        return;
    }
    
    if (role_id < 0) {
        printf("Error: Role '%s' not found\n", role_name);
        return;
    }
    
    resources[res_id].permissions[role_id] = perm;
    printf("Set permissions for '%s' on '%s': %s\n",
           role_name, resource_name, perm_to_string(perm));
}

int check_access(const char *resource_name, const char *role_name, int required_perm) {
    int res_id = find_resource(resource_name);
    int role_id = find_role(role_name);
    
    if (res_id < 0 || role_id < 0) {
        return 0;
    }
    
    int allowed_perm = resources[res_id].permissions[role_id];
    return (allowed_perm & required_perm) == required_perm;
}

void print_acl(void) {
    printf("\n=== Access Control List ===\n");
    printf("%-20s", "Resource/Role");
    
    for (int i = 0; i < role_count; i++) {
        printf("%-12s", roles[i].name);
    }
    printf("\n");
    
    for (int i = 0; i < 20 + (role_count * 12); i++) {
        printf("-");
    }
    printf("\n");
    
    for (int i = 0; i < resource_count; i++) {
        printf("%-20s", resources[i].name);
        for (int j = 0; j < role_count; j++) {
            printf("%-12s", perm_to_string(resources[i].permissions[j]));
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    // Create roles
    add_role("Admin");
    add_role("Developer");
    add_role("User");
    add_role("Guest");
    
    // Create resources
    add_resource("/etc/passwd");
    add_resource("/var/log/system.log");
    add_resource("/home/user/document.txt");
    add_resource("/usr/bin/app");
    add_resource("/tmp/cache");
    
    printf("\n");
    
    // Set permissions (Admin has full access)
    set_permission("/etc/passwd", "Admin", PERM_READ | PERM_WRITE | PERM_DELETE);
    set_permission("/var/log/system.log", "Admin", PERM_READ | PERM_WRITE);
    set_permission("/home/user/document.txt", "Admin", PERM_READ | PERM_WRITE | PERM_DELETE);
    set_permission("/usr/bin/app", "Admin", PERM_READ | PERM_WRITE | PERM_EXECUTE | PERM_DELETE);
    set_permission("/tmp/cache", "Admin", PERM_READ | PERM_WRITE | PERM_DELETE);
    
    // Developer has read/write on code, execute on apps
    set_permission("/etc/passwd", "Developer", PERM_READ);
    set_permission("/var/log/system.log", "Developer", PERM_READ | PERM_WRITE);
    set_permission("/home/user/document.txt", "Developer", PERM_READ | PERM_WRITE);
    set_permission("/usr/bin/app", "Developer", PERM_READ | PERM_EXECUTE);
    set_permission("/tmp/cache", "Developer", PERM_READ | PERM_WRITE);
    
    // Regular user has limited access
    set_permission("/home/user/document.txt", "User", PERM_READ | PERM_WRITE);
    set_permission("/usr/bin/app", "User", PERM_EXECUTE);
    set_permission("/tmp/cache", "User", PERM_READ);
    
    // Guest has minimal access
    set_permission("/usr/bin/app", "Guest", PERM_EXECUTE);
    
    // Display ACL
    print_acl();
    
    // Test access control
    printf("=== Access Control Tests ===\n");
    
    struct {
        const char *role;
        const char *resource;
        int permission;
        const char *action;
    } tests[] = {
        {"Admin", "/etc/passwd", PERM_WRITE, "write"},
        {"User", "/etc/passwd", PERM_READ, "read"},
        {"Developer", "/var/log/system.log", PERM_WRITE, "write"},
        {"Guest", "/home/user/document.txt", PERM_READ, "read"},
        {"User", "/usr/bin/app", PERM_EXECUTE, "execute"},
        {"Guest", "/tmp/cache", PERM_WRITE, "write"},
    };
    
    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        int allowed = check_access(tests[i].resource, tests[i].role, tests[i].permission);
        printf("%-10s %s to %-30s: %s\n",
               tests[i].role,
               tests[i].action,
               tests[i].resource,
               allowed ? "✓ ALLOWED" : "✗ DENIED");
    }
    
    return 0;
}
