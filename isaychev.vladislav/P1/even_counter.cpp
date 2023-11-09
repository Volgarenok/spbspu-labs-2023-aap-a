#include "even_counter.hpp"
#include <limits>
#include <stdexcept>

isaychev::EvenCounter::EvenCounter():
  count_(0),
  max_count_(0)
{}

void isaychev::EvenCounter::operator()(int c_num)
{
  const unsigned long long int u_border = std::numeric_limits< unsigned long long int >::max();
  if (c_num % 2 == 0)
  {
    if (count_ == u_border)
    {
      throw std::logic_error("sequence is too long");
    }
    else
    {
      ++count_;
      if (count_ > max_count_)
      {
        max_count_ = count_;
      }
    }
  }
  else if (c_num % 2 != 0)
  {
    count_ = 0;
  }
}

unsigned long long int isaychev::EvenCounter::operator()() const
{
  return max_count_;
}
