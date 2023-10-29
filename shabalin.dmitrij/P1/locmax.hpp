#ifndef LOCMAX_HPP
#define LOCMAX_HPP
#include <cstddef>

namespace shabalin
{
class LocMax
{ 
  public:
   LocMax(size_t BehindInt, size_t CurInt);
   void count_(size_t);
   void SequenceCounter(size_t lenght);
   size_t get_result() const;
  private:
    size_t kount;
    size_t firstNum;
    size_t curNum;
    size_t nextNum;
  }; 
}
#endif
