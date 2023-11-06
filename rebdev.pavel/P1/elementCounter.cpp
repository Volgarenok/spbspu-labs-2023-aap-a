#include "elementCounter.hpp"
#include <stdexcept>
#include <limits>

rebdev::ElementCounter::ElementCounter():
  lastElement_(0),
  currentElement_(0),
  counter_(0),
  amountOfElements_(0)
{}

void rebdev::ElementCounter::operator()(int nextElement)
{
  if (nextElement != 0)
  {
    amountOfElements_ += 1;
    if (lastElement_ == 0)
    {
      lastElement_ = nextElement;
    }
    else if (currentElement_ == 0)
    {
      currentElement_ = nextElement;
    }
    else
    {
      if ((lastElement_ > currentElement_) && (currentElement_ > nextElement))
      {
        if (counter_ < std::numeric_limits< size_t >::max())
        {
          counter_ += 1;
        }
        else
        {
          throw std::logic_error("there are too many elements in the sequence!");
        }
      }
      lastElement_ = currentElement_;
      currentElement_ = nextElement;
    }
  }
}

size_t rebdev::ElementCounter::operator()() const
{
  if (amountOfElements_ < 3)
  {
    throw std::invalid_argument("there are too little elements in the sequence!");
  }
  return counter_;
}
