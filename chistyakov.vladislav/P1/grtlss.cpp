#include <limits>
#include <stdexcept>
#include "grtlss.hpp"
#include <iostream>

mySpace::grt-lss::grt-lss():
  counter(0);
{}

void mySpace::grt-lss::firstNumber(size_t number)
{
  fstNum = number;
}
void mySpace::grt-lss::middleNumber(size_t number)
{
  midNum = number;
}

void mySpace::grt-lss::countGRT(size_t number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (counter == max_size)
  {
    throw std::logic_error("sequence is too long\n");
  }

  if (fstNum < midNum && midNum > number)
  {
    ++counter;
  }
}

size_t mySpace::grt-lss::get_result-grt() const
{
  return counter;
}
