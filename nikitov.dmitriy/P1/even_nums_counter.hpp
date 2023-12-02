#ifndef EVEN_NUMS_COUNTER_HPP
#define EVEN_NUMS_COUNTER_HPP

#include <cstddef>
namespace nikitov
{
  class EvenNumsCounter
  {
  public:
    EvenNumsCounter();
    void operator()(long long int number);
    size_t operator()() const;

  private:
    size_t actualCount_;
    size_t maxCount_;
  };
}
#endif
