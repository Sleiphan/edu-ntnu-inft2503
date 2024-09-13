#include <stdio.h>

int find_sum(const int *table, int length)
{
  int sum = 0;

  const int *end = table + length;

  while (table != end)
    sum += *(table++);

  return sum;
}

int main()
{
  const char TABLE_SIZE = 20;

  int table[TABLE_SIZE];

  for (int i = 0; i < TABLE_SIZE; ++i)
    table[i] = i + 1;

  printf("Sum av 10 første tall: %2d\n", find_sum(table, 10));
  printf("Sum av neste 5 tall:   %2d\n", find_sum(&table[10], 5));
  printf("Sum av 5 siste tall:   %2d\n", find_sum(&table[TABLE_SIZE - 5], 5));
}