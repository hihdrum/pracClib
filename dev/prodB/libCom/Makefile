.PHONY: all
all : libCom.a libCom.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c $<

libCom.a: func01.o
	ar rcs $@ $^

libCom.so: func01.c
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.a *.so
