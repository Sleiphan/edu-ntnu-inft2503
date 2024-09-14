#include "commodity.hpp"

Commodity::Commodity(std::string name, uint64_t id, double unit_price) : name(name), id(id), unit_price(unit_price) {}

std::string Commodity::get_name()
{
  return name;
}

long Commodity::get_id()
{
  return id;
}

double Commodity::get_price()
{
  return unit_price;
}

double Commodity::get_price(double quantity)
{
  return unit_price * quantity;
}

double Commodity::get_price_with_sales_tax(double quantity)
{
  return unit_price * quantity * 1.25;
}

void Commodity::set_price(double price)
{
  unit_price = price;
}
