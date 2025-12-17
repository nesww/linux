savedcmd_/home/sato/linux/modules/hello/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/sato/linux/modules/hello/"$$0) }' > /home/sato/linux/modules/hello/hello.mod
