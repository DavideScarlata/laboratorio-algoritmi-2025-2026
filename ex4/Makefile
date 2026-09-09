SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

CC = gcc
CFLAGS = -O3 -g -Wall -Wextra -Wpedantic -Wconversion -std=c11
INCLUDES = -I$(INCLUDE_DIR)

LIB_SRC = \
    $(SRC_DIR)/hash_table.c \
    $(SRC_DIR)/graph.c \
    $(SRC_DIR)/bfs.c

LIB_OBJ = \
    $(BUILD_DIR)/hash_table.o \
    $(BUILD_DIR)/graph.o \
    $(BUILD_DIR)/bfs.o

MAIN_SRC = $(SRC_DIR)/main.c
MAIN_OBJ = $(BUILD_DIR)/main.o

TEST_SRC = $(TEST_DIR)/test_ex4.c
TEST_OBJ = $(BUILD_DIR)/test_ex4.o

MAIN_EXEC = $(BIN_DIR)/main_ex4
TEST_EXEC = $(BIN_DIR)/test_ex4

.PHONY: all clean test

all: $(MAIN_EXEC) $(TEST_EXEC)

$(MAIN_EXEC): $(LIB_OBJ) $(MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Built $@"

$(TEST_EXEC): $(LIB_OBJ) $(TEST_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Built $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/test_ex4.o: $(TEST_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	rm -f *.txt
	@echo "Clean completed."

test: $(TEST_EXEC)
	./$(TEST_EXEC)