CC = gcc
CFLAGS = -Wall -fPIC -shared -Iinclude

all: dist/sqlite_h3.so

dist/sqlite_h3.so: src/sqlite_h3.o h3lib/libh3.a
	$(CC) $(CFLAGS) -o $@ $^


# implicit rule something akin too:
# %.o: %.c
# 	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<