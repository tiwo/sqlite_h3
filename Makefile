CC = gcc
CFLAGS = -Wall -fPIC -shared -Iinclude

all: dist/sqlite_h3.so

dist/sqlite_h3.so: src/sqlite_h3.o h3lib/libh3.a
	$(CC) $(CFLAGS) -o $@ $^

# implicit rule something akin too:
# %.o: %.c
# 	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean: correct-directory
	rm -f src/*.o

correct-directory:
	@grep -q "238c00f0-aa08-4eef-bf3d-ecc104b21788 is only found in sqlite_h3's project root" Makefile
.PHONY: correct-directory