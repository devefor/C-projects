CC = gcc
CFLAGS = -Werror -Wall -Wextra -Wpedantic -fsanitize=address -fsanitize=leak -DOUTPUT=1

SRC = a.c
EXECUTE = a

run: $(EXECUTE)
	./$(EXECUTE)

$(EXECUTE) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXECUTE)

clean:
	rm -f $(EXECUTE)
	clear