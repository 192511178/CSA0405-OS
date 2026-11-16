
# Smart Hospital – Operating System Assignment

## Project Overview

This repository contains the practical C programs developed for the Operating Systems Assignment.

The project demonstrates important operating-system concepts using a Smart Hospital computing environment.

## Technologies Used

- Programming Language: C
- Operating System: Linux / Ubuntu
- Compiler: GCC
- System Calls: fork(), exec(), waitpid(), read(), write()
- Thread Library: POSIX Pthreads

## Programs Included

### Task 6 – Cost of System Calls
Demonstrates file copying using read() and write() system calls.

Tests different buffer sizes:
- 1 byte
- 512 bytes
- 4096 bytes

### Task 7 – Process Control System Calls
Demonstrates:
- fork()
- execlp()
- waitpid()
- Process termination

### Task 10 – Performance Measurement
Compares:
- Creation of 1000 processes
- Creation of 1000 threads
- Execution time measurement

## Compilation and Execution

### Task 6
```bash
gcc -Wall -Wextra task6.c -o task6
./task6
```

### Task 7
```bash
gcc -Wall -Wextra task7.c -o task7
./task7
```

### Task 10
```bash
gcc -Wall -Wextra task10.c -pthread -o task10
./task10
```

## Performance Measurement

Use the following command:

```bash
/usr/bin/time -v ./task6
```

To trace system calls:

```bash
strace -c ./task6
```

## Conclusion

This project demonstrates how operating systems manage file operations, system calls, process creation, thread creation, and performance measurement.

The practical experiments help understand the importance of system-call efficiency, process management, and resource utilization in a Smart Hospital environment.
