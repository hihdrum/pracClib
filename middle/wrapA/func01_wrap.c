#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

static void (*prodA_func01)(int x);

void __attribute__((constructor))
init_prodA_func01(void)
{
  prodA_func01 = dlsym(RTLD_NEXT, "func01");
}

void func01(int x, int y)
{
  printf("wrapper func01 : y = %d\n", y);
  (*prodA_func01)(x);
}
