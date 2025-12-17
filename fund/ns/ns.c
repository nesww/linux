#define _GNU_SOURCE
#include <signal.h>
#include <sched.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int child_func(void *arg) {
    printf("Hello, I'm in a different namespace for PIDs! will start bash...");
    char *argv[] = {"/bin/bash", NULL };
    execve(argv[0], argv, NULL);
    perror("execve failed");
    return 1;
}

int main() {
    printf("Starting...\n");
    char* child_stack = malloc(8192);
    if (!child_stack) {
        perror("malloc");
        exit(1);
    }
    pid_t pid = clone(child_func, child_stack + 8192, CLONE_NEWPID | SIGCHLD, NULL);
    if (pid == -1) {
        perror("clone");
        exit(1);
    }
    waitpid(pid, NULL, 0);
}
