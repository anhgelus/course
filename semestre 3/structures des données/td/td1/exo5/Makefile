all: prog.o A.o B.o
	gcc -o prog A.o B.o prog.o

prog.o: prog.c
	gcc -c prog.c

A.o: A.h A.c
	gcc -c A.h A.c

B.o: B.h B.c
	gcc -c B.h B.c

