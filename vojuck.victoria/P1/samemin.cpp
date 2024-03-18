#include <stdexcept>
#include <limits>
#include "samemin.hpp"

constexpr int max_int = std::numeric_limits< int >::max();

vojuck::CounterSameMin::CounterSameMin():
  count_(1),
  minElement_(max_int)
{}

void vojuck::CounterSameMin::operator()(int num)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (max_size - count_ < 1)
  {
    throw std::logic_error("Sequence is too long =(((((");
  }
  if (minElement_ > num)
  {
    count_ = 1;
    minElement_ = num;
  }
  else if (minElement_ == num)
  {
    ++count_;
  }
}

size_t vojuck::CounterSameMin::operator()() const
{
  return count_;
}

