#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> v)
{
  std::string output = "[";
  for (int i : v)
    output.append(std::to_string(i) + ", ");
  output.pop_back();
  output.pop_back();
  output.append("]");
  std::cout << output << std::endl;
}

int main()
{

  std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  std::vector<int> v2 = {2, 3, 12, 14, 24};

  std::cout << "a)" << std::endl;

  auto it = std::find_if(v1.begin(), v1.end(), [](int i)
                         { return i > 15; });

  if (it != v1.end())
    std::cout << "Found value " << std::to_string(*it) << " at index " << std::to_string(it - v1.begin()) << std::endl;
  else
    std::cout << "No value over 15 found" << std::endl;

  std::cout << std::endl;
  std::cout << "b)" << std::endl;

  bool equal_first_5 = std::equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int i1, int i2)
                                  { return abs(i1 - i2) <= 2; });

  bool equal_first_4 = std::equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int i1, int i2)
                                  { return abs(i1 - i2) <= 2; });

  std::cout << "The first 5 values in the vectors are " << (equal_first_5 ? "ALMOST EQUAL" : "NOT almost equal") << std::endl;
  std::cout << "The first 4 values in the vectors are " << (equal_first_4 ? "ALMOST EQUAL" : "NOT almost equal") << std::endl;

  std::cout << std::endl;
  std::cout << "c)" << std::endl;

  std::cout << "'v1' before replacement call:" << std::endl;
  print_vector(v1);

  std::replace_copy_if(v1.begin(), v1.end(), v1.begin(), [](int i)
                       { return i & 1; }, 100);

  std::cout << "'v1' after replacement call:" << std::endl;
  print_vector(v1);

  std::cout << std::endl;

  return 0;
}