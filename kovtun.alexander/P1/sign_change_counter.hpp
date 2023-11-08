#ifndef SIGN_CHANGE_COUNTER_H
#define SIGN_CHANGE_COUNTER_H

#include <limits>


namespace kovtun
{
  class SignChangeCounter
  {
  public:
    SignChangeCounter();

  private:
    size_t counter_;
    int previousNumber_;
  };
}


#endif