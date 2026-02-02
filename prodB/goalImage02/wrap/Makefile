#-----------------------------------------
# ProdA中間ライブラリのfunc01をラップし、
# ProdB中間ライブラリのfunc01から呼出す。
#-----------------------------------------
.PHONY: all
all : libMiddleWrap.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $<

#libMiddleWrap.so: func01_shr.o func04_shr.o func05_shr.o
libMiddleWrap.so: func01_shr.o func05_shr.o
	$(CC) -shared -o $@ $^ -ldl

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.so
