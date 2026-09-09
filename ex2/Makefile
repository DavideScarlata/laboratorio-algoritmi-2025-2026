SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
BIN_DIR = bin
DOC_DIR = doc
INCLUDE_DIR = include

CC = gcc

CFLAGS = -O3 -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = -I$(INCLUDE_DIR)

.PHONY: all clean doc test

COMMON_SRC = hash_table.c
MAIN_SRC   = main_ex2.c
TEST_SRC   = test_ex2.c

COMMON_OBJ = $(COMMON_SRC:%.c=$(BUILD_DIR)/%.o)
MAIN_OBJ   = $(MAIN_SRC:%.c=$(BUILD_DIR)/%.o)
TEST_OBJ   = $(TEST_SRC:%.c=$(BUILD_DIR)/%.o)

MAIN_EXEC = $(BIN_DIR)/main_ex2
TEST_EXEC = $(BIN_DIR)/test_ex2

all: $(MAIN_EXEC) $(TEST_EXEC)

$(MAIN_EXEC): $(MAIN_OBJ) $(COMMON_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Costruito eseguibile principale: $@"

$(TEST_EXEC): $(TEST_OBJ) $(COMMON_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Costruito eseguibile di test: $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(DOC_DIR) Doxyfile
	@echo "Clean completed."

test: $(TEST_EXEC)
	./$(TEST_EXEC)