all: run-tests

run-tests: ../dist/sqlite_h3.so pytest-installed
	. testenv/bin/activate && pytest

.PHONY: run-tests

pytest-installed: testenv
	. testenv/bin/activate && pip install -r requirements.txt
	touch $@


testenv:
	python3 -mvenv --prompt "h2-test" testenv
	. testenv/bin/activate && pip install -U pip