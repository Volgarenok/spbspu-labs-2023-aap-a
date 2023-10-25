#ifndef EVEN_COUNTER
#define EVEN_COUNTER

namespace isaychev
{
  class Even_counter
  {
    unsigned long long int count_;
    unsigned long long int max_count_;

  public:
    Even_counter();
    void operator()(int c_num);
    unsigned long long int operator()() const;
  };
}

#endif 
