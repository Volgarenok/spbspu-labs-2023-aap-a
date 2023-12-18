#include "PrevMoreNextLessCheck.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

vyzhanov::MoreAndLess::MoreAndLess():
  next_num_(0),
  prev_num_(0),
  now_num_(0),
  count_(0)
{}

void vyzhanov::MoreAndLess::operator()(int num)
{
  prev_num_ = now_num_;
  now_num_ = next_num_;
  next_num_ = num;
  const size_t max_s = std::numeric_limits< size_t >::max();

  if ((prev_num_ > now_num_) && (next_num_ < now_num_))
  {
    if (count_ == max_s)
    {
      throw std::logic_error("Sequence is too long!");
    }
    count_++;
  }
}

size_t vyzhanov::MoreAndLess::operator()() const
{
  return count_;
}
