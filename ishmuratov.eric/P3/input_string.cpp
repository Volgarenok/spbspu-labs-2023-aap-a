#include "input_string.hpp"
#include <stdexcept>

char * ishmuratov::inputString(std::istream& input)
{
  size_t str_size = 10;
  size_t count = 0;
  char * initialArray = new char[str_size];
  char curr_char = 0;
  input >> std::noskipws;
  while ((input >> curr_char) && (curr_char != '\n'))
  {
    initialArray[count] = curr_char;
    count += 1;
    if (count == str_size)
    {
      try
      {
        str_size += 10;
        char * newArray = new char[str_size];
        for (size_t i = 0; i < str_size - 10; ++i)
        {
          newArray[i] = initialArray[i];
        }
        delete [] initialArray;
        initialArray = newArray;
      }
      catch (const std::bad_alloc& e)
      {
        input >> std::skipws;
        delete [] initialArray;
        throw;
      }
    }
  }
  initialArray[count] = '\0';
  input >> std::skipws;
  return initialArray;
}
