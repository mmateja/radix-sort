all: build

build: radix.c
	gcc -Wall -Wextra -O2 -std=c99 -o radix radix.c
