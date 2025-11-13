# Access Control in Operating Systems

## Overview

Access control is a security mechanism that determines who can access specific resources in an operating system and what operations they can perform on those resources.

## Access Control Models

### 1. Discretionary Access Control (DAC)

In DAC, the owner of a resource controls who can access it and what permissions they have.

**Characteristics:**
- Resource owners set permissions
- Users can pass permissions to others
- Flexible but potentially less secure
- Used in most modern operating systems (Unix/Linux, Windows)

**Example in Unix/Linux:**
```bash
# File permissions: owner, group, others
-rw-r--r--  1 user group 1024 Nov 10 10:00 file.txt
chmod 755 script.sh
chown user:group file.txt
```

### 2. Mandatory Access Control (MAC)

System-enforced access control based on classification levels.

**Characteristics:**
- Centralized policy enforcement
- Users cannot change access rights
- Based on security labels/classifications
- Used in high-security environments

**Examples:**
- SELinux (Security-Enhanced Linux)
- AppArmor
- Military/government systems

**Security Levels:**
- Top Secret
- Secret
- Confidential
- Unclassified

### 3. Role-Based Access Control (RBAC)

Access permissions are assigned based on user roles within an organization.

**Characteristics:**
- Permissions tied to roles, not individuals
- Users assigned to roles
- Easier to manage in large organizations
- Principle of least privilege

**Example Structure:**
```
Role: Database Administrator
Permissions:
  - Read database files
  - Write to database files
  - Backup database
  - Modify database schema

Role: Application User
Permissions:
  - Execute application
  - Read user data
  - Write user data
```

## Access Control Lists (ACLs)

ACLs specify which users or system processes can access objects and what operations can be performed.

### Linux ACL Example

```bash
# View ACL
getfacl file.txt

# Set ACL
setfacl -m u:john:rw file.txt  # Give john read-write access
setfacl -m g:developers:rx file.txt  # Give developers group read-execute

# Remove ACL
setfacl -x u:john file.txt
```

### Windows ACL

Windows uses Access Control Entries (ACEs) in ACLs:
- Allow/Deny permissions
- Inheritance from parent objects
- Special permissions (Full Control, Modify, Read & Execute, etc.)

## Access Control Matrix

A conceptual model showing subjects (users/processes), objects (files/resources), and access rights.

```
           File1    File2    Printer1
User1      RW       R        -
User2      R        RWX      W
Process1   RWX      -        RW
```

**Access Rights:**
- R: Read
- W: Write
- X: Execute

## Protection Rings

Modern processors provide hardware-based protection levels (rings):

```
Ring 0: Kernel (highest privilege)
Ring 1: Device drivers (some systems)
Ring 2: Device drivers (some systems)
Ring 3: User applications (lowest privilege)
```

**Purpose:**
- Prevent user programs from accessing privileged instructions
- Protect kernel memory from user-space access
- Isolate processes from each other

## Capabilities-Based Access Control

Instead of maintaining a central access control list, systems can use capabilities.

**Capability:** An unforgeable token that gives the holder specific rights to an object.

**Advantages:**
- Easier to delegate rights
- More fine-grained control
- Reduced need for central authorization

**Example Systems:**
- Cambridge CAP computer
- Capsicum (FreeBSD)
- Google Fuchsia

## File System Permissions

### Unix/Linux Permission Model

```
-rwxr-xr--  1 owner group size date filename
 ||||||||| 
 ||||||||||_ Other execute
 |||||||||__ Other write
 ||||||||___ Other read
 |||||||____ Group execute
 ||||||_____ Group write
 |||||______ Group read
 ||||_______ Owner execute
 |||________ Owner write
 ||_________ Owner read
 |__________ File type
```

### Special Permissions

1. **SUID (Set User ID)** - 4000
   - File executes with owner's permissions
   - Example: `passwd` command

2. **SGID (Set Group ID)** - 2000
   - File executes with group's permissions
   - On directories: new files inherit group

3. **Sticky Bit** - 1000
   - On directories: only owner can delete files
   - Example: `/tmp` directory

## Security Policies

### Bell-LaPadula Model
- Focuses on confidentiality
- **No Read Up:** Subject cannot read objects at higher security level
- **No Write Down:** Subject cannot write to objects at lower security level

### Biba Model
- Focuses on integrity
- **No Read Down:** Subject cannot read objects at lower integrity level
- **No Write Up:** Subject cannot write to objects at higher integrity level

### Clark-Wilson Model
- Commercial integrity model
- Well-formed transactions
- Separation of duties
- Audit trail

## Best Practices

1. **Principle of Least Privilege**
   - Grant minimum necessary permissions
   - Reduce attack surface

2. **Defense in Depth**
   - Multiple layers of security
   - Don't rely on single mechanism

3. **Regular Audits**
   - Review access logs
   - Audit permission changes
   - Monitor for unauthorized access

4. **Separation of Duties**
   - Divide critical tasks among multiple users
   - Prevent fraud and errors

5. **Default Deny**
   - Deny access unless explicitly granted
   - Safer than default allow

## Common Vulnerabilities

1. **Privilege Escalation**
   - Unauthorized increase in access rights
   - Exploit vulnerabilities to gain higher privileges

2. **Time-of-Check to Time-of-Use (TOCTOU)**
   - Race condition in access checking
   - File state changes between check and use

3. **Confused Deputy**
   - Privileged program misuses its authority
   - Tricked into performing unauthorized actions

4. **Access Control Bypass**
   - Direct access to resources without proper checks
   - Path traversal attacks

## Implementation Examples

### Linux Security Modules (LSM)

Framework for supporting various security models:
- SELinux
- AppArmor
- Smack
- TOMOYO

### Windows Security

- Security Descriptor
- Security Identifier (SID)
- Access Tokens
- User Account Control (UAC)

## Conclusion

Effective access control is fundamental to operating system security. Modern systems typically combine multiple access control mechanisms to provide robust protection while maintaining usability.
