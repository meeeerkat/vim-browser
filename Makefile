CC = g++
LD = g++

# -O0 option to activate optimisations
CFLAGS = -Wall -Wextra -O0 -iquote include -iquote include-prefixes `pkg-config --cflags glib-2.0` `pkg-config --cflags gumbo`
LDFLAGS = -lcurl -lncurses -lpthread -Llibvim -lvim `pkg-config --libs glib-2.0` `pkg-config --libs gumbo` -lyaml-cpp

SRC_FILES := $(shell find src -regextype sed -regex ".*\.cpp" -type f)
OBJ_FILES=$(patsubst src/%.cpp,obj/%.o,$(SRC_FILES))

LIB_DIR=libvim
LIB_FILE=$(LIB_DIR)/libvim.a

all: main

main: $(LIB_FILE) $(OBJ_FILES)
	$(LD) $(OBJ_FILES) $(LDFLAGS) -o $@

$(LIB_FILE):
	cd $(LIB_DIR); make

$(OBJ_FILES): obj/%.o : src/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@




.PHONY: clean
clean:
	rm -rf main $(OBJ_FILES)
	cd $(LIB_DIR); make clean
