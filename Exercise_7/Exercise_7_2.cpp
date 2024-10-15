#include "Set.hpp"
#include <iostream>

int main()
{
  // Create empty set
  Set set;
  std::cout << "A new empty set: " << set << std::endl;

  std::cout << std::endl;

  // Find union between two sets
  Set union_set({1, 2, 3});
  union_set += Set({2, 3, 4});
  std::cout << "Union: " << union_set << std::endl;

  std::cout << std::endl;

  // Add a new number to a set
  std::cout << "Set before adding: " << set << std::endl;
  set += 5;
  std::cout << "Set after  adding: " << set << std::endl;

  std::cout << std::endl;

  // Assigning one set to another
  std::cout << "Set before assigning: " << set << std::endl;
  set = union_set;
  std::cout << "Set after assigning: " << set << std::endl;

  std::cout << std::endl;

  return 0;
}