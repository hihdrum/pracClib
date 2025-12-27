.PHONY: all
all: wrap_func01.o

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c $<

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d
