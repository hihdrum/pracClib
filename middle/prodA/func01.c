#include <stdio.h>
#include "lowProd01.h"
#include "middle.h"

void func01(int x)
{
  printf("prodA.middle.func01 : x = %d\n", x);
  printf("call lowProd01_func01\n");
  lowProd01_func01(x);
}
