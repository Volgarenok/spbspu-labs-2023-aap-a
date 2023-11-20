#ifndef LOCAL_MIN_COUNTER_HPP
#define LOCAL_MIN_COUNTER_HPP

#include <cstddef>
namespace namestnikov
{
  struct LocalMinCounter
  {
    LocalMinCounter();
    void operator()(int futureNumber);
    size_t operator()() const;
  private:
    size_t count_;
    int lastNumber_;
    int currentNumber_;
  };
}
#endif
