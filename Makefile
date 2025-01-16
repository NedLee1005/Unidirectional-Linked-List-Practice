CC := gcc
CFLAGS :=-Wno-all -g -Og -MMD

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

-include $(DEPS)

all: list.o

test: test_list
	./test_list

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

test_list: $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) test_list *.o *.d
