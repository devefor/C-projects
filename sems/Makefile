CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include

MAIN = src/seminar_main.c

BIN = bin
OBJ = seminar_main.o

TARGET = sem_program

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ): $(MAIN)
	$(CC) $(CFLAGS) -c $(MAIN) -o $(OBJ)

install: $(TARGET)
	cp $(TARGET) $(BIN)/

uninstall:
	rm -f $(BIN)/$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

all: $(TARGET)