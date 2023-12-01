#include "composition.hpp"

void vyzhanov::SequenceSpec::operator()(int num)
{
  count(num);
  sum(num);
  moreless(num);
}

size_t vyzhanov::SequenceSpec::counter() const
{
  return count();
}
size_t vyzhanov::SequenceSpec::sum1() const
{
  return sum();
}
size_t vyzhanov::SequenceSpec::moreLess() const
{
  return moreless();
}
