#ifndef COMPOSITION_HPP
#define COMPOSITION_HPP

#include "sequence_counter.hpp"
#include "first_second_sum.hpp"
#include "more_less_check.hpp"
#include <stdexcept>
#include <iostream>

namespace vyzhanov
{
  struct SequenceSpec
  {
    vyzhanov::CountAfterMax counter;
    vyzhanov::SumDup sum;
    vyzhanov::MoreAndLess moreless;

    void Counter(int num)
    {
      return counter(num);
    }
    void Sum(int num)
    {
      return sum(num);
    }
    void MoreLess(int num)
    {
      return moreless(num);
    }
    size_t Counter()
    {
      return counter();
    }
    size_t Sum()
    {
      return sum();
    }
    size_t MoreLess()
    {
      return moreless();
    }
  };
}

#endif
