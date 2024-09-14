#ifndef CUSTOM_COMMODITY_CLASS
#define CUSTOM_COMMODITY_CLASS

#include <stdint.h>
#include <string>

class Commodity
{
private:
  const std::string name;
  const uint64_t id;
  double unit_price;

public:
  Commodity(std::string name, uint64_t id, double unit_price);

  std::string get_name();
  long get_id();
  double get_price();
  double get_price(double quantity);
  double get_price_with_sales_tax(double quantity);

  void set_price(double price);
};

#endif // CUSTOM_COMMODITY_CLASS