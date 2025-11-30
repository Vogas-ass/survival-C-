CC = gcc
CFLAGS = -Wall -Wextra -g
INCDIR = include
SRCDIR = src
OBJ = src/main.o src/array_inventory.o src/list_inventory.o src/utils.o src/components.o src/sorts.o
EXE = survival

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)
