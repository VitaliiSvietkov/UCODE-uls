.PHONY: all uls uninstall clean reinstall

SRCS := $(wildcard src/*.c src/sorting/*.c src/utils/*.c src/printing/*.c)
HDRS := $(wildcard inc/*.h)

CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: uls

uls:
	@$(MAKE) -C libmx/
	@clang -c ${CCFLAGS} ${SRCS} ${HDRS}
	@mkdir obj
	@mv *.o obj
	@clang obj/*.o libmx/libmx.a
	@mv a.out uls

uninstall: clean
	@$(MAKE) -C libmx/ uninstall
	@rm -rdf uls

clean:
	@$(MAKE) -C libmx/ clean
	@rm -rdf inc/*.gch
	@rm -rdf obj

reinstall: uninstall uls
