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
	$(SRC_DIR)/priority_queue.c \
	$(SRC_DIR)/task.c \
	$(SRC_DIR)/csv.c

LIB_OBJ = \
	$(BUILD_DIR)/hash_table.o \
	$(BUILD_DIR)/priority_queue.o \
	$(BUILD_DIR)/task.o \
	$(BUILD_DIR)/csv.o

MAIN_SRC = $(SRC_DIR)/main.c
MAIN_OBJ = $(BUILD_DIR)/main.o

TEST_SRC = $(TEST_DIR)/test_ex3.c
TEST_OBJ = $(BUILD_DIR)/test_ex3.o

MAIN_EXEC = $(BIN_DIR)/main_ex3
TEST_EXEC = $(BIN_DIR)/test_ex3

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

$(BUILD_DIR)/test_ex3.o: $(TEST_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Clean completed."
	rm -f *.txt
test: $(TEST_EXEC)
	./$(TEST_EXEC)
