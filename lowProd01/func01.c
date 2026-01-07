#include <stdio.h>
#include "lowProd01.h"

void lowProd01_func01(int x)
{
  printf("製品A 下位ライブラリ : %s[%p] : x = %d\n", __func__, lowProd01_func01, x);
}
