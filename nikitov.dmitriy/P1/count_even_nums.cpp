#include "count_even_nums.hpp"

void nikitov::countEvenNums(int now, size_t& max, size_t& actual)
{
  if (now % 2 == 0)
  {
    ++actual;
    if (actual > max)
    {
      max = actual;
    }
  }
  else
  {
    actual = 0;
  }
}
