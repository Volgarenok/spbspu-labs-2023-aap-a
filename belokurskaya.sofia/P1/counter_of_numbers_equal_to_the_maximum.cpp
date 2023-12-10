#include "counter_of_numbers_equal_to_the_maximum.hpp"
#include <limits>
#include <stdexcept>

belokurskaya::CounterOfNumbersEqualToTheMaximum::CounterOfNumbersEqualToTheMaximum():
  max_element_(std::numeric_limits< int >::min()),
  max_element_amount_(1)
{}

void belokurskaya::CounterOfNumbersEqualToTheMaximum::operator()(int number)
{
  if (number > max_element_)
  {
    max_element_ = number;
    max_element_amount_ = 1;
  }
  else if (number == max_element_)
  {
    if (max_element_amount_ == std::numeric_limits< size_t >::max())
    {
      throw std::out_of_range("There is too many elements equal max");
    }
    ++max_element_amount_;
  }
}
size_t belokurskaya::CounterOfNumbersEqualToTheMaximum::operator()() const
{
  return max_element_amount_;
}
