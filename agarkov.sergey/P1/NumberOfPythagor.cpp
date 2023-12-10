#include "NumberOfPythagor.hpp"
#include <limits>
#include <stdexcept>

agarkov::NumberOfPythagor::NumberOfPythagor():
  triples_(0),
  p_(0),
  p_t_(0)
{}

void agarkov::NumberOfPythagor::operator()(int current)
{
  if (p_t_ != 0 && p_ != 0 && isPythTriple(current))
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (triples_ == max_size)
    {
      throw std::logic_error("Limit of triplets exceeded");
    }
    ++triples_;
  }
  p_t_ = p_;
  p_ = current;
}

bool agarkov::NumberOfPythagor::isPythTriple(int current)
{
  int x = p_t_;
  int y = p_;
  int z = current;
  return ((x * x + y * y) == z * z);
}

size_t agarkov::NumberOfPythagor::operator()() const
{
  return triples_;
}
