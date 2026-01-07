.PHONY: all
all: libProdBBridge.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD
CFLAGS += -fPIC

%.o: %.c
	$(CC) $(CFLAGS) -c $<

libProdBBridge.so : func01_bridge.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.so
