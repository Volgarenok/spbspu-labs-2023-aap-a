#include "loc_max.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax():
  m_firstNumber(0),
  m_secondNumber(0),
  count_(0)
{}

void shabalin::LocMax::operator()(long long Number)
{
  if (m_firstNumber == 0)
  {
    m_firstNumber = Number;
    if (m_firstNumber == 0)
    {
      throw std::logic_error("is not sequence");
    }
  }
  else if (m_secondNumber == 0)
  {
    m_secondNumber = Number;
  }

  size_t max_size = std::numeric_limits< size_t >::max();

  if (count_ == max_size)
  {
    throw std::logic_error("Sequence is too long");
  }
  else if (m_secondNumber > Number && m_secondNumber > m_firstNumber)
  {
    ++count_;x
  }
  m_firstNumber = m_secondNumber;
  m_secondNumber = Number;
}

size_t shabalin::LocMax::operator()() const
{
  return count_;
};
