H3_LIBRARYVERSION = 3.7.2

all: static/libh3.a

static/libh3.a: h3source
	true

foo: correct-directory
	( cd build && )

h3source: correct-directory
    
	test -d h3source || git clone --no-checkout https://github.com/uber/h3.git h3source
	@( cd h3source && git config --local advice.detachedHead false )
	( cd h3source && git checkout v$(H3_LIBRARYVERSION) )

correct-directory:
	@grep -q "e040b192-ad6d-458f-80b5-1fcea717db6a" Makefile

.PHONY: correct-directory



clean: correct-directory
	rm -rf h3source build/*