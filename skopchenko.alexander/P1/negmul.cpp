#include "negmul.hpp"
#include <limits>
#include <stdexcept>
#include <cmath>

skopchenko::NegMul::NegMul():
  count_(0),
  maximum_(0),
  maxresult_(0),
  result_(1)
{}

void skopchenko::NegMul::operator()(int current)
{
  if (current < 0)
  {
    size_t max_count = std::numeric_limits<size_t>::max();
    if (count_ > 0)
    {
      if (count_ == max_count)
      {
        throw std::logic_error("maximum sequence length exceeded");
      }
      else
      {
        count_++;
        double max_multiply = (std::numeric_limits< int >::max()) / result_;
        if (abs(max_multiply) > abs(current))
        {
          result_ = result_ * current;
        }
        else
        {
          throw std::logic_error("maximum multiplication reached");
        }
      }
    }
    else
    {
      count_ = 1;
      result_ = current;
    }
  }
  if (maximum_ < count_)
  {
    maximum_ = count_;
    maxresult_ = result_;
  }
}

int skopchenko::NegMul::operator()() const
{
  return maxresult_;
}
