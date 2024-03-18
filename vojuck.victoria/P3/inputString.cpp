#include "inputString.hpp"

char * vojuck::inputString(std::istream& input, char * array, int& size)
{
  char * new_array = nullptr;
  char c = 0;
  int i = 0;
  while ((input >> c) && (c != '\n'))
  {
    if (!input)
    {
      delete [] array;
      throw std::logic_error("input error");
    }
    array[i++] = c;
    if (i == (size - 1))
    {
      int  new_size = size + 20;
      try
      {
        new_array = new char[new_size]{'\0'};
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
      }
    }
    array[i] = '\n';
    if (array[0] == '\n')
    {
      delete [] array;
      throw std::logic_error("where is srting?(\n");
    }
  }
  return array;
}
