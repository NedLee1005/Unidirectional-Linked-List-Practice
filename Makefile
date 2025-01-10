CC := gcc
CFLAGS := -Wall -g -Og

all: list.o

test: test_list
	./test_list

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $< -o $@

test_list: main.c list.c list.h
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) test_list list.o
