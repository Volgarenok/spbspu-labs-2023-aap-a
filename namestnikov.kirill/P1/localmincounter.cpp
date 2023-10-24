#include "local_min_counter.hpp"
#include <limits>
#include <stdexcept>

namestnikov::LocalMinCounter::LocalMinCounter():
  count_(0)
{}

void namestnikov::LocalMinCounter::operator()(int lastnumber, int currentnumber, int futurenumber)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("sequence is too long\n");
  }
  else if ((currentnumber < lastnumber) && (currentnumber < futurenumber))
  {
    ++count_;
  }
}
size_t namestnikov::LocalMinCounter::operator()() const
{
  return count_;
}
