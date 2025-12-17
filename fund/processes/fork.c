#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Je suis le père, mon PID est %d\n", getpid());
    pid_t ret = fork();
    if (ret == 0) {
        printf("Je suis l'enfant, mon PID est %d, celui de mon père est %d\n", getpid(), getppid());
    } else {
        waitpid(ret, NULL, 0);
        printf("Mon enfant a terminé\n");
    }
}
