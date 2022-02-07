H3_LIBRARYVERSION = v3.7.2
H3_LIBRARYVERSION = HEAD

all: static/libh3.a

static/libh3.a: build/h3/lib/libh3.a
	cp -a $< $@

build/h3/lib/libh3.a: h3
	( cd build && cmake -Wno-dev .. )
	( cd build && make )

h3: correct-directory
    
	test -d h3 || git clone --no-checkout https://github.com/uber/h3.git h3
	@( cd h3 && git config --local advice.detachedHead false )
	( cd h3 && git checkout $(H3_LIBRARYVERSION) )


clean: correct-directory
	rm -rf h3 build/*

correct-directory:
	@grep -q "e040b192-ad6d-458f-80b5-1fcea717db6a" Makefile
.PHONY: correct-directory