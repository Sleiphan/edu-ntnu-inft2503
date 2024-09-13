#include <iostream>

int main()
{
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  std::cout << *p << " " << *q << std::endl;
}