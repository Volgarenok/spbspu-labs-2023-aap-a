#include "counter.hpp"

#include <stdexcept>
#include <limits>

zhalilov::Counter::Counter():
  m_count(1),
  m_maxSeq(0)
{}

void zhalilov::Counter::operator()(const int prev, const int curr)
{
  if(curr == prev)
  {
    if(m_count == std::numeric_limits<size_t>::max())
    {
      throw std::logic_error("sequence it too long");
    }
    m_count++;
  }
  else
  {
    m_count = 1;
  }

  if(m_count > m_maxSeq)
  {
    m_maxSeq = m_count;
  }
}

size_t zhalilov::Counter::operator()() const
{
  return m_maxSeq;
}
