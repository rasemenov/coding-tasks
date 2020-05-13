CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64
test: CFLAGS += -DTEST

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

.PHONY: test
test: tests.out
	@./tests.out

.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/*.c *.c *.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) *.c test/vendor/unity.c test/*.c -o tests.out $(LIBS)

all: *.c *.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) *c -o solution $(LIBS)
