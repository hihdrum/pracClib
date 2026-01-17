TARGETS := libMiddle.a libMiddle.so

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD
CFLAGS += -I ../../lowProd01

#--------------------------------------------------
# 静的ライブラリ向け
#--------------------------------------------------
%.o: %.c
	$(CC) $(CFLAGS) -c $<

libMiddle.a: gval.o func01.o func02com.o
	ar rcs $@ $^

#--------------------------------------------------
# 共有ライブラリ向け
#--------------------------------------------------
%_shr.o: %_shr.c
	$(CC) $(CFLAGS) -fPIC -c $<

libMiddle.so: func01_shr.o func02com_shr.o
	$(CC) -shared -o $@ $^


-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
