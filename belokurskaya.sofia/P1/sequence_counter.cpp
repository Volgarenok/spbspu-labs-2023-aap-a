#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

const int min_ = std::numeric_limits< int >::min();

belokurskaya::CounterOfNumbersEqualToTheMaximum::CounterOfNumbersEqualToTheMaximum():
  max_(min_),
  count_max_(1)
{}

void belokurskaya::CounterOfNumbersEqualToTheMaximum::operator()(int number)
{
  if (number > max_)
  {
    max_ = number;
    count_max_ = 1;
  }
  else if (number == max_)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_max_ == max_size)
      {
        throw "There is too many elements equal max";
      }
    ++count_max_;
  }
}
size_t belokurskaya::CounterOfNumbersEqualToTheMaximum::operator()() const
{
  return count_max_;
}
