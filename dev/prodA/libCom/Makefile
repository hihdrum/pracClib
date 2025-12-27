libCom.a : func01.o
	ar rcs libCom.a func01.o

func01.o : func01.c
	gcc -Wall -c -MMD func01.c

-include *.d

.PHONY: clean
clean:
	rm -f *.o *.d *.a

