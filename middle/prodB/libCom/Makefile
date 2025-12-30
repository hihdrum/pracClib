.PHONY: all
all : libCom.a libCom.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

# 静的ライブラリ向け
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 共有ライブラリ向け
%_shr.o: %_shr.c
	$(CC) $(CFLAGS) -fPIC -c $<

libCom.a: func01.o
	ar rcs $@ $^

libCom.so: func01_shr.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.a *.so
