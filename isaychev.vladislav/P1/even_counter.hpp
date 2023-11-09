#ifndef EVEN_COUNTER_HPP
#define EVEN_COUNTER_HPP

namespace isaychev
{
  struct EvenCounter
  {
    EvenCounter();
    void operator()(int c_num);
    unsigned long long int operator()() const;

  private:
    unsigned long long int count_;
    unsigned long long int max_count_;
  };
}

#endif
