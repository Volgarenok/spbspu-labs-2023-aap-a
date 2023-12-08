#include "sumdup.hpp"
#include <limits>
#include <stdexcept>

marishin::SumDup::SumDup():
  prev1_(0),
  prev2_(0),
  prev3_(0),
  count_(0)
{}

void marishin::SumDup::operator()(long long int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  prev3_ = prev2_;
  prev2_ = prev1_;
  prev1_ = num;
  if ((prev2_ > 0 && prev3_ > std::numeric_limits< long long int >::max() - prev2_)
    || (prev2_ < 0 && prev3_ < std::numeric_limits< long long int >::min() - prev2_))
  {
    throw std::logic_error("overflow");
  }
  else if ((prev3_ != 0) && (prev1_ == (prev2_ + prev3_)))
  {
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++count_;
  }
}
size_t marishin::SumDup::operator()() const
{
  if (prev1_ == 0)
  {
    throw std::logic_error("empty sequence");
  }
  else if (prev2_ == 0)
  {
    throw std::logic_error("one number is not enough");
  }
  else if (prev3_ == 0)
  {
    throw std::logic_error("two numbers is not enough");
  }
  else
  {
    return count_;
  }
}
