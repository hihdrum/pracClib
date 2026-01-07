#include <stdio.h>
#include "lowProd02.h"

void lowProd02_func01(int x, int y)
{
  printf("製品B 下位ライブラリ(共有) : %s[%p] : x = %d, y = %d\n", __func__, lowProd02_func01, x, y);
}
