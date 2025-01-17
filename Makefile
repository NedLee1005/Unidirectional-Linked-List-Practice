CC := gcc
CFLAGS :=-Wno-all -g -O0 -MMD

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

-include $(DEPS)

all: $(filter-out main.o, $(OBJS))

test: test_list
	./test_list

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

test_list: $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) test_list *.o *.d
