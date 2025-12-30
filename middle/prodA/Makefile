TARGETS := middle.a middle.so
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

middle.a: func01.o
	ar rcs $@ $^

middle.so: func01_shr.o
	$(CC) -shared -o $@ $^

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
