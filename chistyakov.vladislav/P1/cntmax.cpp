#include "cntmax.hpp"
#include <limits>
#include <stdexcept>

chistyakov::CntMax::CntMax() :
  max_(0),
  counter_(0)
{}

void chistyakov::CntMax::operator()(intmax_t number)
{
  if (!max_)
  {
    max_ = number;
  }

  size_t max_size = std::numeric_limits< size_t >::max();

  if (counter_ > max_size)
  {
    throw std::logic_error("sequence is too long");
  }

  if (number > max_)
  {
      max_ = number;
      counter_ = 1;
  }
  else if (number == max_)
  {
      ++counter_;
  }
}

size_t chistyakov::CntMax::operator()() const
{
  return counter_;
}
