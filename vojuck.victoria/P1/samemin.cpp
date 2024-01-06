#include "samemin.hpp"
#include <stdexcept>

vojuck::counterSameMin::counterSameMin():
  count_(1)
{}

void vojuck::counterSameMin::operator()(int num, int &minElement)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long =(((((");
  }
  if (minElement > num)
  {
    count_ = 1;
    minElement = num;
  }
  else if (minElement == num)
  {
    ++count_;
  }
}

size_t vojuck::counterSameMin::operator()() const
{
  return count_;
}

