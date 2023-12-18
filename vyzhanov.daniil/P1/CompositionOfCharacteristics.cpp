#include "CompositionOfCharacteristics.hpp"

void vyzhanov::SequenceSpec::operator()(int num)
{
  count(num);
  sum(num);
  moreless(num);
}

size_t vyzhanov::SequenceSpec::getCount() const
{
  return count();
}
size_t vyzhanov::SequenceSpec::getSum() const
{
  return sum();
}
size_t vyzhanov::SequenceSpec::checkMoreLess() const
{
  return moreless();
}
