#ifndef CUSTOM_FRACTION_TYPE_FROM_LECTURE
#define CUSTOM_FRACTION_TYPE_FROM_LECTURE

#include <string>

class Fraction
{
public:
  int numerator;
  int denominator;

  Fraction();
  Fraction(const Fraction &); // Implicit declarations of this constructor is deprecated, and so it must be explicitly included.
  Fraction(int numerator, int denominator);
  void set(int numerator_, int denominator_ = 1);
  Fraction operator+(const Fraction &other) const;
  Fraction operator-(const Fraction &other) const;
  Fraction operator*(const Fraction &other) const;
  Fraction operator/(const Fraction &other) const;
  Fraction operator-(const int number) const;
  Fraction operator-() const;
  Fraction &operator++(); // Preinkrement
  Fraction &operator--(); // Predekrement
  Fraction &operator+=(const Fraction &other);
  Fraction &operator-=(const Fraction &other);
  Fraction &operator*=(const Fraction &other);
  Fraction &operator/=(const Fraction &other);
  Fraction &operator=(const Fraction &other);
  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  bool operator>(const Fraction &other) const;

  std::string to_string();

private:
  void reduce();
  int compare(const Fraction &other) const;
};

Fraction operator-(const int number, const Fraction &other);

#endif