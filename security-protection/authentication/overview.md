# Authentication in Operating Systems

## Overview

Authentication is the process of verifying the identity of a user, process, or device before allowing access to system resources. It answers the question: "Who are you?"

## Authentication Factors

Authentication can be based on three main factors:

### 1. Something You Know
- Passwords
- PINs
- Security questions
- Passphrases

### 2. Something You Have
- Smart cards
- Hardware tokens
- Mobile devices
- Security keys (e.g., YubiKey)

### 3. Something You Are
- Fingerprints
- Facial recognition
- Iris scans
- Voice recognition
- Behavioral biometrics

## Multi-Factor Authentication (MFA)

Combining two or more authentication factors for stronger security.

**Common Combinations:**
- Password + SMS code
- Password + Hardware token
- Biometric + PIN
- Smart card + Password

**Benefits:**
- Significantly reduces risk of unauthorized access
- Protects against password theft
- Required for high-security environments

## Password-Based Authentication

### Password Storage

**Never store passwords in plaintext!**

#### Hashing
```
Plaintext Password → Hash Function → Stored Hash
"mypassword123" → SHA-256 → "ef92b778..."
```

**Common Hash Functions:**
- SHA-256, SHA-512
- bcrypt (with salt, recommended)
- Argon2 (winner of Password Hashing Competition)
- PBKDF2

#### Salting
Add random data to password before hashing to prevent rainbow table attacks:

```
Password + Random Salt → Hash Function → Stored Hash
"mypassword123" + "a4b8c9d2" → bcrypt → "$2a$12$..."
```

### Password Policies

**Complexity Requirements:**
- Minimum length (e.g., 8-12 characters)
- Mix of uppercase, lowercase, numbers, special characters
- No common words or patterns
- Not based on personal information

**Security Measures:**
- Password expiration (controversial)
- Password history (prevent reuse)
- Account lockout after failed attempts
- Password strength meters

### Common Password Attacks

1. **Brute Force**
   - Try all possible combinations
   - Time-consuming but guaranteed to work eventually

2. **Dictionary Attack**
   - Try common words and phrases
   - Much faster than brute force

3. **Rainbow Table**
   - Pre-computed hash tables
   - Defeated by salting

4. **Credential Stuffing**
   - Use leaked credentials from other breaches
   - Relies on password reuse

5. **Keylogging**
   - Record keystrokes to capture passwords
   - Hardware or software-based

## Unix/Linux Authentication

### PAM (Pluggable Authentication Modules)

Flexible framework for authentication in Linux systems.

**Configuration Files:**
```
/etc/pam.d/
  ├── common-auth
  ├── common-password
  ├── login
  ├── sshd
  └── sudo
```

**PAM Module Types:**
- `auth`: Authenticate users
- `account`: Check account validity
- `password`: Update authentication tokens
- `session`: Set up and tear down sessions

**Example PAM Configuration:**
```
# /etc/pam.d/sshd
auth       required     pam_unix.so
auth       required     pam_google_authenticator.so
account    required     pam_unix.so
password   required     pam_unix.so
session    required     pam_unix.so
```

### /etc/passwd and /etc/shadow

**`/etc/passwd`:** User account information
```
username:x:UID:GID:comment:home:shell
john:x:1001:1001:John Doe:/home/john:/bin/bash
```

**`/etc/shadow`:** Encrypted passwords and aging information
```
username:$algorithm$salt$hash:lastchange:min:max:warn:inactive:expire
john:$6$rounds=5000$salt$hash:19000:0:99999:7:::
```

**Password Algorithms:**
- `$1$` - MD5 (deprecated)
- `$5$` - SHA-256
- `$6$` - SHA-512
- `$2a$` or `$2y$` - bcrypt
- `$argon2i$` - Argon2

### Linux Login Process

1. User enters username and password
2. `login` program invoked
3. PAM modules consulted
4. Password checked against `/etc/shadow`
5. Account validity checked
6. Session established
7. Shell launched

## Windows Authentication

### Local Authentication

**SAM (Security Account Manager):**
- Stores local user credentials
- Password hashes stored in SAM database
- Protected by SYSKEY encryption

**NTLM (NT LAN Manager):**
- Challenge-response protocol
- Hash-based authentication
- Legacy protocol, still used for backward compatibility

### Domain Authentication

**Kerberos:**
- Network authentication protocol
- Used in Active Directory
- Ticket-based system
- Mutual authentication

**Kerberos Process:**
1. User requests TGT (Ticket Granting Ticket) from KDC
2. KDC authenticates and issues TGT
3. User presents TGT to request service ticket
4. User presents service ticket to access resource

