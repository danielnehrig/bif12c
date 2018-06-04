CC =gcc
OBJ =tictactoe.o validation.o logic.o
C =tictactoe.c validation.c logic.c
DEPS = func.h

%.o: %.c $(DEPS)
	$(CC) --std=c99 -Wall -c -o $@ $<

prog: $(OBJ)
	$(CC) --std=c99 -Wall -g -o tictactoe $(OBJ)

test:
	./test.sh

clean:
	rm *.o
	rm tictactoe
	rm -rf ./tictactoe.dYSM/
