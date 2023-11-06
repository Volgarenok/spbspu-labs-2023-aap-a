#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COIUNTER_HPP
#include <cstddef>
namespace stepanov
{
  struct SequenceCounter
  {
    SequenceCounter();
    void operator()(int);
    size_t operator()() const;
  private:
    size_t count_;
  };
}
#endif
