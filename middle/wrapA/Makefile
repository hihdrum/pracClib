.PHONY: all
all: wrap_func01.o libWrapCom.so

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD
CFLAGS += -fPIC

%.o: %.c
	$(CC) $(CFLAGS) -c $<

libWrapCom.so : wrap_func01.o
	$(CC) -shared -o $@ $^

#func01_wrap.so : func01_wrap.c
#	$(CC) -shared -fPIC -o func01_wrap.so $< -ldl

func01_wrap.so : func01_wrap.c
	$(CC) -shared -fPIC -o func01_wrap.so $< -L ../../prodA/lib -Wl,--no-as-needed -lMiddle -lLowProd01 -Wl,--as-needed

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.so
