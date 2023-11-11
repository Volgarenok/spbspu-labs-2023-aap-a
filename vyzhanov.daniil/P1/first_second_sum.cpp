#include "first_second_sum.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

vyzhanov::SumDup::SumDup():
  count_sum_(0),
  num1_(0),
  num2_(0),
  num3_(0)
{}

void vyzhanov::SumDup::operator()(int num)
{
  num3_ = num2_;
  num2_ = num1_;
  num1_ = num;
  const size_t max_s = std::numeric_limits< size_t >::max();
  if ((num2_ > 0 && num3_ > std::numeric_limits<int>::max() - num2_)  || (num2_ < 0 && num3_ < std::numeric_limits<int>::min() - num2_))
  {
    throw std::logic_error("Overflow!");
  }
  if (count_sum_ == max_s)
  {
    throw std::logic_error("Sequence is too long!");
  }
  else if (count_sum_ < max_s)
  {
    if (num1_ == num2_ + num3_)
    {
      ++count_sum_;
    }
  }
}
size_t vyzhanov::SumDup::operator()() const
{
  if (num3_ == 0)
  {
    throw std::logic_error("Sequence is too short!");
  }
  return count_sum_;
}
