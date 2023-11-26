#include "composition.hpp"
#include <iostream>

using namespace vyzhanov;
using namespace std;

void SequenceSpec::operator()(int num)
{
  count(num);
  sum(num);
  moreless(num);
}
size_t SequenceSpec::counter() const
{
  return count();
}
size_t SequenceSpec::sum1() const
{
  return sum();
}
size_t SequenceSpec::moreLess() const
{
  return moreless();
}
