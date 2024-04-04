#include "inputString.hpp"
#include <stdexcept>
char * vojuck::inputString(std::istream& input)
{
  int size = 20;
  char * array = new char[size]{};
  char * new_array = nullptr;
  char c = 0;
  int i = 0;

  while ((input >> c) && (c != '\n'))
  {
    if (!input)
    {
      delete [] array;
      throw std::logic_error("no input");
    }
    array[i++] = c;
    if (i == (size - 1))
    {
      int new_size = size +20;
      try
      {
         new_array = new char [new_size];
      }
      catch(...)
      {
        delete [] new_array;
        array = nullptr;
      }
      if (array == nullptr)
      {
        std::logic_error("Unable to create buffer");
      }
      for (int j = 0; j < i; j++)
      {
        new_array[j] = array[j];
      }
      delete [] array;
      array = new_array;
      size = new_size;
    }
  }
  array[i] = '\0';
  return array;
}
