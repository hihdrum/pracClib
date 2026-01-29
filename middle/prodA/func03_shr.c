#include <stdio.h>
#include "middle.h"

void func03(int x)
{
  printf("製品A 中間共有ライブラリの関数 %s(%d) が呼ばれました。\n", __func__, x);
  func01(x);
  printf("製品A 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}
