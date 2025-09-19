all: question2.o question1.o
	gcc -ggdb -o main question1.o question2.o

question2.o: question2.c
	gcc -c question2.c

question1.o: question1.c question1.h
	gcc -c question1.h question1.c

clean:
	rm *.o
	rm *.gch
