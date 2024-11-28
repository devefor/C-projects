CC = gcc

CFLAGS = -Werror -Wall -Wextra -Wpedantic -fsanitize=address -fsanitize=leak -DOUTPUT=1

SRC = a.c b.c c.c d.c
TARGET = a b c d

run_a: $(word 1, $(TARGET))
	./$(word 1, $(TARGET))

run_b: $(word 2, $(TARGET))
	./$(word 2, $(TARGET))

run_c: $(word 3, $(TARGET))
	./$(word 3, $(TARGET))

run_d: $(word 4, $(TARGET))
	./$(word 4, $(TARGET))

$(word 1, $(TARGET)): $(word 1, $(SRC))
	$(CC) $(CFLAGS) $(word 1, $(SRC)) -o $(word 1, $(TARGET))

$(word 2, $(TARGET)): $(word 2, $(SRC))
	$(CC) $(CFLAGS) $(word 2, $(SRC)) -o $(word 2, $(TARGET))

$(word 3, $(TARGET)): $(word 3, $(SRC))
	$(CC) $(CFLAGS) $(word 3, $(SRC)) -o $(word 3, $(TARGET))

$(word 4, $(TARGET)): $(word 4, $(SRC))
	$(CC) $(CFLAGS) $(word 4, $(SRC)) -o $(word 4, $(TARGET))

clean:
	rm -f $(TARGET)
	clear