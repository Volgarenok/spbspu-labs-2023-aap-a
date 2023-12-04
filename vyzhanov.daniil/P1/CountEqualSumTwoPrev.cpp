#include "CountEqualSumTwoPrev.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

vyzhanov::CountEqualSumTwoPrev::CountEqualSumTwoPrev():
  count_sum_(0),
  num1_(0),
  num2_(0),
  num3_(0)
{}

void vyzhanov::CountEqualSumTwoPrev::operator()(int num)
{
  num3_ = num2_;
  num2_ = num1_;
  num1_ = num;
  const size_t max_s = std::numeric_limits< size_t >::max();
  const int max_int = std::numeric_limits< int >::max();
  const int min_int = std::numeric_limits< int >::min();

  if ((num2_ > 0 && num3_ > max_int - num2_) || (num2_ < 0 && num3_ < min_int - num2_))
  {
    throw std::logic_error("Overflow!");
  }

  if (num1_ == num2_ + num3_)
  {
    if (count_sum_ == max_s)
    {
      throw std::logic_error("Sequence is too long!");
    }
    count_sum_++;
  }
}
size_t vyzhanov::CountEqualSumTwoPrev::operator()() const
{
  if (num3_ == 0)
  {
    throw std::logic_error("Sequence is too short!");
  }
  return count_sum_;
}
