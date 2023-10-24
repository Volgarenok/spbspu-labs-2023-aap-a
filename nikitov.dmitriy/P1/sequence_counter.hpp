#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace nikitov {
  struct SequenceCounter
  {
    SequenceCounter();
    void operator()(int);
    size_t operator()();
  private:
      size_t count_;
  };
}
#endif
