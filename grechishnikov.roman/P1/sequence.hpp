#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <cstddef>

namespace grechishnikov
{
  class SequenceCountMin
  {
  public:
    SequenceCountMin();
    void operator()(long long num);
    size_t operator()() const;
  private:
    size_t number_count_;
    long long number_min_;
  };
}

#endif
