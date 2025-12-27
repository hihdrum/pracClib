.PHONY: all
all : ap01

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I ../inc $<

ap01 : ap01.o
	$(CC) $(CFLAGS) $^ -L ../lib -lCom -o $@

.PHONY: clean
clean:
	rm -f *.o *.d ap01
