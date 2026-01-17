#include <stdio.h>
#include "lowProd02.h"
#include "middle.h"

void func01(int x, int y)
{
  printf("製品B 中間ライブラリ(共有,埋込み) : %s: x = %d, y = %d\n", __func__, x, y);
  printf("説明 : %s\n", libDescribe);
  printf("CALL lowProd02_func01\n");
  lowProd02_func01(x, y);
}
