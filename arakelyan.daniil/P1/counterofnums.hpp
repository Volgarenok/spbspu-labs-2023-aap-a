#ifndef SEQUENCEOFNUMS_HPP
#define SEQUENCEOFNUMS_HPP
#include <cstddef>
namespace arakelyan
{
  struct CounterOfNums
  {
    CounterOfNums();
    void operator()(int cur);
    size_t operator()() const;
  private:
    size_t count_;
    size_t length_;
    int past_num_;
  };
}
#endif
