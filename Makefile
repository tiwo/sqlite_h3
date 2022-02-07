CC = gcc
CFLAGS = -Wall -fPIC -shared -Iinclude

all: dist/sqlite_h3.so

dist/sqlite_h3.so: src/sqlite_h3.o h3lib/libh3.a
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c prerequisites
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

prerequisites: h3lib/h3api.h h3lib/libh3.a
h3lib/h3api.h:
	$(MAKE) -C h3lib
h3lib/libh3.a:
	$(MAKE) -C h3lib

clean: correct-directory
	rm -f src/*.o

fullclean: clean correct-directory
	rm -f dist/sqlite_h3.so
	$(MAKE) -C h3lib fullclean

tests: dist/sqlite_h3.so
	$(MAKE) -C $@
.PHONY: tests

correct-directory:
	@grep -q "238c00f0-aa08-4eef-bf3d-ecc104b21788 is only found in sqlite_h3's project root" Makefile
.PHONY: correct-directory