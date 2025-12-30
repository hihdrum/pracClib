TARGETS := libLowProd02.a libLowProd02.so

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

# 静的ライブラリ向け
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 共有ライブラリ向け
%_shr.o: %_shr.c
	$(CC) $(CFLAGS) -fPIC -c $<

libLowProd02.a: lfunc01.o
	ar rcs $@ $^

libLowProd02.so: lfunc01_shr.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
