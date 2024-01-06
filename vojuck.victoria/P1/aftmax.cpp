#include "aftmax.hpp"
#include <stdexcept>

vojuck::counterAftMax::counterAftMax():
   count_(0)
{}

void vojuck::counterAftMax::operator()(int num, int &maxElement)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long =(((((");
  }
  if (maxElement < num)
  {
    count_ = 0;
    maxElement = num;
  }
  else
  {
    ++count_;
  }
}

size_t vojuck::counterAftMax::operator()() const
{
  return count_;
}
