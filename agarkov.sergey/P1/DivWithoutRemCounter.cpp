#include "DivWithoutRemCounter.hpp"

#include <stdexcept>
#include <limits>
#include <cstddef>

agarkov::DivWithoutRemCounter::DivWithoutRemCounter():
  prev(0),
  count(0)
{}

void agarkov::DivWithoutRemCounter::operator()(int num)
{
  if (prev == 0)
  {
    prev = num;
    return;
  }
  if (prev < 0)
  {
    throw std::logic_error("Division by remainder by a negative number");
  }
  if (num % prev == 0)
  {
    if (count == std::numeric_limits< size_t >::max())
    {
      throw std::logic_error("The upper limit size_t");
    }
    count++;
  }
  prev = num;
}

int agarkov::DivWithoutRemCounter::getCount() const
{
  return count;
}
