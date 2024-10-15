#ifndef CUSTOM_SET_CLASS_FOR_EXERCISE_PURPOSE
#define CUSTOM_SET_CLASS_FOR_EXERCISE_PURPOSE

#include <ostream>
#include <stddef.h>
#include <vector>

class Set
{
public:
  Set();
  Set(const int *numbers, const size_t count);
  Set(std::vector<int>);
  Set(const Set &other);
  Set &operator=(const Set &other);
  Set &operator+=(const int number);
  Set &operator+=(const Set &other);

  inline const std::vector<int>::const_iterator begin() const { return set.begin(); };
  inline const std::vector<int>::const_iterator end() const { return set.end(); };

  inline size_t size() const { return set.size(); }

private:
  std::vector<int> set;
};

std::ostream &operator<<(std::ostream &out, const Set &set);

#endif