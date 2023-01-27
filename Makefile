#CC = gcc

all: main.c library
	gcc -L main.c  -lant.so -lncursesw -o ant


library: langton.c visualiser.c
	gcc -c -fPIC langton.c  langton.o
	gcc -c -fPIC visualiser.c -c visualiser.o
	gcc -shared -o libant.so visualiser.o langton.o
clean:
	rm -f  *.o *.so ant

