#include <stdio.h>
#include "lowProd01.h"
#include "middle.h"

void func01(int x)
{
  printf("製品A 中間ライブラリ(埋込み) : %s : x = %d\n", __func__, x);
  printf("説明 : %s\n", libDescribe);
  printf("CALL 製品A lowProd01_func01\n");
  lowProd01_func01(x);
}
