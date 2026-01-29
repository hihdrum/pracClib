#include <stdio.h>
#include "middle.h"

static const char *funcDescribe = "製品A 中間ライブラリ(共有, static変数)";
static void func(int x);

void func04(int x)
{
  int called = 0;
  called++;

  printf("製品A 中間ライブラリ(共有, 埋込み) : %s : x = %d\n", __func__, x);
  printf("CALL static func : %d times.\n", called);
  func(x);
}

static void func(int x)
{
  printf("%s : %s : x = %d\n", funcDescribe, __func__, x);
  printf("CALL func01\n");
  func02com(x);
}
