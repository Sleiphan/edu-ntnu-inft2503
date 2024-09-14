#include <algorithm>
#include <iostream>
#include <vector>

bool contains(const std::vector<double> &data, double value)
{
  return std::find(data.begin(), data.end(), value) != data.end();
}

int main()
{
  std::vector<double> data = {3.14, 2.56, 19.84, 4.20, 9.11};

  std::cout << "vector.front(): " << data.front() << std::endl;
  std::cout << "vector.back(): " << data.back() << std::endl;

  data.emplace(data.begin(), 7.11);
  std::cout << "vector.front() after vector.emplace(): " << data.front() << std::endl;

  std::cout << "Write a value: ";
  double value = 0.0;
  std::cin >> value;

  if (std::find(data.begin(), data.end(), value) != data.end())
    std::cout << "Value exists inside the vector." << std::endl;
  else
    std::cout << "Value does not exist inside the vector." << std::endl;

  return 0;
}