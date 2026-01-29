#include <stdio.h>
#include "middle.h"

static const char *funcDescribe = "製品B 中間ライブラリ ファイルスコープstatic変数";
static void func(int x);

void func04(int x)
{
  int called = 0;
  called++;

  printf("製品B 中間ライブラリの関数 %s(%d) が呼ばれました。\n", __func__, x);
  func(x);
  printf("製品B 中間ライブラリの関数 %s を抜けます。\n", __func__);
}

static void func(int x)
{
  printf("製品B 中間ライブラリの関数 %s(%d) が呼ばれました。\n", __func__, x);
  printf("製品B ファイルスコープstatic変数の参照 : %s\n", funcDescribe);
  func02com(x);
  printf("製品B 中間ライブラリの関数 %s を抜けます。\n", __func__);
}
