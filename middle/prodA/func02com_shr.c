#include <stdio.h>
#include "lowProd01.h"
#include "middle.h"

void func02com(int x)
{
  printf("製品A 中間ライブラリ(共有) : %s : x = %d\n", __func__, x);
}
