#include <stdio.h>
#include "lowProd01.h"
#include "lowProd02.h"

void lowProd02_func01(int x, int y)
{
  printf("製品B 下位ライブラリ(自作, ラッパー) : %s : x = %d, y = %d\n", __func__, x, y);

  printf("      CALL lowPrd01_func01\n");
  lowProd01_func01(x);
}
