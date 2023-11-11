#include "first_second_sum.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

vyzhanov::SumDup::SumDup():
  count_sum_(0),
  first_(0),
  second_(0),
  third_(0)
{}

void vyzhanov::SumDup::operator()(int num)
{
  third_ = second_;
  second_ = first_;
  first_ = num;
  const size_t max_s = std::numeric_limits< size_t >::max();
  if ((second_ > 0 && third_ > std::numeric_limits<int>::max() - second_) || (second_ < 0 && third_ < std::numeric_limits<int>::min() - second_))
  {
    throw std::logic_error("Overflow!");
  }
  if (count_sum_ == max_s)
  {
    throw std::logic_error("Sequence is too long!");
  }
  else if (count_sum_ < max_s)
  {
    if (first_ == second_ + third_)
    {
      ++count_sum_;
    }
  }
}
size_t vyzhanov::SumDup::operator()() const
{
  if (third_ == 0)
  {
    throw std::logic_error("Sequence is too short!");
  }
  return count_sum_;
}
