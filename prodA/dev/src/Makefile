TARGETS := preLib ap01 ap01_shr ap01_sd ap01_ds

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
LOWPROD01_DIR := ../../../lowProd01

.PHONY : preLib
preLib :
	# lowProd01
	make -C $(LOWPROD01_DIR)
	cp $(LOWPROD01_DIR)/lowProd01.h $(LIB_INC)
	cp $(LOWPROD01_DIR)/libLowProd01.a $(LIB_PATH)
	cp $(LOWPROD01_DIR)/libLowProd01.so $(LIB_PATH)

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
	rm -f *.o *.d $(TARGETS)
