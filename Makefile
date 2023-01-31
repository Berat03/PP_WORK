CC = gcc

all: main.c library
	$(CC) main.c -L. -lant -lncursesw -Wl,-rpath=. -o ant
	./ant LRRL
# if I changed the last line of all: to  './ant $(variant)', user can input rules doing 'make all variant="LRLRRL"'
# I removed this feature as according to the FAQ questions we need to run a pre-picked variant of the game
library: langton.c visualiser.c
	$(CC) -c -fPIC langton.c -o langton.o
	$(CC) -c -fPIC visualiser.c -o visualiser.o
	$(CC) -shared -o libant.so visualiser.o langton.o
clean:
	rm -f  *.o *.so ant

