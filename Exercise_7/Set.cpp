#include "Set.hpp"

Set::Set() {}
Set::Set(const Set &other) : set(other.set) {}
Set::Set(std::vector<int> numbers) : Set(numbers.data(), numbers.size()) {}

Set::Set(const int *numbers, const size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    int exists = 0;

    for (int num : set)
      exists += numbers[i] == num;

    if (!exists)
      set.push_back(numbers[i]);
  }
}

Set &Set::operator=(const Set &other)
{
  this->set = other.set;
  return *this;
}

Set &Set::operator+=(const int number)
{
  int exists = 0;

  for (int i : set)
    exists += i == number;

  if (!exists)
    set.push_back(number);

  return *this;
}

Set &Set::operator+=(const Set &other)
{
  for (int i : other.set)
    this->operator+=(i);

  return *this;
}

std::ostream &operator<<(std::ostream &out, const Set &set)
{

  std::string numbers = "[";

  for (int i : set)
    numbers.append(std::to_string(i) + ", ");

  if (set.size())
  {
    numbers.pop_back();
    numbers.pop_back();
  }

  numbers.append("]");

  out << numbers;

  return out;
}