#ifndef SEQUENCECOUNTMIN_HPP
#define SEQUENCECOUNTMIN_HPP

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
    long long number_min_;
    size_t number_count_;
  };
}

#endif
