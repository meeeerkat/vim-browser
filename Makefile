CC = g++
LD = g++

# -O0 option to activate optimisations
CFLAGS = -Wall -Wextra -O0 -Iinclude `pkg-config --cflags glib-2.0` `pkg-config --cflags gumbo`
LDFLAGS = -lcurl -lncurses -lpthread `pkg-config --libs glib-2.0` `pkg-config --libs gumbo` -lyaml-cpp

SRC_FILES := $(shell find src -regextype sed -regex ".*\.cpp" -type f)

OBJ_FILES=$(patsubst src/%.cpp,obj/%.o,$(SRC_FILES))

all: main

main: $(OBJ_FILES)
	$(LD) $(OBJ_FILES) $(LDFLAGS) -o $@

obj/%.o: src/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf main $(OBJ_FILES)
