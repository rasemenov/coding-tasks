### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

include ../rules.mk

LIBS = 

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

test: tests.out
	@./tests.out

memcheck: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(ASANFLAGS) $(CFLAGS) src/*.c $(UNITY_C) test/*.c -o memcheck.out $(LIBS) $(INCLUDE)
	@./memcheck.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/*.c $(UNITY_C) test/*.c -o tests.out $(LIBS) $(INCLUDE)
