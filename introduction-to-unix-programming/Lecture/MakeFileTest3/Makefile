CC = gcc
CFLAGS = -Wall -I include -MMD # Generate dependency files / include header file in dependency files

SRC = src/main.c src/add.c
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d) # SRC:.o=.d 도 같은 역할

TARGET = app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c	
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -f $(TARGET) $(OBJ) $(DEP)

.PHONY: all clean
