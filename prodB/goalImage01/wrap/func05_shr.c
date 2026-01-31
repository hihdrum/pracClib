#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

extern const char *libDescribe;

void func05(int x, int y)
{
  printf("製品Bラッパー 中間共有ライブラリの関数 %s(%d, %d) が呼ばれました。\n", __func__, x, y);
  printf("製品Bラッパー グローバル変数の参照 : %s\n", libDescribe);

  static void (*real_func05)(int) = NULL;
  if(!real_func05)
  {
    void *handle = dlopen("libMiddleA.so", RTLD_LAZY);
    if(!handle)
    {
      fprintf(stderr, "dlopen(libMiddleA.so)異常 : %s\n", dlerror());
      exit(1);
    }

    real_func05 = dlsym(handle, "func05");
    if(!real_func05)
    {
      fprintf(stderr, "dlsym(func05) 異常 : %s\n", dlerror());
      exit(1);
    }
  }

  real_func05(x);
  printf("製品Bラッパー 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}
