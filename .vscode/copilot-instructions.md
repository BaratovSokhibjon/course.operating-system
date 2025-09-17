# GitHub Copilot Instructions for Operating Systems Course

This repository is for studying and practicing concepts from the Operating Systems course at Inha University. To get the most out of GitHub Copilot, follow these guidelines:

## General Coding Practices
- **Write system-level code**: Focus on C/C++ for kernel-level programming and system calls.
- **Comment complex algorithms**: Explain scheduling algorithms, memory management, and synchronization.
- **Use proper error handling**: Always check return values for system calls.
- **Document system behavior**: Include explanations of OS concepts and implementations.
- **Version control system configurations**: Track different OS configurations and implementations.

## Copilot Usage Tips
- **Provide OS context**: Start prompts with specific operating system concepts and requirements.
- **Review for system correctness**: Ensure suggestions follow OS principles and avoid race conditions.
- **Ask for OS explanations**: Use Copilot to explain system call behavior and kernel mechanisms.
- **Leverage for system programming**: Use Copilot for process management, threading, and IPC code.

## Project Structure
This repository is organized by **operating system topics and concepts**:

### Core OS Topics
- `fundamentals/`: Basic OS concepts, system calls, and kernel architecture
- `process-management/`: Processes, threads, scheduling, and synchronization
- `memory-management/`: Virtual memory, paging, and segmentation
- `file-systems/`: File management, directory structures, and storage devices
- `security-protection/`: Access control, authentication, and system security

### Supporting Materials
- `practical-labs/`: Hands-on programming assignments and system implementations
- `resources/`: Code examples, lecture materials, and reference guides
- `assignments/`: Course assignments organized by topic

### File Organization
- Use C/C++ for system programming assignments
- Include shell scripts for automation and testing
- Document system specifications in markdown files
- Keep compiled binaries out of version control

## OS-Specific Guidelines

### Process Management (`process-management/`)
- Implement process creation, termination, and communication
- Work with POSIX threads and synchronization primitives
- Design and implement scheduling algorithms (FCFS, SJF, Round Robin)
- Handle race conditions and deadlock prevention

### Memory Management (`memory-management/`)
- Implement virtual memory systems and page replacement algorithms
- Work with memory allocation and deallocation
- Design paging and segmentation systems
- Handle memory protection and address translation

### File Systems (`file-systems/`)
- Implement file allocation methods (contiguous, linked, indexed)
- Design directory structures and file system operations
- Work with disk scheduling algorithms
- Handle file permissions and metadata

## Example Copilot Prompts
- "# Implement a round-robin CPU scheduling algorithm in C"
- "# Create a producer-consumer solution using semaphores"
- "# Write a system call wrapper for process creation"
- "# Implement the LRU page replacement algorithm"
- "# Design a simple shell with command parsing"
- "# Create a file system simulator with basic operations"
- "# Implement mutex locks for thread synchronization"
- "# Write a deadlock detection algorithm"

## Key Libraries and Tools
- **System Programming**: POSIX API, pthreads, system calls
- **Development**: GCC, GDB, Make, Valgrind
- **Synchronization**: mutexes, semaphores, condition variables
- **IPC**: pipes, message queues, shared memory
- **File I/O**: open(), read(), write(), lseek()

## Best Practices for OS Programming
- **Always check return values** from system calls
- **Handle signals properly** in multi-process programs  
- **Use proper synchronization** to avoid race conditions
- **Test with multiple processes/threads** to verify correctness
- **Document assumptions** about system behavior and limitations
- **Profile performance** for scheduling and memory algorithms

## Exclusions
- Do not commit compiled binaries or object files
- Avoid hardcoding system-specific paths
- Keep core dump files out of the repository
- Ignore IDE-specific files and temporary build artifacts

## Workflow Tips
- Create branches for different OS implementations
- Use descriptive commit messages referencing OS concepts
- Include performance analysis for algorithms
- Cross-reference OS theory with practical implementations
- Test code on different Unix/Linux systems when possible

