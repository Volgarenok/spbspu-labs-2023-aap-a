#include "inputString.hpp"

char * vojuck::inputString(std::istream& input, int& size)
{
  char * array = new char[size]{'\0'};
  char * new_array = nullptr;
  char c = 0;
  int i = 0;
  while (input >> c)
  {
    if (!input)
    {
      delete [] array;
      throw std::logic_error("input error");
    }
    array[i++] = c;
    if ((c == '\n') || (c == '\0'))
    {
      if (i == 1)
      {
        delete [] array;
        throw std::logic_error("the string is empty\n");
      }
      array[i - 1] = '\0';
      break;
    }
    if (i == (size - 1))
    {
      int  new_size = size + 20;
      try
      {
        new_array = new char[new_size]{};
        for (int j = 0; j < i; j++)
        {
          new_array[j] = array[j];
        }
        delete [] array;
        array = new_array;
        size = new_size;
      }
      catch (const std::bad_alloc &e)
      {
        delete [] array;
        throw;
      }
    }
    array[i] = '\n';
  }
  return array;
}
