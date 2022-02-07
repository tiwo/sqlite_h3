H3_LIBRARYVERSION = v3.7.2
H3_LIBRARYVERSION = HEAD

all: libh3.a h3api.h

h3api.h: build/h3/src/h3lib/include/h3api.h
	cp -a $< $@

libh3.a: build/h3/lib/libh3.a
	cp -a $< $@

build/h3/lib/libh3.a: build h3
	( cd build && cmake -Wno-dev .. )
	$(MAKE) -C build

build:
	mkdir -p $@

h3: correct-directory
    
	test -d h3 || git clone --no-checkout https://github.com/uber/h3.git h3
	@test -d h3/.git
	@( cd h3 && git config --local advice.detachedHead false )
	( cd h3 && git checkout $(H3_LIBRARYVERSION) )
.PHONY: h3


clean: correct-directory
	rm -rf h3 build

fullclean: clean correct-directory
	rm -f libh3.a h3api.h


correct-directory:
	@grep -q "e040b192-ad6d-458f-80b5-1fcea717db6a is only found in sqlite_h3/h3lib" Makefile
.PHONY: correct-directory