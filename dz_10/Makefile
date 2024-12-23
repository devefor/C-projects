CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -lcmocka -Wl,--wrap=read_lines

BIN_DIR = bin
SRC_DIR = src
INC_DIR = include

TARGET = sentence_counter
TARGET_TEST = sentence_counter_test

SRC_FILES = $(SRC_DIR)/sentence_counter.c $(SRC_DIR)/read_lines.c $(SRC_DIR)/main.c
TEST_FILES = $(SRC_DIR)/sentence_counter.c $(SRC_DIR)/sentence_counter_test.c

OBJ = $(SRC_FILES:$(SRC_DIR).c=$(BIN_DIR).o)
OBJ_TEST = $(TEST_FILES:$(SRC_DIR).c=$(BIN_DIR).o)

build: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

build_test: $(BIN_DIR)/$(TARGET_TEST)

$(BIN_DIR)/$(TARGET_TEST): $(OBJ_TEST) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: build_test
	./$(BIN_DIR)/$(TARGET_TEST)

clean:
	rm -rf $(BIN_DIR) $(TARGET) $(TARGET_TEST)