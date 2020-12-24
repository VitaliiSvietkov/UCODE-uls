.PHONY: all uls uninstall clean reinstall

SRCS := $(wildcard src/*.c)
HDRS := $(wildcard inc/*.h)

all: uls

uls:
	@make -C libmx/
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic ${SRCS} ${HDRS} libmx.a
	@mv a.out uls

uninstall: clean
	@make -C libmx/ uninstall

clean:
	@make -C libmx/ clean
	@rm -rdf uls

reinstall: uninstall uls
