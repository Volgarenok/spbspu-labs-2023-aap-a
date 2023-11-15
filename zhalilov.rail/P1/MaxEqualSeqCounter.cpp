#include "MaxEqualSeqCounter.hpp"

#include <stdexcept>
#include <limits>

zhalilov::MaxEqualSeqCounter::MaxEqualSeqCounter():
  m_count(0),
  m_maxSeq(0),
  m_accum(0)
{}

void zhalilov::MaxEqualSeqCounter::operator()(const int curr)
{
  if (curr == m_accum)
  {
    if (m_count == std::numeric_limits< size_t >::max())
    {
      throw std::logic_error("sequence it too long");
    }
    m_count++;
  }
  else
  {
    m_count = 1;
  }

  if (m_count > m_maxSeq)
  {
    m_maxSeq = m_count;
  }
  m_accum = curr;
}

size_t zhalilov::MaxEqualSeqCounter::operator()() const
{
  return m_maxSeq;
}
