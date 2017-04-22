CC=gcc
OPT=-g

text.o: text.h text.c
	$(CC) text.h text.c -c

text: text.o
	$(CC) $(OPT) text.o -o text

clean:
	rm *.o text *.h.gch