all : ap01

ap01.o : ap01.c
	gcc -Wall -c -MMD -I ../inc ap01.c

ap01 : ap01.o
	gcc -Wall ap01.o -L ../lib -lCom -o ap01

.PHONY: clean
clean:
	rm -f *.o *.d ap01
