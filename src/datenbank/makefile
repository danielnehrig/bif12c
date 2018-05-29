CC=gcc
LDFLAGS=-I /usr/local/mysql/include/mysql/ -L /usr/local/mysql/lib/ -lmysqlclient

prog: datenbank.c
	$(CC) $(LDFLAGS) -o prog datenbank.c
