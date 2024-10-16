#include <boost/type_index.hpp>
#include <iostream>

template <typename T>
bool equal(const T &a, const T &b)
{
  std::cout << "[equal()] Type: " << boost::typeindex::type_id_with_cvr<T>().pretty_name();
  return a == b;
}

bool equal_doubles(const double &a, const double &b)
{
  std::cout << "[equal_doubles()] Type: " << boost::typeindex::type_id_with_cvr<double>().pretty_name();
  return abs(a - b) < 0.00001;
}

int main()
{
  std::cout << ". Result: " + std::to_string(equal(1, 2)) << std::endl;
  std::cout << ". Result: " + std::to_string(equal(2, 2)) << std::endl;
  std::cout << ". Result: " + std::to_string(equal(1.0, 2.0)) << std::endl;
  std::cout << ". Result: " + std::to_string(equal(2.0, 2.0)) << std::endl;
  std::cout << ". Result: " + std::to_string(equal(1.0f, 2.0f)) << std::endl;
  std::cout << ". Result: " + std::to_string(equal(2.0f, 2.0f)) << std::endl;

  std::cout << ". Result: " + std::to_string(equal_doubles(1, 2)) << std::endl;
  std::cout << ". Result: " + std::to_string(equal_doubles(2, 2)) << std::endl;

  return 0;
}