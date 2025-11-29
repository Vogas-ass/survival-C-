CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = src/main.c src/utils.c src/array_inventory.c src/list_inventory.c src/components.c src/sorts.c
OBJ = $(SRC:.c=.o)

all: survival

survival: $(OBJ)
	$(CC) $(CFLAGS) -o survival $(OBJ)

clean:
	rm -f $(OBJ) survival
