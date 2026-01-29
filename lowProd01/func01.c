#include <stdio.h>
#include "lowProd01.h"

void lowProd01_func01(int x)
{
  printf("製品A 下位ライブラリの関数 %s(%d) が呼ばれました。\n", __func__, x);
  printf("製品A 下位ライブラリの関数 %s を抜けます。\n", __func__);
}
