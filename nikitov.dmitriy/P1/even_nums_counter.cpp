#include "even_nums_counter.hpp"
#include <limits>
#include <stdexcept>

nikitov::EvenNumsCounter::EvenNumsCounter():
  actualCount_(0),
  maxCount_(0)
{}

void nikitov::EvenNumsCounter::operator()(long long int number)
{
  if (number % 2 == 0)
  {
    size_t maxLimit = std::numeric_limits< size_t >::max();
    if (actualCount_ == maxLimit)
    {
      throw std::logic_error("This sequence it too long");
    }
    ++actualCount_;

    if (actualCount_ > maxCount_)
    {
      maxCount_ = actualCount_;
    }
  }
  else
  {
    actualCount_ = 0;
  }
}
size_t nikitov::EvenNumsCounter::operator()() const
{
  return maxCount_;
}
