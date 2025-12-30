.PHONY: all
all : libMiddle.a libMiddle.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD
CFLAGS += -I ../../lowProd02

# 静的ライブラリ向け
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 共有ライブラリ向け
%_shr.o: %_shr.c
	$(CC) $(CFLAGS) -fPIC -c $<

libMiddle.a: func01.o
	ar rcs $@ $^

libMiddle.so: func01_shr.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.a *.so
