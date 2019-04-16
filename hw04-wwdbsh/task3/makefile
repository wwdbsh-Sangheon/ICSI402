# makefile
prog:	main.o permarray.o
		gcc main.o permarray.o -o all
main.o: main.c
		gcc -c main.c
permarray.o: permarray.c
			 gcc -c permarray.c
test:
		./test_permute_array.sh
clean:
		rm permarray.o main.o all