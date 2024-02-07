#include "almost_max.hpp"
#include <stdexcept>
#include <limits>

chernov::AlmostMax::AlmostMax():
  premax_(0),
  max_(0)
{}

void chernov::AlmostMax::operator()(int number)
{
  if (max_ == 0)
  {
    max_ = number;
    if (number == 0)
    {
      throw std::invalid_argument("Mot enough values!\n");
    }
  }
  else if (max_ > 0)
  {
    if (number > max_)
    {
      premax_ = max_;
      max_ = number;
    }
    else if (number < max_)
    {
      if (premax_ < number)
      {
        premax_ = number;
      }
    }
  }
}

int chernov::AlmostMax::operator()() const
{
  return premax_;
}
