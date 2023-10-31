#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <cstddef>
namespace marishin
{
  class QuantitySumOfThePreviousTwo
  {
  public:
    QuantitySumOfThePreviousTwo();
    void operator()(int num);
    size_t operator()() const;
  private:
    long long int prev1_;
    long long int prev2_;
    long long int prev3_;
    size_t count_;
  };
}
#endif
