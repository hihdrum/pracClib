.PHONY: all
all : libCom.a

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c $<

libCom.a: func01.o
	ar rcs $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.a