### Windows Hello

Modern biometric authentication:
- Face recognition
- Fingerprint
- PIN
- Stored locally, not on servers

## Biometric Authentication

### Advantages
- Convenient (no need to remember)
- Difficult to lose or forget
- Hard to share or steal
- Quick authentication

### Challenges
- Cannot be changed if compromised
- Privacy concerns
- False acceptance/rejection rates
- Requires specialized hardware

### Common Biometric Methods

1. **Fingerprint**
   - Most common
   - Capacitive, optical, or ultrasonic sensors
   - ~1 in 50,000 false acceptance rate

2. **Facial Recognition**
   - Camera-based
   - 2D or 3D mapping
   - Vulnerable to photos (without liveness detection)

3. **Iris Scanning**
   - Very accurate
   - Requires specialized camera
   - Used in high-security environments

4. **Voice Recognition**
   - Analyzes voice characteristics
   - Can be affected by illness, stress
   - Vulnerable to recordings

## Certificate-Based Authentication

Uses public key cryptography for authentication.

### Public Key Infrastructure (PKI)

**Components:**
- Certificate Authority (CA)
- Registration Authority (RA)
- Digital certificates
- Certificate Revocation List (CRL)

### SSH Key Authentication

```bash
# Generate key pair
ssh-keygen -t rsa -b 4096

# Public key stored on server
~/.ssh/authorized_keys

# Private key stays on client
~/.ssh/id_rsa
```

**Advantages:**
- More secure than passwords
- Enables passwordless login
- Difficult to brute force

### Smart Cards

Physical devices containing cryptographic keys:
- PIV (Personal Identity Verification)
- CAC (Common Access Card)
- FIDO2/WebAuthn tokens

## Single Sign-On (SSO)

Authenticate once, access multiple systems.

### Protocols
- **SAML (Security Assertion Markup Language)**
  - XML-based
  - Enterprise applications

- **OAuth 2.0**
  - Authorization framework
  - "Login with Google/Facebook"

- **OpenID Connect**
  - Built on OAuth 2.0
  - Identity layer

### Benefits
- Improved user experience
- Reduced password fatigue
- Centralized access control
- Better security (fewer passwords)

### Risks
- Single point of failure
- If compromised, all systems accessible
- Requires robust security measures

## Session Management

After authentication, maintain authenticated state.

### Session Tokens
- Random, unpredictable values
- Stored server-side
- Sent to client (cookie, header)
- Validated on each request

### Best Practices
- Use secure, random session IDs
- Regenerate session ID after login
- Set appropriate timeout
- Use HTTPS only (secure cookies)
- Implement session fixation protection

## Authentication Vulnerabilities

### 1. Weak Passwords
- Short length
- Common patterns
- Personal information
- Default credentials

### 2. Credential Theft
- Phishing
- Man-in-the-middle attacks
- Keyloggers
- Database breaches

### 3. Session Hijacking
- Steal session tokens
- XSS (Cross-Site Scripting)
- Network sniffing

### 4. Replay Attacks
- Capture and reuse authentication data
- Defeated by timestamps, nonces

### 5. Brute Force
- Automated password guessing
- Mitigated by rate limiting, account lockout

## Zero Trust Authentication

Modern security model: "Never trust, always verify"

**Principles:**
- Verify explicitly
- Use least privilege access
- Assume breach

**Implementation:**
- Continuous authentication
- Context-aware access
- Micro-segmentation
- Multi-factor authentication

## Best Practices

1. **Enforce Strong Authentication**
   - Require MFA for sensitive access
   - Use strong password policies
   - Consider passwordless options

2. **Protect Credentials**
   - Never store passwords in plaintext
   - Use strong hashing algorithms
   - Implement proper salting

3. **Monitor and Audit**
   - Log authentication attempts
   - Alert on suspicious activity
   - Regular security audits

4. **Defense in Depth**
   - Multiple authentication layers
   - Combine different factors
   - Implement additional controls

5. **User Education**
   - Password security training
   - Phishing awareness
   - Report suspicious activity

## Future Trends

- **Passwordless Authentication**
  - FIDO2/WebAuthn
  - Biometrics
  - Hardware tokens

- **Continuous Authentication**
  - Behavioral biometrics
  - Risk-based authentication
  - Adaptive authentication

- **Blockchain-Based Identity**
  - Decentralized identity
  - Self-sovereign identity
  - Verifiable credentials

## Conclusion

Authentication is the first line of defense in system security. Modern systems should implement multiple authentication factors, protect credentials properly, and continuously monitor for threats while balancing security with usability.
