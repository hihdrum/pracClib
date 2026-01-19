#include <stdio.h>
#include "middle.h"

void func03(int x)
{
  printf("製品A 中間ライブラリ(共有,埋込み) : %s : x = %d\n", __func__, x);
  printf("CALL func01\n");
  func01(x);
}
