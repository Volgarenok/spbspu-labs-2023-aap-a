#include "sequence_counter.hpp"
#include <limits>
#include <stdexcept>

skuratov::MaxCounter::MaxCounter():
  max_number_(0),
  count_(0)
{}

void skuratov::MaxCounter::operator()(int number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (number > max_number_)
  {
    max_number_ = number;
    count_ = 0;
  }
  else if (max_number_ == number)
  {
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++count_;
  }
}
size_t skuratov::MaxCounter::operator()() const
{
  return count_ + 1;
}
