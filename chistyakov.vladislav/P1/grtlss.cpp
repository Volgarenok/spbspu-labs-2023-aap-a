#include <limits>
#include <stdexcept>
#include "grtlss.hpp"
#include <iostream>

mySpace::grt_lss::grt_lss():
  counter(0)
{}

void mySpace::grt_lss::firstNumber(size_t number)
{
  fstNum = number;
}
void mySpace::grt_lss::middleNumber(size_t number)
{
  midNum = number;
}

void mySpace::grt_lss::countGRT(size_t number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (counter == max_size)
  {
    throw std::logic_error("sequence is too long\n");
  }

  if (fstNum > midNum and midNum > number)
  {
    ++counter;
  }
  fstNum = midNum;
  midNum = number;
}

size_t mySpace::grt_lss::get_result_grt() const
{
  return counter;
}
