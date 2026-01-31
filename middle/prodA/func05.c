#include <stdio.h>
#include "lowProd01.h"
#include "middle.h"

void func05(int x)
{
  printf("製品A 中間ライブラリの関数 %s(%d) が呼ばれました。\n", __func__, x);
  printf("製品A グローバル変数の参照 : %s\n", libDescribe);
  func04(x);
  printf("製品A 中間ライブラリの関数 %s を抜けます。\n", __func__);
}
