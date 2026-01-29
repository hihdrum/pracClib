#include <stdio.h>
#include "lowProd02.h"
#include "middle.h"

void func01(int x, int y)
{
  printf("製品B 中間共有ライブラリの関数 %s(%d, %d) が呼ばれました。\n", __func__, x, y);
  printf("製品B グローバル変数の参照 : %s\n", libDescribe);
  lowProd02_func01(x, y);
  printf("製品B 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}
