#include "loc_max.hpp"
#include <limits>
#include <stdexcept>

shabalin::LocMax::LocMax(signed long long firstInt,signed long long secondInt,signed long long thirdInt):
  m_firstNumber(firstInt),
  m_secondNumber(secondInt),
  m_thirdNumber(thirdInt),
  count_(0)
{}

void shabalin::LocMax::operator()(signed long long Number)
{
  m_firstNumber = Number;
  size_t max_size = std::numeric_limits< size_t >::max();
  if (Number == max_size)
  {
    throw std::logic_error("Sequence is too long\n");
  }
  else if (m_secondNumber > Number && m_secondNumber > m_firstNumber)
  {
    ++count_;
  }
  m_firstNumber = m_secondNumber;
  m_secondNumber = Number;
}

size_t shabalin::LocMax::operator()() const
{
  return count_;
};
