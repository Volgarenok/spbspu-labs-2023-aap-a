#include "mondec.h"
#include <limits>
#include <stdexcept>

strelyaev::Mondec::Mondec():
  max_counter_(0),
  new_counter_(1),
  past_number_(0)
{}

void strelyaev::Mondec::operator()(int num)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  if (past_number_ >= num)
  {
    if (new_counter_ == max_size)
    {
      throw std::logic_error("SEQUENCE IS TOO BIG");
    }
    ++new_counter_;
  }
  else
  {
    new_counter_ = 1;
  }
  past_number_ = num;
  if (new_counter_ > max_counter_)
  {
    max_counter_ = new_counter_;
  }
}

size_t strelyaev::Mondec::operator()() const
{
  return max_counter_;
}
