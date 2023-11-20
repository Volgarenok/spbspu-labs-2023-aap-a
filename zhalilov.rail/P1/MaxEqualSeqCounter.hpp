#ifndef MAXEQUALSEQCOUNTER_HPP
#define MAXEQUALSEQCOUNTER_HPP

#include <cstddef>

namespace zhalilov
{
  class MaxEqualSeqCounter
  {
  public:
    MaxEqualSeqCounter();
    void operator()(int curr);
    size_t operator()() const;
  private:
    size_t m_count;
    size_t m_maxSeq;
    int m_accum;
  };
}
#endif
