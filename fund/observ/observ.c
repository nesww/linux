#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        char *argv[] = {"/bin/sleep", "5", NULL};
        printf("Child PID: %d\n", getpid());
        execve(argv[0], argv, NULL);
    } else {
        printf("Reading child\n");
        char *proc_path = malloc(128);
        sprintf(proc_path, "cat /proc/%d/status", pid);
        system(proc_path);
        waitpid(pid, NULL, 0);
    }
}
