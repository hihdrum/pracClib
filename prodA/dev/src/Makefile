TARGETS := ap01 ap01_shr ap01_sd ap01_ds

LIB_INC := ../ext/inc
LIB_PATH := ../ext/lib

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c $(LIB_INC)
	$(CC) $(CFLAGS) -c -I $(LIB_INC) $<

#------------------------------------------------------------------
# runターゲット
#------------------------------------------------------------------
.PHONY : run-all
run-all : run_ap01 ap01_shr run_ap01_sd run_ap01_ds

#------------------------------------------------------------------
# 環境整備
#------------------------------------------------------------------
# Low層
LOWPROD01_DIR := ../../../lowProd01

TO_LOW_LIBS := $(LIB_PATH)/libLowProd01.a $(LIB_PATH)/libLowProd01.so
TO_LOW_HEADER := $(LIB_INC)/lowProd01.h

.PHONY : preLibLow
preLibLow : $(TO_LOW_LIBS) $(TO_LOW_HEADER)

$(TO_LOW_LIBS) : $(LIB_PATH)/% : $(LOWPROD01_DIR)/%
	cp $< $@

$(TO_LOW_HEADER) : $(LOWPROD01_DIR)/lowProd01.h
	cp $< $@

$(LOWPROD01_DIR)/lowProd01.h $(LOWPROD01_DIR)/libLowProd01.a $(LOWPROD01_DIR)/libLowProd01.so :
	make -C $(LOWPROD01_DIR)

# Middle層

MIDDLE_A_DIR := ../../../middle/prodA

TO_MIDDLE_LIBS := $(LIB_PATH)/libMiddle.a $(LIB_PATH)/libMiddle.so
TO_MIDDLE_HEADER := $(LIB_INC)/middle.h

.PHONY : preLibMiddle
preLibMiddle : $(TO_MIDDLE_LIBS) $(TO_MIDDLE_HEADER)

$(TO_MIDDLE_LIBS) : $(LIB_PATH)/% : $(MIDDLE_A_DIR)/%
	cp $< $@

$(TO_MIDDLE_HEADER) : $(MIDDLE_A_DIR)/middle.h
	cp $< $@

$(MIDDLE_A_DIR)/middle.h $(MIDDLE_A_DIR)/libMiddle.a $(MIDDLE_A_DIR)/libMiddle.so :
	make -C $(MIDDLE_A_DIR)

.PHONY : preLib
preLib : preLibLow preLibMiddle

#------------------------------------------------------------------
# 静的リンク版
#------------------------------------------------------------------
ap01 : ap01.o
	$(CC) $(CFLAGS) $^ $(LIB_PATH)/libMiddle.a $(LIB_PATH)/libLowProd01.a -o $@

run_ap01 : ap01
	@./ap01

#------------------------------------------------------------------
# 動的リンク版
#------------------------------------------------------------------
ap01_shr : ap01.o
	$(CC) $(CFLAGS) $^ -L $(LIB_PATH) -lMiddle -lLowProd01 -o $@

run_ap01_shr : ap01_shr
	@LD_LIBRARY_PATH=$(LIB_PATH) ./ap01_shr

#------------------------------------------------------------------
# 混在リンク版
#  libLowProd01 : static
#  libMiddle    : dynamic
#------------------------------------------------------------------
ap01_sd : ap01.o
	$(CC) $(CFLAGS) $^ -L $(LIB_PATH) -lMiddle $(LIB_PATH)/libLowProd01.a -o $@

run_ap01_sd : ap01_sd
	@LD_LIBRARY_PATH=$(LIB_PATH) ./ap01_sd

#------------------------------------------------------------------
# 混在リンク版
#  libLowProd01 : dynamic
#  libMiddle    : static
#------------------------------------------------------------------
ap01_ds : ap01.o
	$(CC) $(CFLAGS) $^ $(LIB_PATH)/libMiddle.a -L $(LIB_PATH) -lLowProd01 -o $@

run_ap01_ds : ap01_ds
	@LD_LIBRARY_PATH=$(LIB_PATH) ./ap01_ds

#------------------------------------------------------------------
.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS) $(LIB_INC)/* $(LIB_PATH)/*
