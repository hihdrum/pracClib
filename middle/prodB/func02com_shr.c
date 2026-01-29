#include <stdio.h>
#include "lowProd02.h"
#include "middle.h"

void func02com(int x)
{
  printf("製品B 中間共有ライブラリの関数 %s(%d) が呼ばれました。\n", __func__, x);
  printf("製品B 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}
