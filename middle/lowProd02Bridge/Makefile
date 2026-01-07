TARGETS := libLowProd02.a libLowProd02.so

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

CFLAGS += -I ../../lowProd01

# 静的ライブラリ向け
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 共有ライブラリ向け
%_shr.o: %_shr.c
	$(CC) $(CFLAGS) -fPIC -c $<

libLowProd02.a: func01.o
	ar rcs $@ $^

libLowProd02.so: func01_shr.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
