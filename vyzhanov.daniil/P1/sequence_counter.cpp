#include <limits>
#include <stdexcept>
#include "sequence_counter.hpp"

vyzhanov::SequenceCounter::SequenceCounter():
  count(0)
{
}
void vyzhanov::SequenceCounter::size(int num)
{
   size_t max_s = std::numeric_limits< size_t >::max();
    if (count == max_s)
    {
      throw  std::logic_error("Sequence is too long!\n");
    }
    ++count;
}
size_t vyzhanov::SequenceCounter::get_res() const
{
  return count;
}

