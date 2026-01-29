#include <stdio.h>
#include "middle.h"

void func03(int x, int y)
{
  printf("製品B 中間ライブラリ関数 %s(%d, %d) が呼ばれました。\n", __func__, x, y);
  func01(x, y);
  printf("製品B 中間ライブラリ関数 %s を抜けます。\n", __func__);
}
