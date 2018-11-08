all: signals.o
	gcc signals.o
signals.o:
	gcc -c signals.c
run:
	./a.out