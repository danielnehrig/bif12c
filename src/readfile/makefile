CC=gcc
LDFLAGS=-I /usr/local/include -L /usr/local/lib/

prog: readfile_xml.c
	$(CC) $(LDFLAGS) -o prog readfile_xml.c

clean:
	rm ./prog
