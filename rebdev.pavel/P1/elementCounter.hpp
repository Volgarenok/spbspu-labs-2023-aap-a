#ifndef ELEMENTCOUNTER_HPP
#define ELEMENTCOUNTER_HPP

#include <iostream>
#include <limits>

namespace rebdev
{
  class element_counter
  {
  public:
    element_counter();
    element_counter(int last_element, int current_element);
    void operator()(int next_element);
    size_t operator()() const;
  
  private:
    int lastElement;
    int currentElement;
    size_t counter;
    const size_t maxSize = std::numeric_limits< size_t >::max();
  };
}
#endif
