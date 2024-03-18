#include "workWithArray.hpp"
#include <cstddef>
#include "shape.hpp"

agarkov::Shape** agarkov::expandArray(agarkov::Shape** array, size_t capacity, size_t buf)
{
  agarkov::Shape** expanded_array = nullptr;
  try
  {
    agarkov::Shape** expanded_array = new agarkov::Shape*[capacity + buf];
    for (size_t i = 0; i < capacity; i++)
    {
      expanded_array[i] = array[i];
    }
    return expanded_array;
  }
  catch (...)
  {
    delete expanded_array;
    return expanded_array;
    throw;
  }
}

void agarkov::deleteArray(agarkov::Shape** array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete array[i];
  }
  delete[] array;
}
