CC=gcc
CFLAGS=-g -Wall -Werror -Wpedantic -fsanitize=address -std=c11 -Iinclude
LIBS=-fsanitize=address
TARGET=epsilon

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
_DEPS = main.h add.h struct.h print_list.h get_list.h done_task.h clear.h remove.h helper.h
_OBJS = main.o add.o print_list.o get_list.o done_task.o clear.o remove.o helper.o
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
