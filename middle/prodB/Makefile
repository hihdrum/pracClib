.PHONY: all
all : libMiddle.a libMiddle.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD
CFLAGS += -I ../../lowProd02

#--------------------------------------------------
# 静的ライブラリ向け
#--------------------------------------------------
%.o: %.c
	$(CC) $(CFLAGS) -c $<

libMiddle.a: gval.o func01.o func02com.o func03.o func04.o func05.o
	ar rcs $@ $^

#--------------------------------------------------
# 共有ライブラリ向け
#--------------------------------------------------
%_shr.o: %_shr.c
	$(CC) $(CFLAGS) -fPIC -c $<

libMiddle.so: gval_shr.o func01_shr.o func02com_shr.o func03_shr.o func04_shr.o func05_shr.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.a *.so
