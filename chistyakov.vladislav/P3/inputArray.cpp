#include "inputArray.hpp"

char* chistyakov::inputArray(std::istream & in)
{
  size_t size = 50;
  char * array = new char[size]{};

  char input = 0;
  size_t i = 0;
  in >> std::noskipws;

  while ((in >> input))
  {
    if (i == size)
    {
      try
      {
        char* newArray = new char[size + 10]{};

        for (size_t i = 0; i < size; ++i)
        {
          newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
        size += 10;
      }
      catch (const std::bad_alloc &)
      {
        delete[] array;
        in >> std::skipws;
        throw;
      }
    }

    if (input == '\n')
    {
      array[i] = 0;
      break;
    }

    if (!in)
    {
      delete[] array;
      in >> std::skipws;
      throw std::invalid_argument("Bad input, maybe try again?..");
    }

    array[i++] = input;

  }

  in >> std::skipws;

  return array;
}
