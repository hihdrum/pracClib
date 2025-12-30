TARGETS := ap01 ap01_shr ap01_wrap ap01_shr_wrap ap01_shr_wrap_v2

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I ../inc $<

# libCom : 静的リンク
ap01 : ap01.o
	$(CC) $(CFLAGS) $^ ../lib/libCom.a -o $@

# libCom : 動的リンク版
ap01_shr : ap01.o
	$(CC) $(CFLAGS) $^ -L ../lib -lCom -o $@

# libCom : 静的リンク版, ld --wrapによるシンボル置き換え。
#  wrap関数経由でシグネチャの異なるfun01を呼び出している。
ap01_wrap : ap01.o
	$(CC) $(CFLAGS) $^ -Wl,--wrap=func01 ../lib/wrap_func01.o ../../../prodA/build/lib/libCom.a -o $@

# libCom : 動的リンク版, ld --wrapによるシンボル置き換え。
ap01_shr_wrap : ap01.o
	$(CC) $(CFLAGS) $^ -Wl,--wrap=func01 ../lib/wrap_func01.o -L ../../../prodA/build/lib -lCom -o $@

ap01_shr_wrap_v2 : ap01.o
	$(CC) $(CFLAGS) $^ -Wl,--wrap=func01 -L ../lib -lWrapCom -L ../../../prodA/build/lib -lCom -o $@

run_ap01 : ap01
	@./ap01

run_ap01_shr : ap01_shr
	@LD_LIBRARY_PATH=../lib ./ap01_shr

run_ap01_shr_wrap : ap01_shr_wrap
	@LD_LIBRARY_PATH=../../../prodA/build/lib ./ap01_shr_wrap

run_ap01_shr_wrap_v2 : ap01_shr_wrap
	@LD_LIBRARY_PATH=../../../prodA/build/lib:../lib ./ap01_shr_wrap

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
