#ifndef SEQUENCEOFNUMS_HPP
#define SEQUENCEOFNUMS_HPP
#include <cstddef>
namespace arakelyan
{
  struct CounterOfNumsThatDevideByThePrev
  {
    CounterOfNumsThatDevideByThePrev();
    void operator()(int curr);
    size_t operator()() const;
  private:
    size_t count_;
    int pastNum_;
    int currentNum_;
  };
}
#endif
