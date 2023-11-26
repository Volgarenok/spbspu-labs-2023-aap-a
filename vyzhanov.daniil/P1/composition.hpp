#ifndef COMPOSITION_HPP
#define COMPOSITION_HPP

#include "sequence_counter.hpp"
#include "first_second_sum.hpp"
#include "more_less_check.hpp"

namespace vyzhanov
{
  class SequenceSpec
  {
    CountAfterMax count;
    SumDup sum;
    MoreAndLess moreless;
    public:
      void operator()(int num);
      size_t counter() const;
      size_t sum1() const;
      size_t moreLess() const;
   };
}
#endif
