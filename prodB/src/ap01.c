#include <stdio.h>
#include "middle.h"

int main(void)
{
  puts("----------------------");
  puts("- 製品B AP01         -");
  puts("----------------------");
  func01(100, 1000);
  puts("");

  puts("----------------------");
  func02com(200);
  puts("");

  puts("----------------------");
  func01(300, 3000);
  puts("");

  return 0;
}
