
#include "Fraction.hpp"
#include <iostream>

int main()
{
  Fraction fraction_1(5 * 6 - 1, 6);

  Fraction result_1 = fraction_1 - 5;
  Fraction result_2 = 5 - fraction_1;

  std::cout << "Result 1: " << result_1.to_string() << std::endl;
  std::cout << "Result 2: " << result_2.to_string() << std::endl;

  return 0;
}