#include <stdio.h>

extern void __real_func01(int x);

void __wrap_func01(int x, int y)
{
  printf("wrap_func01, y = %d\n", y);
  __real_func01(x);
}
