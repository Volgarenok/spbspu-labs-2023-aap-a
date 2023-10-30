#include "locmax.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax(size_t behindInt,size_t curInt):
  curNum(curInt),
  behindNum(behindInt),
  kount(0)
{}



void shabalin::LocMax::operator()(size_t nextNum)
{
  if (curNum > nextNum && curNum > behindNum)
  {
    ++kount;
  }
  behindNum = curNum;
  curNum = nextNum;
};

size_t shabalin::LocMax::operator()() const
{
  return kount;
};