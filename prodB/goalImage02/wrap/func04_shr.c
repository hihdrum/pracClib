#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

extern const char *libDescribe;

void func04(int x)
{
  printf("製品Bラッパー 中間共有ライブラリの関数 %s(%d) が呼ばれました。\n", __func__, x);
  printf("製品Bラッパー グローバル変数の参照 : %s\n", libDescribe);

  static void (*real_func04)(int) = NULL;
  if(!real_func04)
  {
    void *handle = dlopen("libMiddleA.so", RTLD_LAZY);
    if(!handle)
    {
      fprintf(stderr, "dlopen(libMiddleA.so)異常 : %s\n", dlerror());
      exit(1);
    }

    real_func04 = dlsym(handle, "func04");
    if(!real_func04)
    {
      fprintf(stderr, "dlsym(func01) 異常 : %s\n", dlerror());
      exit(1);
    }
  }

  real_func04(x);
  printf("製品Bラッパー 中間共有ライブラリの関数 %s を抜けます。\n", __func__);
}