---

*Edit this file to add more instructions as you discover useful Copilot workflows for operating systems development.*

## General Coding Practices
- **Write clear, concise code**: Use meaningful variable and function names.
- **Keep notebooks minimal**: Use only necessary comments and print statements, avoid lengthy explanations.
- **Divide code into logical cells**: Separate imports, data setup, processing, and results into distinct cells.
- **Focus on functionality over documentation**: Let the code speak for itself with clear variable names.
- **Prefer Python and Jupyter Notebooks**: Most course work is in Python, using pandas, numpy, matplotlib, and seaborn.

## Copilot Usage Tips
- **Prompt Copilot with context**: Start comments or code cells with a clear description of your goal.
- **Review suggestions**: Always check Copilot's code for correctness and relevance.
- **Ask for explanations**: Use Copilot to explain code, suggest improvements, or generate visualizations.
- **Use Copilot for repetitive tasks**: E.g., data cleaning, plotting, or summary statistics.

## Project Structure
This repository is organized by **topics and concepts** rather than weeks, making it easier to find related content:

### Core Learning Topics
- `foundations/`: Basic Python, data structures, and course introduction
- `data-analysis/`: Exploratory data analysis, visualization, and statistical analysis
- `machine-learning/`: Supervised/unsupervised learning algorithms and model evaluation
- `deep-learning/`: Neural networks, computer vision, and NLP
- `applications/`: Real-world projects, case studies, and final project

### Supporting Materials
- `resources/`: Reference materials including lecture slides, papers, and cheat sheets
- `assignments/`: Course assignments organized by topic
- `.vscode/`: VS Code settings and this instruction file

### File Organization
- Each topic has `notebooks/` subdirectories for Jupyter notebooks
- Group related notebooks by specific concepts (e.g., classification, regression)
- Place small reference datasets in `resources/datasets/` (**avoid committing large files**)

## Best Practices for Notebooks
- **Import only necessary libraries**.
- **Separate code into logical cells**: One cell for imports, one for data setup, separate cells for each major operation.
- **Use minimal, functional comments**: Only comment what the code does, not why (unless complex logic).
- **Print only essential results**: Show original data, intermediate steps, and final verification.
- **Restart and run all cells before submission** to ensure reproducibility.
- **Handle missing values and outliers** as shown in class examples.
- **Create clean, focused visualizations** using matplotlib or seaborn.

## Example Copilot Prompts
- "# Import required libraries"
- "# Create dataset with missing values"
- "# Fill missing numeric values with median"
- "# Fill missing categorical values with mode"
- "# Verify all missing values handled"
- "# Create scatter plot"
- "# Calculate correlation coefficient"
- "# Train linear regression model"
- "# Build classification model"
- "# Perform K-means clustering"

## Topic-Specific Guidelines

### Data Analysis (`data-analysis/`)
- Focus on pandas, numpy, matplotlib, and seaborn
- Minimal data exploration - show dataset structure and key statistics only
- Use concise print statements to display results

### Machine Learning (`machine-learning/`)
- Use scikit-learn for traditional ML algorithms
- Show only essential metrics and results
- Separate model training, evaluation, and results into different cells

### Deep Learning (`deep-learning/`)
- Use TensorFlow or PyTorch
- Focus on code implementation over detailed explanations
- Show training progress with minimal output
- Display only final model performance

## Exclusions
- Do not commit large datasets (>10MB) - use `resources/datasets/` only for small reference files
- Ignore model checkpoints, outputs, and temporary files
- Avoid committing virtual environments and build artifacts
- Keep sensitive data and API keys out of the repository

## Workflow Tips
- Create topic-specific branches for major assignments
- Use descriptive commit messages that reference the topic area
- Keep notebooks focused on single concepts for better organization
- Cross-reference related notebooks in different topic areas when beneficial