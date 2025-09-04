CC := gcc
CFLAGS :=-Wno-all -g -O0 -MMD

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

-include $(DEPS)

all: $(filter-out main.o, $(OBJS))

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJS) 
	$(CC) $(CFLAGS) $^ -o ts
	./ts	

clean:
	$(RM) test *.o *.d
