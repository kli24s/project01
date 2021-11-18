all: project01.o
	gcc -o project01m project01.o

project01.o: project01.c
	gcc -c project01.c

run:
	./project01m

clean:
	rm *.o
	rm project01m