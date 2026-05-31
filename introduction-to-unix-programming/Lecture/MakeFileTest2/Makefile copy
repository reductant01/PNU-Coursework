CC = gcc
CFLAGS = -Wall

.PHONY: all clean

app: main.o add.o
	$(CC) $(CFLAGS) main.o add.o -o app

main.o: main.c add.h
	$(CC) $(CFLAGS) -c main.c -o main.o

add.o: add.c add.h
	$(CC) $(CFLAGS) -c add.c 

clean:
	rm -rf app *.o

helloTest: abc def
	echo $@
	echo $^
	echo $<
abc:
#	echo abc
def:
#	echo def
