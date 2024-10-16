

template <typename T1, typename T2>
class Pair
{
public:
  T1 first;
  T2 second;

  Pair() {}
  Pair(const Pair &other) : first(other.first), second(other.second) {}
  Pair(T1 first, T2 second) : first(first), second(second) {}

  Pair operator+(const Pair &other) { return Pair(first + other.first, second + other.second); }
  bool operator<(const Pair &other);
  bool operator>(const Pair &other) { return !(*this < other); }
};

template <typename T1, typename T2>
bool Pair<T1, T2>::operator<(const Pair &other)
{
  if (first == other.first)
    return second < other.second;

  return first < other.first;
}