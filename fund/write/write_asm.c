void _start() {
    const char msg[] = "Pure syscall, no libc or stdlib!";

    long ret;
    asm volatile(
        "syscall"
        : "=a" (ret)
        : "a" (1),
          "D" (1),
          "S"(msg),
          "d" (14)
        : "rcx", "r11", "memory"
    );

    asm volatile(
        "syscall"
        :
        :"a"(60),
         "D"(0)
        : "rcx", "r11", "memory"
    );
}
