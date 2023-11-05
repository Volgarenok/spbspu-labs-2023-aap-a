#include "sequence_count_min.hpp"
#include <stdexcept>
#include <limits>

grechishnikov::SequenceCountMin::SequenceCountMin():
  number_min_(std::numeric_limits< long long >::max()),
  number_count_(0)
{}

void grechishnikov::SequenceCountMin::operator()(long long num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (num == number_min_)
  {
    if (number_count_ == max_size)
    {
      throw std::overflow_error("sequence is too long");
    }
    number_count_ += 1;
  }
  if (num < number_min_)
  {
    number_min_ = num;
    number_count_ = 1;
  }
}

size_t grechishnikov::SequenceCountMin::operator()() const
{
  return number_count_;
}
