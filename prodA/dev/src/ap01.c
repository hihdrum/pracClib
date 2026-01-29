#include <stdio.h>
#include "middle.h"

int main(void)
{
  puts("----------------------");
  puts("- 製品A AP01         -");
  puts("----------------------");
  func01(10);
  puts("");

  puts("----------------------");
  func02com(20);
  puts("");

  puts("----------------------");
  func01(30);

  puts("----------------------");
  func03(30);

  puts("----------------------");
  func04(40);

  return 0;
}
