#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

extern const char *libDescribe;

void func01(int x, int y)
{
  printf("製品B 中間ライブラリ(共有, ラッパー) : %s: x = %d, y = %d\n", __func__, x, y);
  printf("説明 : %s\n", libDescribe);
  static void (*real_func01)(int) = NULL;
  if(!real_func01)
  {
    void *handle = dlopen("libMiddleReal.so", RTLD_LAZY);
    if(!handle)
    {
      fprintf(stderr, "dlopen(libComReal.so)異常 : %s\n", dlerror());
      exit(1);
    }

    real_func01 = dlsym(handle, "func01");
    if(!real_func01)
    {
      fprintf(stderr, "dlsym(func01) 異常 : %s\n", dlerror());
      exit(1);
    }
  }

  printf("CALL func01\n");
  real_func01(x);
}
