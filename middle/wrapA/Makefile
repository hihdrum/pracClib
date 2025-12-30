.PHONY: all
all: wrap_func01.o libWrapCom.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD
CFLAGS += -fPIC

%.o: %.c
	$(CC) $(CFLAGS) -c $<

libWrapCom.so : wrap_func01.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.so
