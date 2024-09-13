#include <stdio.h>

int main()
{
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  printf("i [%p]: %d\n", &i, i);
  printf("j [%p]: %d\n", &j, j);
  printf("p [%p]: %p\n", &p, p);
  printf("q [%p]: %p\n", &q, q);
}