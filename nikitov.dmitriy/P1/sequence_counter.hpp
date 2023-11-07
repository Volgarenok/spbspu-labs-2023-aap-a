#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace nikitov {
  class SequenceCounter
  {
  public:
    SequenceCounter();
    void operator()(long long int number);
    long long int operator()() const;

  private:
    long long int actualMax_;
    long long int prevMax_;
    size_t count_;
  };
}
#endif
