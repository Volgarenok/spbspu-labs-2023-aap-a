#include "cntmax.hpp"
#include <stdexcept>
#include <limits>


skopchenko::CntMax::CntMax():
  max_(0),
  count_(1)
{}

void skopchenko::CntMax::operator()(int current)
{
  if (max_ < current)
  {
    max_ = current;
    count_ = 1;
  }
  else if (max_ == current)
  {
    size_t max_count = std::numeric_limits< size_t >::max();

    if (count_ == max_count)
    {
      throw std::logic_error("max sequence lengh");
    }
    else
    {
      count_++;
    }
  }
}

size_t skopchenko::CntMax::operator()() const
{
  return count_;
}
