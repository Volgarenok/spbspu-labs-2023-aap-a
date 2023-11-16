#include "countmax.hpp"
#include <stdexcept>
#include <limits>


skopchenko::CountMax::CountMax():
  max_(0),
  count_(1)
{}

void skopchenko::CountMax::operator()(int current)
{
  if (!max_)
  {
    max_ = current;
  }
  else if (current > max_)
  {
    max_ = current;
    count_ = 1;
  }
  else if (current == max_)
  {
    size_t max_size = std::numeric_limits< size_t >::max();

    if (count_ == max_size)
    {
      throw std::logic_error("maximum sequence lenght exceeded");
    }
    else
    {
      count_++;
    }
  }
}

size_t skopchenko::CountMax::operator()() const
{
  return count_;
}
