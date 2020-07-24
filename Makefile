#Makefile
all: nbo

nbo: nbo.o main.o
	gcc -o nbo nbo.o main.o

main.o: nbo.h main.cpp
	gcc -c -o main.o main.cpp

nbo.o: nbo.h nbo.cpp
	gcc -c -o nbo.o nbo.cpp

clean:
	rm -f nbo
	rm -f *.o
