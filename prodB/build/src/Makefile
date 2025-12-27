.PHONY: all
all : ap01 ap01_shr ap01_wrap

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I ../inc $<

ap01 : ap01.o
	$(CC) $(CFLAGS) $^ ../lib/libCom.a -o $@

ap01_shr : ap01.o
	$(CC) $(CFLAGS) $^ -L ../lib -lCom -o $@

ap01_wrap : ap01.o
	$(CC) $(CFLAGS) $^ -Wl,--wrap=func01 ../lib/wrap_func01.o ../../../prodA/build/lib/libCom.a -o $@

run_ap01 : ap01
	@./ap01

run_ap01_shr : ap01_shr
	@LD_LIBRARY_PATH=../lib ./ap01_shr

.PHONY: clean
clean:
	rm -f *.o *.d ap01 ap01_shr ap01_wrap
