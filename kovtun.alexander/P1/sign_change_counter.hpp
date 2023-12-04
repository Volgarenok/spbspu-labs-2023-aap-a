#ifndef SIGN_CHANGE_COUNTER_H
#define SIGN_CHANGE_COUNTER_H

#include <cstddef>
#include <limits>
#include <stdexcept>


namespace kovtun
{
  class SignChangeCounter
  {
  public:
    SignChangeCounter();
    void operator()(int);
    const size_t operator()();

  private:
    size_t counter_;
    int previousNumber_;
  };
}


#endif
