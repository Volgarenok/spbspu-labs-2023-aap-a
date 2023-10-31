#include "pyth_triples_counter.hpp"
#include <limits>
#include <stdexcept>

erohin::PythTriplesCounter::PythTriplesCounter():
  number_(0),
  pythtriple_(0),
  prev_(0),
  pre_prev_(0)
{}

void erohin::PythTriplesCounter::operator()(int current)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (number_ == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  ++number_;
  if (number_ > 2 && isPythTriple(current))
  {
    ++pythtriple_;
  }
  pre_prev_ = prev_;
  prev_ = current;
}

bool erohin::PythTriplesCounter::isPythTriple(int current)
{
  size_t a = pre_prev_;
  size_t b = prev_;
  size_t c = current;
  if ((a * a + b * b) == c * c)
  {
    return true;
  }
  else
  {
    return false;
  }
}

size_t erohin::PythTriplesCounter::operator()() const
{
  return pythtriple_;
}
