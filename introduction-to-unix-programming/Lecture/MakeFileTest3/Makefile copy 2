CC = gcc
CFLAGS = -Wall -I include -MMD # Generate dependency files / include header file in dependency files

SRC = src/main.c src/add.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

app: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

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
