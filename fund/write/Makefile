CC=cc

all: write asm

write: write.c
	$(CC) write.c -o build/write

asm: write_asm.c
	$(CC) write_asm.c -o build/write_asm -nostdlib -fno-stack-protector -static

clean:
	rm -rf build/*
