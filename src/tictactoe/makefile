CC =gcc
OBJ =tictactoe.o validation.o logic.o
C =tictactoe.c validation.c logic.c
DEPS = func.h

%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $<

prog: $(OBJ)
	$(CC) -Wall -g -o prog $(OBJ)

clean:
	rm *.o
