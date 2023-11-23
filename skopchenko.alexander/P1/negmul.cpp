#include "negmul.hpp"
#include <limits>
#include <stdexcept>
#include <cmath>

skopchenko::NegMul::NegMul():
  prevNum_(0),
  count_(1),
  maximum_(0),
  maxresult_(0),
  result_(1)
{}

void skopchenko::NegMul::operator()(int current)
{
  if (current < 0 && prevNum_ < 0)
  {
    size_t max_count = std::numeric_limits< size_t >::max();
    if (count_ == max_count)
    {
      throw std::logic_error("maximum sequence length exceeded");
    }
    else
    {
      count_++;
      int max_multiply = std::numeric_limits< int >::max();
      int min_multiply = std::numeric_limits< int >::min();
      if (max_multiply / result_ > current || min_multiply / result_ > current)
      {
        result_ = result_ * current;
      }
      else
      {
        throw std::logic_error("maximum multiplication size exceeded");
      }
      if (maximum_ < count_)
      {
        maximum_ = count_;
        maxresult_ = result_;
      }
    }
  }
  else if (current < 0)
  {
    result_ = result_ * current;
    count_ = 1;
    if (maximum_ < count_)
    {
      maximum_ = count_;
      maxresult_ = result_;
    }
  }
  else
  {
    count_ = 0;
    result_ = 1;
  }
  prevNum_ = current;
}

size_t skopchenko::NegMul::operator()() const
{
  return maxresult_;
}
