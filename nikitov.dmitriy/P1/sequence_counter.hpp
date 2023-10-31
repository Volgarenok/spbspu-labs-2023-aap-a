#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace nikitov {
  class SequenceCounter
  {
  public:
    SequenceCounter();
    void operator()(int);
    size_t operator()() const;

  private:
    size_t count_;
  };
}
#endif
