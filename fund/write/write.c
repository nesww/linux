#include <unistd.h>

int main() {
    write(1, "Hello, syscall!\n", 16);
}
