TARGETS := ap01 ap01_shr ap01_sd ap01_ds

.PHONY: all
all : $(TARGETS)

CFLAGS += -Wall
CFLAGS += -g
CFLAGS += -MMD

%.o: %.c
	$(CC) $(CFLAGS) -c -I ../inc $<

#------------------------------------------------------------------
# 静的リンク版
ap01 : ap01.o
	$(CC) $(CFLAGS) $^ ../lib/libMiddle.a ../lib/libLowProd01.a -o $@

# 動的リンク版
ap01_shr : ap01.o
	$(CC) $(CFLAGS) $^ -L ../lib -lMiddle -lLowProd01 -o $@

# 混在リンク版
#  libLowProd01 : static
#  libMiddle    : dynamic
ap01_sd : ap01.o
	$(CC) $(CFLAGS) $^ -L ../lib -lMiddle ../lib/libLowProd01.a -o $@

# 混在リンク版
#  libLowProd01 : dynamic
#  libMiddle    : static
ap01_ds : ap01.o
	$(CC) $(CFLAGS) $^ ../lib/libMiddle.a -L ../lib -lLowProd01 -o $@

#------------------------------------------------------------------
run_ap01 : ap01
	@./ap01

run_ap01_shr : ap01_shr
	@LD_LIBRARY_PATH=../lib ./ap01_shr

run_ap01_sd : ap01_sd
	@LD_LIBRARY_PATH=../lib ./ap01_sd

run_ap01_ds : ap01_ds
	@LD_LIBRARY_PATH=../lib ./ap01_ds

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGETS)
