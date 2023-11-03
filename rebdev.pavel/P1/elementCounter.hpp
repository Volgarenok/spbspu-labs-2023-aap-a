#ifndef ELEMENTCOUNTER_HPP
#define ELEMENTCOUNTER_HPP

#include <cstddef>

namespace rebdev
{
  class ElementCounter
  {
  public:
    ElementCounter();
    void operator()(int nextElement);
    size_t operator()() const;

  private:
    int lastElement_;
    int currentElement_;
    size_t counter_;
    size_t amountOfElements_;
  };
}
#endif
