CC=gcc
LDFLAGS=-I/usr/local/include/libxml -lxml2

all:
	make xml
	make csv

xml: readfile_xml.c
	$(CC) $(LDFLAGS) -o readfile_xml readfile_xml.c

csv: readfile_csv.c
	$(CC) -o readfile_csv readfile_csv.c

clean:
	rm ./readfile_csv
	rm ./readfile_xml
