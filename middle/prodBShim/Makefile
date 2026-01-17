.PHONY: all
all : libMiddle.so

CFLAGS += -Wall
CFLAGS += -g3
CFLAGS += -MMD

# 静的ライブラリ向け
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 共有ライブラリ向け
%_shr.o: %_shr.c
	$(CC) $(CFLAGS) -fPIC -c $<

libMiddle.so: func01_shr.o
	$(CC) -shared -o $@ $^ -ldl

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.a *.so
