#include "sequence.hpp"
#include <limits>
#include <stdexcept>

marishin::QuantitySumOfThePreviousTwo::QuantitySumOfThePreviousTwo():
  prev1_(0),
  prev2_(0),
  prev3_(0),
  count_(0)
{}

void marishin::QuantitySumOfThePreviousTwo::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  long long int sum_of_two = std::numeric_limits< long long int >::max();
  if (count_ > max_size)
  {
    throw std::logic_error("sequence is too long");
  }
  if ((prev2_ + prev3_) > sum_of_two)
  {
    throw std::logic_error("overflow");
  }
  if ((num == 0) && (prev3_ == 0))
  {
    throw std::logic_error("sequence is too short");
  }
  else
  {
    prev3_ = prev2_;
    prev2_ = prev1_;
    prev1_ = num;
    if ((prev3_ != 0) && (prev1_ == (prev2_ + prev3_)))
    {
      ++count_;
    }
  }
}
size_t marishin::QuantitySumOfThePreviousTwo::operator()() const
{
  return count_;
}
