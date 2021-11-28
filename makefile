all: main.o read.o pipes.o redirection.o
	gcc -o project01 main.o read.o pipes.o redirection.o

main.o: main.c read.h
	gcc -c main.c

read.o: read.c read.h pipes.h redirection.h
	gcc -c read.c

pipes.o: pipes.c pipes.h
	gcc -c pipes.c

redirect.o: redirect.c redirect.h
	gcc -c redirect.c 

run:
	./project01

clean:
	rm *.o
	rm project01