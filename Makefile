# Output
OUTPUT := libsortql.so

CC := gcc
CFLAGS := -std=c89 -Wall -Wextra -Wpedantic

ifdef DEBUG
	CFLAGS += -Werror -fsanitize=address -fsanitize=undefined
endif

all: build

build:
	$(CC) $(CFLAGS) -shared -fPIC -o $(OUTPUT) sortql.c -lsqlite3

test:
	$(CC) $(CFLAGS) test.c $(OUTPUT)
	LD_LIBRARY_PATH=. ./a.out

.PHONY: clean
clean:
	rm -f a.out $(OUTPUT)
