#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;  // To store process ID

    // Create a new process using fork
    pid = fork();

    if (pid < 0) {
        // If fork fails
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}


Example Output:
Case: Parent Process
Parent Process:
Process ID: 1234
Child Process ID: 1235


Case: Child Process
Child Process:
Process ID: 1235
Parent Process ID: 1234
