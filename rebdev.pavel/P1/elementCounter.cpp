#include "elementCounter.hpp"
#include <stdexcept>

rebdev::element_counter::element_counter():
  lastElement(0),
  currentElement(0),
  counter(0)
{}

rebdev::element_counter::element_counter(int last_element, int current_element):
  lastElement(last_element),
  currentElement(currect_element),
  counter(0)
{}

void rebdev::element_counter::operator()(int next_element)
{
  if(counter <  maxSize)
  {
    counter += (lastElement > currentElement) && (currentElement > next_element);
    lastElement = currentElement;
    currentElement = next_element;
  }
  else
  {
    throw std::logic_error("there are too many elements in the sequence!");
  }
}

size_t rebdev::element_counter::operator()() const
{
  return counter;
}
