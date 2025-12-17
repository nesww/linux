#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Je suis le père, mon PID est %d\n", getpid());
    pid_t ret = fork();
    if (ret == 0) {
        printf("Je vais devenir ls!");
        char *args[] = {"/usr/bin/ls", "-l" ,NULL};
        execve("/usr/bin/ls", args, NULL);
        printf("Je ne devrais jamais être affiché!");
    } else {
        waitpid(ret, NULL, 0);
        printf("Mon enfant a terminé\n");
    }
}
