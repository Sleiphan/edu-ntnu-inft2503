#include "Exercise_3_1.hpp"

const double pi = 3.141592;

Circle::Circle(double radius_) : radius(radius_)
{
}

double Circle::get_area() const
{
  return pi * radius * radius;
}

double Circle::get_circumference() const
{
  double circumference = 2.0 * pi * radius;
  return circumference;
}