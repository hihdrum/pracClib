TARGETS := ap01 ap01_shr ap01_sd ap01_ds

.PHONY: all
all : $(TARGETS)

# 製品A,Bの環境整備は似通っているので上手く共通化できるかもしれない。
#------------------------------------------------------------------
# 環境整備
#------------------------------------------------------------------
# 製品A ラッパー調整
#------------------------------------
LIB_INC_A := ../ext/incA
LIB_PATH_A := ../ext/libA

LOW_DIR_A := ../../../lowProd01
LOW_LIBS_A := $(LIB_PATH_A)/libLowProd01.so
LOW_HEADER_A := $(LIB_INC_A)/lowProd01.h

MID_DIR_A := ../../../middle/prodA
MID_LIBS_A := $(LIB_PATH_A)/libMiddleReal.so
MID_HEADER_A := $(LIB_INC_A)/middle.h

.PHONY : preLibA
preLibA : $(LOW_LIBS_A) $(LOW_HEADER_A) $(MID_LIBS_A) $(MID_HEADER_A)

$(LOW_LIBS_A) : $(LIB_PATH_A)/% : $(LOW_DIR_A)/%
	cp $< $@

$(LOW_HEADER_A) : $(LOW_DIR_A)/lowProd01.h
	cp $< $@

$(LOW_DIR_A)/lowProd01.h $(LOW_DIR_A)/libLowProd01.so :
	make -C $(LOW_DIR_A)

$(LIB_PATH_A)/libMiddleReal.so : $(MID_DIR_A)/libMiddle.so
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
LIB_PATH_B_SHIM := ../ext/libBShim

MID_DIR_B_SHIM := ../../../middle/prodBShim
MID_LIBS_B_SHIM := $(LIB_PATH_B_SHIM)/libMiddle.so

.PHONY : preLibBShim
preLibBShim : $(MID_LIBS_B_SHIM)

$(MID_LIBS_B_SHIM) : $(LIB_PATH_B_SHIM)/% : $(MID_DIR_B_SHIM)/%
	cp $< $@

$(MID_DIR_B_SHIM)/libProdBShim.so :
	make -C $(MID_DIR_B_SHIM)

.PHONY : preLib
preLib : preLibA preLibB preLibBShim

#------------------------------------------------------------------

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(LIB_INC_B) $<

ap01_try : ap01.o
	$(CC) $(CFLAGS) $^ \
	-L ../ext/libBShim -lMiddle \
	-L ../ext/libA -lMiddleReal \
	-L ../ext/libA -lLowProd01 \
	-o $@

run_ap01_try : ap01_try
	LD_LIBRARY_PATH=../ext/libBShim:../ext/libA ./ap01_try




ap01_try2 : ap01.o
	$(CC) $(CFLAGS) $^ \
	-L ../ext/libBBridge -lProdBBridge \
	-L ../ext/libB -lMiddle -lLowProd02 \
	-L ../ext/libA -Wl,--no-as-needed -lMiddle -lLowProd01 \
	-o $@

run_ap01_try2 : ap01_try2
	LD_LIBRARY_PATH=../ext/libBShim:../ext/libA ./ap01_try

run_ap01_A_Br_B : ap01_try
	LD_LIBRARY_PATH=../ext/libA:../ext/libBBridge:../ext/libB/ ./ap01_try

run_ap01_A_B_Br : ap01_try
	LD_LIBRARY_PATH=../ext/libA:../ext/libB:../ext/libBBridge ./ap01_try

run_ap01_B_Br_A : ap01_try
	LD_LIBRARY_PATH=../ext/libB:../ext/libBBridge:../ext/libA/ ./ap01_try

run_ap01_B_A_Br : ap01_try
	LD_LIBRARY_PATH=../ext/libB:../ext/libA:../ext/libBBridge: ./ap01_try

run_ap01_Br_B_A : ap01_try
	LD_LIBRARY_PATH=../ext/libBBridge:../ext/libB:../ext/libA/ ./ap01_try

run_ap01_Br_A_B : ap01_try
	LD_LIBRARY_PATH=../ext/libBBridge:../ext/libA:../ext/libB/ ./ap01_try


.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
	rm -f ../ext/incA/*
	rm -f ../ext/libA/*
	rm -f ../ext/incB/*
	rm -f ../ext/libB/*
	rm -f ../ext/libBShim/*
