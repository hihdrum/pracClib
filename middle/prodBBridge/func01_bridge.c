#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

/* 共有ライブラリのリンク順は以下とする。*/
/* 本ブリッジ */
/* prodB */
/* prodA */

#if 0
static void (*prodA_func01)(int x);

void __attribute__((constructor))
init_prodA_func01(void)
{
  prodA_func01 = dlsym(RTLD_NEXT, "func01");
}

#endif

void func01(int x, int y)
{
  printf("x = %d, y = %d\n", x, y);

  void (*prodA_func01)(int);

  prodA_func01 = dlsym(RTLD_NEXT, "func01");
  printf("prodA_func01 : %p\n", prodA_func01);

  prodA_func01 = dlsym(RTLD_NEXT, "func01");
  printf("prodA_func01 : %p\n", prodA_func01);

  printf("CALL func01 : y = %d\n", y);
  (*prodA_func01)(x);
}
