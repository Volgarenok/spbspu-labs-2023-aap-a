#ifndef COUNTERREVERSAL_H
#define COUNTERREVERSAL_H

namespace gladyshev
{
  struct CounterReversal
  {
    CounterReversal();
    void operator()(long long int number_);
    unsigned long long int operator()() const;
  public:
    unsigned long long counter_sign_;
  private:
    long long int number_;
    long long int sup_number_;
  };
}
#endif
