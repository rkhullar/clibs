/*
 * @author  :  Rajan Khullar
 * @created :  08/18/16
 * @updated :  08/21/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "string.h"

//{{{
char * itoa(int x)
{
  unsigned int l = snprintf(NULL, 0, "%d", x) + 1;
  char *p = (char*) malloc(l*sizeof(char));
  snprintf(p, l+1, "%d", x);
  return p;
}
//}}}

void test01()
{
  string_class String = string_clazz();
  int x, l, N = 2; string *a[N];
  a[0] = String.mllc("hello world");
  a[1] = String.mllc("");
  for(x = 0; x < N; x++)
  {
    String.print(a[x]);
    l = String.length(a[x]);
    printf("%d\n", l);
    free(a[x]);
  }
}

void test02()
{
  string_class String = string_clazz();
  string *a = String.mllc("hello");
  string *b = String.mllc("helloo");
  bool t = String.equal(a, b);
  printf("%s = %s: %d\n", a->ptr, b->ptr, t);
  free(a); free(b);
}

void test03()
{
  string_class String = string_clazz();
  string *a[3];
  a[0] = String.mllc("hello");
  a[1] = String.mllc("cruel");
  a[2] = String.mllc("world");
  string *s = string_join(.array=a, .n=3, .delim=" : ", .prefix="[", .suffix="]");
  String.print(s);
  printf("N = %d\n", s->length);
  free(s);
  String.free(3, a);
}

void test04()
{
  string_class String = string_clazz();
  int x=0, N = 5, i[] = {12, 34, 56, 78, 90};
  char *c[N]; string *s[N];
  for(x = 0; x < N; x++)
  {
    c[x] = itoa(i[x]);
    s[x] = String.mllc(c[x]);
    //printf("%s\n", s[x]->ptr);
  }
  string *t = string_join(.array=s, .n=N, .prefix="[", .suffix="]");
  //string *t = string_join(N, s);
  String.print(t);
  for(x = 0; x < N; x++)
  {
    free(c[x]);
    free(s[x]);
  }
}

int main()
{
  //test01();
  //test02();
  //test03();
  test04();
}
