#include "reading_a_string.hpp"

char * resizeStringBuffer(const char * my_string, const size_t size, const size_t new_memory)
{
  try
  {
    char * result = new char[new_memory] {};

    std::copy(my_string, my_string + size, result);

    return result;
  }
  catch (const std::bad_alloc & e)
  {
    throw e;
  }
}

char * inputString(std::istream& input)
{
  const size_t size_of_memory = 20;
  size_t string_size = size_of_memory;
  char * string = new char[size_of_memory] {};
  char c;
  size_t i = 0;

  input >> std::noskipws;

  while ((input >> c) && c != '\n')
  {
    if (i > string_size)
    {
      try
      {
        string = resizeStringBuffer(string, string_size, string_size + size_of_memory);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] string;
        throw e;
      }
      string_size += size_of_memory;
    }
    string[i++] = c;
  }

  input >> std::skipws;
  return string;
}
