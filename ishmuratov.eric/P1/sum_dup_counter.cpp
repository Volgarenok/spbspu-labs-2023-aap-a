#include "sum_dup_counter.hpp"

#include <limits>
#include <stdexcept>

ishmuratov::SumDupCounter::SumDupCounter():
  sum_count_(0),
  first_num_(0),
  second_num_(0),
  cur_num_(0)
{}

void ishmuratov::SumDupCounter::operator()(long long int num)
{
  first_num_ = second_num_;
  second_num_ = cur_num_;
  cur_num_ = num;
  long long int max_sum = std::numeric_limits< long long int >::max();
  long long int min_sum = std::numeric_limits< long long int >::min();
  if ((second_num_ > 0 && first_num_ > max_sum - second_num_) || (second_num_ < 0 && first_num_ < min_sum - second_num_))
  {
    throw std::logic_error("Sum overflow!");
  }
  if (cur_num_ == (first_num_ + second_num_))
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (sum_count_ == max_size)
    {
      throw std::logic_error("Sequence is too long!");
    }
    ++sum_count_;
  }
}

size_t ishmuratov::SumDupCounter::operator()() const
{
  if ((first_num_ == 0) || (second_num_ == 0) || (cur_num_ == 0))
  {
    throw std::logic_error("Sequence is too short!");
  }
  return sum_count_;
}
