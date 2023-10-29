#include "locmax.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax(size_t BehindInt, size_t CurInt):
  firstNum(BehindInt),
  curNum(CurInt),
  nextNum(1),
  kount(0)
{}

void shabalin::LocMax::SequenceCounter(size_t lenght)
{
  size_t max_size = std::numeric_limits<size_t>::max();
    if (lenght == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
}

void shabalin::LocMax::count_(size_t number)
{
  if (curNum > nextNum && curNum > firstNum)
  {
    ++kount; 
  }
  firstNum = curNum;
  curNum = nextNum;
}
  size_t shabalin::LocMax::get_result() const
  {
    return kount; 
  }
