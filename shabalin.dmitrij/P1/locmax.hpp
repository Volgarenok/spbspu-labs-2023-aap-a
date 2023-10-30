#ifndef LOCMAX_HPP
#define LOCMAX_HPP
#include <cstddef>

namespace shabalin
{
struct LocMax
{ 
  LocMax(size_t BehindInt, size_t CurInt);
  void count(size_t nextNum);
  void SequenceCounter(size_t lenght);
  size_t get_result();
  size_t curNum;
  size_t behindNum;
private:
  size_t kount;
}; 
}
#endif