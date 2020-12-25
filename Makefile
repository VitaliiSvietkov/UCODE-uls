.PHONY: all uls uninstall clean reinstall

SRCS := $(wildcard src/*.c src/sorting/*.c)
HDRS := $(wildcard inc/*.h)

CCFLAGS = -Wall -Wextra -Werror -Wpedantic

all: uls

uls:
	@$(MAKE) -C libmx/
	@clang ${CCFLAGS} ${SRCS} ${HDRS} libmx/libmx.a
	@mv a.out uls

uninstall: clean
	@$(MAKE) -C libmx/ uninstall
	@rm -rdf uls

clean:
	@$(MAKE) -C libmx/ clean
	@rm -rdf inc/*.gch

reinstall: uninstall uls
