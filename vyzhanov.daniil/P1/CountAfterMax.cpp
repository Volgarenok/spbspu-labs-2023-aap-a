#include "CountAfterMax.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

vyzhanov::CountAfterMax::CountAfterMax():
  maxi_num_(0),
  after_max_(0)
{}

void vyzhanov::CountAfterMax::operator()(int num)
{
  const size_t max_s = std::numeric_limits< size_t >::max();
  if (num > maxi_num_)
  {
    maxi_num_ = num;
    after_max_ = 0;
  }
  else if (num <= maxi_num_)
  {
    if (after_max_ == max_s)
    {
      throw std::logic_error("Sequence is too long!");
    }
    after_max_++;
  }
}
size_t vyzhanov::CountAfterMax::operator()() const
{
  if (maxi_num_ == 0)
  {
    throw std::logic_error("Sequence is too short!");
  }
  return after_max_;
}

