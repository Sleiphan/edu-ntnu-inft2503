#include <stdio.h>

int main()
{
  double number;
  double *number_p = &number;
  double &number_r = number;

  number = 1.;
  printf("number   <- 1; number: %f\n", number);

  *number_p = 2.;
  printf("number_r <- 2; number: %f\n", number);

  number_r = 3.;
  printf("number_r <- 3; number: %f\n", number);
}