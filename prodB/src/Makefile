TARGETS := ap01 ap01_shr ap01_sd ap01_ds

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I ../inc $<

#------------------------------------------------------------------
# 静的リンク
ap01 : ap01.o
	$(CC) $(CFLAGS) $^ ../lib/libMiddle.a ../lib/libLowProd02.a -o $@

# 動的リンク版
ap01_shr : ap01.o
	$(CC) $(CFLAGS) $^ -L ../lib -lMiddle -lLowProd02 -o $@

# 混在リンク版
#  libLowProd01 : static
#  libMiddle    : dynamic
ap01_sd : ap01.o
	$(CC) $(CFLAGS) $^ -L ../lib -lMiddle ../lib/libLowProd02.a -o $@

# 混在リンク版
#  libLowProd01 : dynamic
#  libMiddle    : static
ap01_ds : ap01.o
	$(CC) $(CFLAGS) $^ ../lib/libMiddle.a -L ../lib -lLowProd02 -o $@

# ここから編集中

ap01_try : ap01.o
	$(CC) $(CFLAGS) $^ \
	-L ../../middle/prodBBridge -lProdBBridge \
	-L ../../middle/prodB -lMiddle \
	-L ../../lowProd02 -lLowProd02 \
	-o $@

run_ap01_try : ap01_try
	LD_LIBRARY_PATH=../../lowProd01:../../middle/prodBBridge:../../middle/prodA:../../middle/prodB:../../lowProd02 ./ap01_try








#ap01_wrap : ap01.o
#	$(CC) $(CFLAGS) $^ -Wl,--wrap=func01 ../lib/wrap_func01.o ../../../prodA/build/lib/libCom.a -o $@

# libCom : 動的リンク版, ld --wrapによるシンボル置き換え。
ap01_shr_wrap : ap01.o
	$(CC) $(CFLAGS) $^ -Wl,--wrap=func01 ../lib/wrap_func01.o -L ../../../prodA/build/lib -lCom -o $@

ap01_shr_wrap_v2 : ap01.o
	$(CC) $(CFLAGS) $^ -Wl,--wrap=func01 -L ../lib -lWrapCom -L ../../../prodA/build/lib -lCom -o $@

#------------------------------------------------------------------
run_ap01 : ap01
	@./ap01

run_ap01_shr : ap01_shr
	@LD_LIBRARY_PATH=../lib ./ap01_shr

run_ap01_sd : ap01_sd
	@LD_LIBRARY_PATH=../lib ./ap01_sd

run_ap01_ds : ap01_ds
	@LD_LIBRARY_PATH=../lib ./ap01_ds

run_ap01_shr_wrap : ap01_shr_wrap
	@LD_LIBRARY_PATH=../../../prodA/build/lib ./ap01_shr_wrap


run_ap01_shr_wrap_v2 : ap01_shr_wrap
	@LD_LIBRARY_PATH=../../../prodA/build/lib:../lib ./ap01_shr_wrap

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
