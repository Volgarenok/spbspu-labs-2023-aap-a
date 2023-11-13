#ifndef SEQUENCEOFNUMS_HPP
#define SEQUENCEOFNUMS_HPP
#include <cstddef>
namespace arakelyan
{
  struct CounterOfNumsThatDevideByThePrev
  {
    CounterOfNumsThatDevideByThePrev();
    void counterOfSequence(int curr);
    void chekZeroSequence(size_t curr);
    size_t get_count() const;
  private:
    size_t count_;
    int pastNum_;
    size_t length_;
    int currentNum_;
  };
}
#endif
