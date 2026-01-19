#include <stdio.h>
#include "middle.h"

void func03(int x, int y)
{
  printf("製品B 中間ライブラリ(共有, 埋込み) : %s : x = %d, y = %d\n", __func__, x, y);
  printf("CALL func01\n");
  func01(x, y);
}
