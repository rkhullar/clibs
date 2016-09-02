/*
 * @author  :  Rajan Khullar
 * @created :  09/01/16
 * @updated :  09/01/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "misc.h"

void test01()
{
  int a = 2, b = 2, c = 1;
  printf("%d = %d? %d\n", a, b, ieq(a, b));
  printf("%d = %d? %d\n", a, c, ieq(a, c));
}

void test02()
{
  int a, b; char *p, *q;
  a = 1234567890;
  b = -123456789;
  p = itoa(a);
  q = itoa(b);
  printf("%d => %s\n", a, p);
  printf("%d => %s\n", b, q);
  free(p);
  free(q);
}

int main()
{
  test01();
  test02();
}
