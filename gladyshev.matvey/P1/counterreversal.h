#ifndef COUNTERREVERSAL_H
#define COUNTERREVERSAL_H

#include <cstddef>

namespace gladyshev
{
  struct CounterReversal
  {
  public:
    CounterReversal();
    void operator()(long long int number_);
    size_t operator()() const;
    size_t counter_sign_;
  private:
    long long int number_;
    long long int sup_number_;
  };
}
#endif
