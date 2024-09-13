#include <stdio.h>

int main()
{
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  printf("i [%p]: %d\n", (void *)&i, i);
  printf("j [%p]: %d\n", (void *)&j, j);
  printf("p [%p]: %p\n", (void *)&p, (void *)p);
  printf("q [%p]: %p\n", (void *)&q, (void *)q);
}