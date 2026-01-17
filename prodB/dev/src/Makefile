TARGETS := ap01 ap01_shr ap01_sd ap01_ds

LIB_INC := ../ext/inc
LIB_PATH := ../ext/lib

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(LIB_INC) $<

#------------------------------------------------------------------
# 環境整備
#------------------------------------------------------------------
# 下層
LOW_DIR := ../../../lowProd02
LOW_LIBS := $(LIB_PATH)/libLowProd02.a $(LIB_PATH)/libLowProd02.so
LOW_HEADER := $(LIB_INC)/lowProd02.h

# 中間層
MID_DIR := ../../../middle/prodB
MID_LIBS := $(LIB_PATH)/libMiddle.a $(LIB_PATH)/libMiddle.so
MID_HEADER := $(LIB_INC)/middle.h

.PHONY : preLib
preLib : $(LOW_LIBS) $(LOW_HEADER) $(MID_LIBS) $(MID_HEADER)

$(LOW_LIBS) : $(LIB_PATH)/% : $(LOW_DIR)/%
	cp $< $@

$(LOW_HEADER) : $(LOW_DIR)/lowProd02.h
	cp $< $@

$(LOW_DIR)/lowProd01.h $(LOW_DIR)/libLowProd01.a $(LOW_DIR)/libLowProd01.so :
	make -C $(LOW_DIR)

#---

$(MID_LIBS) : $(LIB_PATH)/% : $(MID_DIR)/%
	cp $< $@

$(MID_HEADER) : $(MID_DIR)/middle.h
	cp $< $@

$(MID_DIR)/libMiddle.a $(MID_DIR)/libMiddle.so :
	make -C $(LOW_DIR)

#------------------------------------------------------------------
# 静的リンク
ap01 : ap01.o
	$(CC) $(CFLAGS) $^ $(LIB_PATH)/libMiddle.a $(LIB_PATH)/libLowProd02.a -o $@

# 動的リンク版
ap01_shr : ap01.o
	$(CC) $(CFLAGS) $^ -L $(LIB_PATH) -lMiddle -lLowProd02 -o $@

# 混在リンク版
#  libLowProd01 : static
#  libMiddle    : dynamic
ap01_sd : ap01.o
	$(CC) $(CFLAGS) $^ -L $(LIB_PATH) -lMiddle $(LIB_PATH)/libLowProd02.a -o $@

# 混在リンク版
#  libLowProd01 : dynamic
#  libMiddle    : static
ap01_ds : ap01.o
	$(CC) $(CFLAGS) $^ $(LIB_PATH)/libMiddle.a -L $(LIB_PATH) -lLowProd02 -o $@

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
	rm -f ../ext/inc/*
	rm -f ../ext/lib/*
