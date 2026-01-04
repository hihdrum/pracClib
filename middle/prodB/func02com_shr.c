#include <stdio.h>
#include "lowProd02.h"
#include "middle.h"

void func02com(int x)
{
  printf("製品B 中間ライブラリ(共有) : %s : x = %d\n", __func__, x);
}
