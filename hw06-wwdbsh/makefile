
all: filegrep.o lsal.o lsal2.o
	gcc filegrep.o -o filegrep
	gcc lsal.o -o lsal
	gcc lsal2.o -o lsal2

filegrep.o: filegrep.c
	gcc -c filegrep.c

filegrep: filegrep.o
	gcc filegrep.o -o filegrep

lsal.o: lsal.c
	gcc -c lsal.c

lsal: lsal.o 
	gcc lsal.o -o lsal

lsal2.o: lsal2.c
	gcc -c lsal2.c

lsal2: lsal2.o
	gcc lsal2.o -o lsal2

clean:
	rm filegrep.o filegrep lsal.o lsal lsal2.o lsal2