#include <stdio.h>
#include "middle.h"

static const char *funcDescribe = "製品A 中間共有ライブラリ ファイルスコープstatic変数";
static void func(int x);

void func04(int x)
{
  int called = 0;
  called++;

  printf("製品A 中間共有ライブラリの静的関数 %s(%d) が呼ばれました。\n", __func__, x);
  func(x);
  printf("製品A 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}

static void func(int x)
{
  printf("製品A 中間共有ライブラリの静的関数 %s(%d) が呼ばれました。\n", __func__, x);
  printf("%s : %s : x = %d\n", funcDescribe, __func__, x);
  func02com(x);
  printf("製品A 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}
