include ../../rules.mk

LIBS = -lm

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

.PHONY: test
test: tests.out
	@./tests.out

.PHONY: memcheck
memcheck: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(ASANFLAGS) $(CFLAGS) src/*.c $(UNITY_C) test/*.c -o memcheck.out $(LIBS) $(INCLUDE)
	@./memcheck.out
	@echo "Memory check passed"

.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@echo $(UNITY_DIR)
	@$(CC) $(CFLAGS) src/*.c $(UNITY_C) test/*.c -o tests.out $(LIBS) $(INCLUDE)
