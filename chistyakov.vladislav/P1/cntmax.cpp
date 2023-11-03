#include "cntmax.hpp"
#include <limits>
#include <stdexcept>

chistyakovCntMax::CntMax::CntMax() :
  max_(0),
  counter_(0)
{}

void chistyakovCntMax::CntMax::operator()(intmax_t number)
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

size_t chistyakovCntMax::CntMax::operator()() const
{
  return counter_;
}
