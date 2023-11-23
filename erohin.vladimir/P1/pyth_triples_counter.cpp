#include "pyth_triples_counter.hpp"
#include <limits>
#include <stdexcept>

erohin::PythTriplesCounter::PythTriplesCounter():
  pythtriples_(0),
  prev_(0),
  pre_prev_(0)
{}

void erohin::PythTriplesCounter::operator()(int current)
{
  if (pre_prev_ != 0 && prev_ != 0 && isPythTriple(current))
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (pythtriples_ == max_size)
    {
      throw std::logic_error("There are too many pythagorean triples");
    }
    ++pythtriples_;
  }
  pre_prev_ = prev_;
  prev_ = current;
}

bool erohin::PythTriplesCounter::isPythTriple(int current)
{
  int a = pre_prev_;
  int b = prev_;
  int c = current;
  return ((a * a + b * b) == c * c);
}

size_t erohin::PythTriplesCounter::operator()() const
{
  return pythtriples_;
}
