class Circle
{
public:
  Circle(double radius_);
  double get_area() const;
  double get_circumference() const;

private:
  double radius;
};