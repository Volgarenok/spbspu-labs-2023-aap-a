#include "loc_max.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax(size_t behindInt,size_t curInt,size_t nextInt):
  behindNum(behindInt),
  curNum(curInt),
  nextNum(nextInt),
  kount(0)
{}

void shabalin::LocMax::SequenceCounter(size_t lenght)
{
  size_t max_size = std::numeric_limits<size_t>::max();
    if (lenght == max_size)
    {
      throw std::logic_error("Sequence is too long\n");
    }
};

void shabalin::LocMax::operator()(size_t Number)
{
  nextNum = Number;
  if (curNum > Number && curNum > behindNum)
  {
    ++kount;
  }
  behindNum = curNum;
  curNum = Number;
};

size_t shabalin::LocMax::operator()() const
{
  return kount;
};
