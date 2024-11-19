CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
BIN = bin

SRC = $(wildcard src/*.c)
SRC_FILTER = $(filter-out src/seminar_main.c, $(SRC))
SRC_TEST = $(wildcard tests/*.c)
SRC_FILTER_TEST = $(filter-out src/seminar_main.c src/home_main.c, $(SRC))


OBJ = $(SRC_FILTER:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)
OBJ_FILTER_TEST = $(SRC_FILTER_TEST:.c=.o)

TARGET = home_program
TARGET_TEST = test_home_program

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(TARGET_TEST) $(OBJ) $(OBJ_TEST) $(OBJ_FILTER_TEST)

install: $(TARGET)
	cp ${TARGET} $(BIN)/

uninstall:
	rm -f $(BIN)/$(TARGET)

test: $(OBJ_TEST) $(OBJ_FILTER_TEST)
	$(CC) $(CFLAGS) -o $(TARGET_TEST) $^