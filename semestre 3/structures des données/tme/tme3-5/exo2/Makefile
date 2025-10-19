all: main.o biblioH.o entreeSortieH.o
	gcc -o main main.o biblioH.o entreeSortieH.o -lm

main.o: main.c
	gcc -c main.c -lm

biblioH.o: biblioH.c biblioH.h
	gcc -c biblioH.c biblioH.h -lm

entreeSortieH.o: entreeSortieH.c entreeSortieH.h
	gcc -c entreeSortieH.c entreeSortieH.h -lm

clean:
	rm *.o
	rm *.gch
