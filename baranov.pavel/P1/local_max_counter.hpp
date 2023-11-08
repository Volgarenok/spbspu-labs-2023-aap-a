#ifndef LOCAL_MAX_COUNTER_HPP
#define LOCAL_MAX_COUNTER_HPP

#include <cstddef>
namespace baranov
{
  class LocalMaxCounter
  {
  public:
    LocalMaxCounter();
    void operator()(long long int number);
    size_t operator()() const;
  private:
    long long int prevNumber_;
    long long int currentNumber_;
    long long int nextNumber_;
    size_t count_;
  };
}

#endif

