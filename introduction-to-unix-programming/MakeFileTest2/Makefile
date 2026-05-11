SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

echo: $(SRC)
	@echo $^
	@echo $<
	@echo $@
	@echo $(OBJ)
	@echo $(patsubst %.c, %.o, $(SRC))