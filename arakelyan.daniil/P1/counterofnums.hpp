#ifndef SEQUENCEOFNUMS_HPP
#define SEQUENCEOFNUMS_HPP
#include <cstddef>
namespace arakelyan
{
  struct CounterOfNums
  {
    CounterOfNums();
    void counter(int curr,int past);
    size_t get_count() const;
  private:
    size_t count_;
    size_t length_;
  };
}
#endif
