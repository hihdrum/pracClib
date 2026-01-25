TARGETS := ap01

.PHONY: all
all : $(TARGETS)

# 製品A,Bの環境整備は似通っているので上手く共通化できるかもしれない。
#------------------------------------------------------------------
# 環境整備
#------------------------------------------------------------------
# 製品A
#  ラッパー経由で呼び出される部分
#------------------------------------
LIB_INC_A := ../ext/incA
LIB_PATH_A := ../ext/libA

LOW_DIR_A := ../../../lowProd01
TO_LOW_LIBS_A := $(LIB_PATH_A)/libLowProd01.so
TO_LOW_HEADER_A := $(LIB_INC_A)/lowProd01.h

MID_DIR_A := ../../../middle/prodA

# サンプル簡易化の目的で、libMiddle.soを別のファイル名にする。
TO_MID_LIBS_A := $(LIB_PATH_A)/libMiddleA.so
TO_MID_HEAER_A := $(LIB_INC_A)/middle.h

$(TO_LOW_LIBS_A) : $(LIB_PATH_A)/% : $(LOW_DIR_A)/%
	cp $< $@

$(TO_LOW_HEADER_A) : $(LOW_DIR_A)/lowProd01.h
	cp $< $@

$(LOW_DIR_A)/lowProd01.h $(LOW_DIR_A)/libLowProd01.so :
	make -C $(LOW_DIR_A)

$(LIB_PATH_A)/libMiddleA.so : $(MID_DIR_A)/libMiddle.so
	cp $< $@

$(TO_MID_HEAER_A) : $(MID_DIR_A)/middle.h
	cp $< $@

$(MID_DIR_A)/libMiddle.so :
	make -C $(MID_DIR_A)

.PHONY : preLibA
preLibA : $(TO_LOW_LIBS_A) $(TO_LOW_HEADER_A) $(TO_MID_LIBS_A) $(TO_MID_HEAER_A)

#------------------------------------
# 製品B
#------------------------------------
LIB_INC_B := ../ext/incB
LIB_PATH_B := ../ext/libB

LOW_DIR_B := ../../../lowProd02
TO_LOW_LIB_B := $(LIB_PATH_B)/libLowProd02.so
TO_LOW_HEADER_B := $(LIB_INC_B)/lowProd02.h

MID_DIR_B := ../../../middle/prodB
MID_LIBS_B := $(LIB_PATH_B)/libMiddle.so
MID_HEADER_B := $(LIB_INC_B)/middle.h

$(TO_LOW_LIB_B) : $(LIB_PATH_B)/% : $(LOW_DIR_B)/%
	cp $< $@

$(TO_LOW_HEADER_B) : $(LOW_DIR_B)/lowProd02.h
	cp $< $@

$(LOW_DIR_B)/lowProd01.h $(LOW_DIR_B)/libLowProd01.so :
	make -C $(LOW_DIR_B)

$(MID_LIBS_B) : $(LIB_PATH_B)/% : $(MID_DIR_B)/%
	cp $< $@

$(MID_HEADER_B) : $(MID_DIR_B)/middle.h
	cp $< $@

$(MID_DIR_B)/libMiddle.a $(MID_DIR_B)/libMiddle.so :
	make -C $(MID_DIR_B)

.PHONY : preLibB
preLibB : $(TO_LOW_LIB_B) $(TO_LOW_HEADER_B) $(MID_LIBS_B) $(MID_HEADER_B)

#------------------------------------
# 製品B -> A 中間層ラッパーライブラリ
#------------------------------------
LIB_PATH_WRAP := ../ext/libWrap

MID_WRAP_DIR := ../wrap
TO_MID_LIB_WRAP := $(LIB_PATH_WRAP)/libMiddleWrap.so

$(TO_MID_LIB_WRAP) : $(LIB_PATH_WRAP)/% : $(MID_WRAP_DIR)/%
	cp $< $@

$(MID_WRAP_DIR)/libMiddleWrap.so :
	make -C $(MID_WRAP_DIR)

.PHONY : preLibWrap
preLibWrap : $(TO_MID_LIB_WRAP)


.PHONY : preLib
preLib : preLibA preLibB preLibWrap

#------------------------------------------------------------------

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(LIB_INC_B) $<

ap01 : ap01.o
	$(CC) $(CFLAGS) $^ \
	-L ../ext/libWrap -lMiddleWrap \
	-L ../ext/libB -lMiddle \
	-L ../ext/libB -lLowProd02 \
	-L ../ext/libA -lMiddleA \
	-L ../ext/libA -Wl,--no-as-neede -lLowProd01 \
	-o $@

run_ap01 : ap01
	LD_LIBRARY_PATH=../ext/libWrap:../ext/libB:../ext/libA ./ap01_try

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
	rm -f ../ext/incA/*
	rm -f ../ext/libA/*
	rm -f ../ext/incB/*
	rm -f ../ext/libB/*
	rm -f ../ext/libWrap/*
