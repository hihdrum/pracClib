TARGETS := ap01 ap01_shr ap01_sd ap01_ds

# 製品A,Bの環境整備は似通っているので上手く共通化できるかもしれない。
#------------------------------------------------------------------
# 環境整備
#------------------------------------------------------------------
# 製品A
#------------------------------------
LIB_INC_A := ../ext/incA
LIB_PATH_A := ../ext/libA

LOW_DIR_A := ../../../lowProd01
LOW_LIBS_A := $(LIB_PATH_A)/libLowProd01.so
LOW_HEADER_A := $(LIB_INC_A)/lowProd01.h

MID_DIR_A := ../../../middle/prodA
MID_LIBS_A := $(LIB_PATH_A)/libMiddle.so
MID_HEADER_A := $(LIB_INC_A)/middle.h

.PHONY : preLibA
preLibA : $(LOW_LIBS_A) $(LOW_HEADER_A) $(MID_LIBS_A) $(MID_HEADER_A)

$(LOW_LIBS_A) : $(LIB_PATH_A)/% : $(LOW_DIR_A)/%
	cp $< $@

$(LOW_HEADER_A) : $(LOW_DIR_A)/lowProd01.h
	cp $< $@

$(LOW_DIR_A)/lowProd01.h $(LOW_DIR_A)/libLowProd01.so :
	make -C $(LOW_DIR_A)

$(MID_LIBS_A) : $(LIB_PATH_A)/% : $(MID_DIR_A)/%
	cp $< $@

$(MID_HEADER_A) : $(MID_DIR_A)/middle.h
	cp $< $@

$(MID_DIR_A)/libMiddle.so :
	make -C $(MID_DIR_A)

#------------------------------------
# 製品B
#------------------------------------
LIB_INC_B := ../ext/incB
LIB_PATH_B := ../ext/libB

LOW_DIR_B := ../../../lowProd02
LOW_LIBS_B := $(LIB_PATH_B)/libLowProd02.so
LOW_HEADER_B := $(LIB_INC_B)/lowProd02.h

MID_DIR_B := ../../../middle/prodB
MID_LIBS_B := $(LIB_PATH_B)/libMiddle.so
MID_HEADER_B := $(LIB_INC_B)/middle.h

.PHONY : preLibB
preLibB : $(LOW_LIBS_B) $(LOW_HEADER_B) $(MID_LIBS_B) $(MID_HEADER_B)

$(LOW_LIBS_B) : $(LIB_PATH_B)/% : $(LOW_DIR_B)/%
	cp $< $@

$(LOW_HEADER_B) : $(LOW_DIR_B)/lowProd02.h
	cp $< $@

$(LOW_DIR_B)/lowProd01.h $(LOW_DIR_B)/libLowProd01.so :
	make -C $(LOW_DIR_B)

$(MID_LIBS_B) : $(LIB_PATH_B)/% : $(MID_DIR_B)/%
	cp $< $@

$(MID_HEADER_B) : $(MID_DIR_B)/middle.h
	cp $< $@

$(MID_DIR_B)/libMiddle.a $(MID_DIR_B)/libMiddle.so :
	make -C $(MID_DIR_B)

#------------------------------------
# 製品B ブリッジ
#------------------------------------
LIB_PATH_B_BRIDGE := ../ext/libBBridge

MID_DIR_B_BRIDGE := ../../../middle/prodBBridge
MID_LIBS_B_BRIDGE := $(LIB_PATH_B_BRIDGE)/libProdBBridge.so

.PHONY : preLibBBridge
preLibBBridge : $(MID_LIBS_B_BRIDGE)

$(MID_LIBS_B_BRIDGE) : $(LIB_PATH_B_BRIDGE)/% : $(MID_DIR_B_BRIDGE)/%
	cp $< $@

$(MID_DIR_B_BRIDGE)/libProdBBridge.so :
	make -C $(MID_DIR_B_BRIDGE)

.PHONY : preLib
preLib : preLibA preLibB preLibBBridge

#------------------------------------------------------------------

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(LIB_INC_B) $<

# ここから編集中

ap01_try : ap01.o
	$(CC) $(CFLAGS) $^ \
	-L ../ext/libBBridge -lProdBBridge \
	-L ../ext/libB -lMiddle -lLowProd02 \
	-L ../ext/libA -Wl,--no-as-needed -lLowProd01 \
	-o $@

run_ap01_try : ap01_try
	LD_LIBRARY_PATH=../ext/libA:../ext/libBBridge:../ext/libB/ ./ap01_try



#ap01_try : ap01.o
#	$(CC) $(CFLAGS) $^ \
#	-L ../../middle/prodBBridge -lProdBBridge \
#	-L ../../middle/prodB -lMiddle \
#	-L ../../lowProd02 -lLowProd02 \
#	-o $@

#run_ap01_try : ap01_try
#	LD_LIBRARY_PATH=../../lowProd01:../../middle/prodBBridge:../../middle/prodA:../../middle/prodB:../../lowProd02 ./ap01_try
#







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

.PHONY: all
all : $(TARGETS)




.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
	rm -f ../ext/incA/*
	rm -f ../ext/libA/*
	rm -f ../ext/incB/*
	rm -f ../ext/libB/*
	rm -f ../ext/libBBridge/*
