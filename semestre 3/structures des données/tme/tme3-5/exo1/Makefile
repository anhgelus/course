all: main.o biblioLC.o entreeSortieLC.o
	gcc -o main main.o biblioLC.o entreeSortieLC.o

main.o: main.c
	gcc -c main.c

biblioLC.o: biblioLC.c biblioLC.h
	gcc -c biblioLC.c biblioLC.h

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
	gcc -c entreeSortieLC.c entreeSortieLC.h

clean:
	rm *.o
	rm *.gch
