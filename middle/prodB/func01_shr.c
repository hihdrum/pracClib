#include <stdio.h>
#include "lowProd02.h"
#include "middle.h"

void func01(int x, int y)
{
  printf("prodB.middle.func01 shr: x = %d, y = %d\n", x, y);
  printf("call lowProd02_func01\n");
  lowProd02_func01(x, y);
}
