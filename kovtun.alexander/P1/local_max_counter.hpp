#ifndef LOCAL_MAX_COUNTER_H
#define LOCAL_MAX_COUNTER_H

#include <limits>


namespace kovtun 
{
  class LocalMaxCounter
  {
  public:
    LocalMaxCounter();
    void operator()(int);
    size_t operator()();

  private:
    size_t counter_;
  };
}


#endif