cc=gcc
all:
	${cc} src/main.c src/readFile.c -o bin/main -I include
