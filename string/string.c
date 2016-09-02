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
extern string_class string_clazz()
{
  string_class c;
  c.init   = &string_init;
  c.mllc   = &string_mllc;
  c.free   = &string_free;
  c.length = &string_length;
  c.print  = &string_print;
  c.equal  = &string_equal;
  c.join   = &string_join_base;
  return c;
}
//}}}

//{{{
extern string string_init(const char *str)
{
  string o;
  o.ptr = (char*) str;
  o.length = string_length(&o);
  return o;
}

extern string * string_mllc(const char* str)
{
  string *o = (string*) malloc(sizeof(string));
  if(o == NULL) exit(1);
  *o = string_init(str);
  return o;
}

extern void string_free(unsigned int n, string *a[])
{
  string **t = a;
  for(unsigned int x = 0; x < n; x++)
  {
    free(*t);
    t++;
  }
}

static unsigned int string_length(string* o)
{
  const char *c = o->ptr;
  o->length = string_clen(c);
  return o->length;
}

static unsigned int string_clen(const char* c)
{
  unsigned int l = 0;
  while(*c++) l++;
  return l;
}

static void string_print(string* o)
{
  printf("%s\n", o->ptr);
}

static bool string_equal(string* a, string* b)
{
  char *x = a->ptr; char *y = b->ptr;
  while(*x != '\0' && *y != '\0')
    if(*x++ != *y++)
    return false;
  return *x == *y;
}

extern string * string_join_wrap(string_join_args args)
{
  const char *d = args.delim  ? args.delim  : ", ";
  const char *p = args.prefix ? args.prefix : "";
  const char *s = args.suffix ? args.suffix : "";
  return string_join_base(args.n, args.array, d, p, s);
}

/*
 * @input  : length string array, delimiter, string array
 * @output : joined string
 */
static string * string_join_base(unsigned int n, string *a[], const char *d, const char *px, const char *sx)
{
  string **t = a, *s; char *m, *c;
  unsigned int ls[n], l, k, x, y=0;
  // find total lenght of new string
  for(x = 0; x < n; x++)
  {
    ls[x] = a[x]->length;
    l += ls[x];
    t++;
  }
  l += (n-1)*string_clen(d) + string_clen(px) + string_clen(sx) + 1;
  k = l - string_clen(sx) - 1;
  // create output string
  s = string_mllc("");
  // add prefix
  m = (char*) malloc(l*sizeof(char));
  c = (char*) px;
  while(*c)
    m[y++] = *c++;
  for(x = 0; x < n; x++)
  {
    // add chars from one input string
    c = a[x]->ptr;
    while(*c)
      m[y++] = *c++;
    // add chars from delimiter
    c = (char*) d;
    while(*c && y < k)
      m[y++] = *c++;
  }
  // add suffix
  c = (char*) sx;
  while(*c)
    m[y++] = *c++;
  m[y] = '\0'; // terminator
  s->ptr = m;
  s->length = l-1;
  return s;
}
//}}}
