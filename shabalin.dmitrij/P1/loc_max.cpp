#include "loc_max.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax():
  m_firstNumber(0),
  m_secondNumber(0),
  m_thirdNumber(0),
  count_(0)
{}

void shabalin::LocMax::operator()(long long Number)
{
  while (m_firstNumber == 0|| m_secondNumber == 0)
  {
    m_firstNumber = Number;
    m_secondNumber = Number;
  }
  m_thirdNumber = Number;
  size_t max_size = std::numeric_limits< size_t >::max();
  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long\n");
  }
  else if (m_secondNumber > m_thirdNumber && m_secondNumber > m_firstNumber)
  {
    ++count_;
  }
  m_firstNumber = m_secondNumber;
  m_secondNumber = m_thirdNumber;
}

size_t shabalin::LocMax::operator()() const
{
  return count_;
};
