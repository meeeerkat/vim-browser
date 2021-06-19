CC = gcc
LD = gcc

# -O0 option to activate optimisations
CFLAGS = -Wall -Wextra -O0 -Iinclude
LDFLAGS = -lcurl -llexbor -lncurses -lpthread

SRC_FILES := $(shell find src -regextype sed -regex ".*\.c" -type f)

OBJ_FILES=$(patsubst src/%.c,obj/%.o,$(SRC_FILES))

all: main

main: $(OBJ_FILES)
	$(LD) $(OBJ_FILES) $(LDFLAGS) -o $@

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf main $(OBJ_FILES)
