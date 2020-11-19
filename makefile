cc=gcc
all:
	${cc} src/project.c src/readFile.c -o bin/main -I include
