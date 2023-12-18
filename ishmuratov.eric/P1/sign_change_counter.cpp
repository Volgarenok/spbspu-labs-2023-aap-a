#include "sign_change_counter.hpp"

#include <limits>
#include <stdexcept>

ishmuratov::SignChangeCounter::SignChangeCounter():
  change_count_(0),
  prev_num_(0),
  cur_num_(0)
{}

void ishmuratov::SignChangeCounter::operator()(long long int num)
{
  prev_num_ = cur_num_;
  cur_num_ = num;
  if (((prev_num_ > 0) && (cur_num_ < 0)) || ((prev_num_ < 0) && (cur_num_ > 0)))
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (change_count_ == max_size)
    {
      throw std::logic_error("Sequence is too long!");
    }
    ++change_count_;
  }
}

size_t ishmuratov::SignChangeCounter::operator()() const
{
  return change_count_;
}
