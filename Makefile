CC = gcc
#need to implement this

# unclear instructions, am I meant to have makefile actually run or only create the executable, and does the makefile take rule?
all: main.c library
	$(CC) main.c -L. -lant -lncursesw -Wl,-rpath=. -o ant

library: langton.c visualiser.c
	$(CC) -c -fPIC langton.c -o langton.o
	$(CC) -c -fPIC visualiser.c -o visualiser.o
	$(CC) -shared -o libant.so visualiser.o langton.o
clean:
	rm -f  *.o *.so ant

