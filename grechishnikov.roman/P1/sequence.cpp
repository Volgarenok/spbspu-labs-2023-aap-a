#include "sequence.hpp"
#include <stdexcept>

void sequence::doCount(long long num)
{
  if (num == number_min)
  {
    sequence::changeNum();
  }
  if (num < number_min)
  {
    sequence::changeNum(num);
  }
}

void sequence::changeNum(long long num)
{
  number_min = num;
  number_count = 1;
}

void sequence::changeNum()
{
  if (number_count == max_length)
  {
    throw std::overflow_error("sequence is too long");
  }
  number_count += 1;
}

int sequence::getRez()
{
  return number_count;
}
