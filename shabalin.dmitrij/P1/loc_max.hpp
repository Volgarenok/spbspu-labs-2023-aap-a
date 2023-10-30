#ifndef LOC_MAX_HPP
#define LOC_MAX_HPP
#include <cstddef>
namespace shabalin
{
  class LocMax
  {
  public:
    LocMax(size_t behindInt,size_t curInt,size_t nextInt);
    void operator()(size_t Number);
    void SequenceCounter(size_t lenght);
    size_t operator()() const;
    size_t behindNum;
    size_t curNum;
    size_t nextNum;
  private:
    size_t kount;
  };
}
#endif