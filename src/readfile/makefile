CC=gcc
LDFLAGS=-lxml2 -I/usr/local/include/libxml

prog: readfile_xml.c
	$(CC) $(LDFLAGS) -o prog readfile_xml.c

clean:
	rm ./prog
