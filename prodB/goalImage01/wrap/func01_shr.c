#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

extern const char *libDescribe;

void func01(int x, int y)
{
  printf("製品Bラッパー 中間共有ライブラリの関数 %s(%d, %d) が呼ばれました。\n", __func__, x, y);
  printf("製品Bラッパー グローバル変数の参照 : %s\n", libDescribe);

  static void (*real_func01)(int) = NULL;
  if(!real_func01)
  {
    void *handle = dlopen("libMiddleA.so", RTLD_LAZY);
    if(!handle)
    {
      fprintf(stderr, "dlopen(libMiddleA.so)異常 : %s\n", dlerror());
      exit(1);
    }

    real_func01 = dlsym(handle, "func01");
    if(!real_func01)
    {
      fprintf(stderr, "dlsym(func01) 異常 : %s\n", dlerror());
      exit(1);
    }
  }

  real_func01(x);
  printf("製品Bラッパー 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}
