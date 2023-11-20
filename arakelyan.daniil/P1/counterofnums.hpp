#ifndef SEQUENCEOFNUMS_HPP
#define SEQUENCEOFNUMS_HPP
#include <cstddef>
namespace arakelyan
{
  struct CounterOfNumsThatDevideByThePrev
  {
    CounterOfNumsThatDevideByThePrev();
    void counterOfSequence(int curr);
    size_t getCount() const;
  private:
    size_t count_;
    int pastNum_;
  };
}
#endif
