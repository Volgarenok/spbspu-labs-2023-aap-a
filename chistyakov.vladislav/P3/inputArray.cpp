#include "inputArray.hpp"
#include "enlargeArray.hpp"

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
        array = enlargeArray(array, size);
      }
      catch(const std::exception & e)
      {
        delete[] array;
        in >> std::skipws;
        throw e.what();
      }

      size += 10;
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
