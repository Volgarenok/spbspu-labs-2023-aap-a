#include "frq_top.hpp"

#include <cstddef>
#include <cctype>

char * lebedev::findTopFrqSymbs(const char * string, char * symbols)
{
  size_t frq_one = 0;
  size_t frq_two = 0;
  size_t frq_three = 0;
  symbols[0] = 'A';
  symbols[1] = 'A';
  symbols[2] = 'A';
  symbols[3] = '\0';

  for (int symbol = 'A'; symbol <= 'z'; ++symbol)
  {
    if (std::isalpha(symbol))
    {
      size_t frq_current = 0;
      size_t current_index = 0;
      while (string[current_index] != '\0')
      {
        if (string[current_index] == symbol)
        {
          ++frq_current;
        }
        ++current_index;
      }
      if (frq_current > frq_one)
      {
        frq_three = frq_two;
        frq_two = frq_one;
        frq_one = frq_current;
        symbols[2] = symbols[1];
        symbols[1] = symbols[0];
        symbols[0] = symbol;
      }
      else if (frq_current > frq_two)
      {
        frq_three = frq_two;
        frq_two = frq_current;
        symbols[2] = symbols[1];
        symbols[1] = symbol;
      }
      else if (frq_current > frq_three)
      {
        frq_three = frq_current;
        symbols[2] = symbol;
      }
    }
  }
  for (size_t i = 0; i < 3; ++i)
  {
    for (size_t j = i; j < 3; ++j)
    {
      if (symbols[j] < symbols[i])
      {
        char tmp = symbols[j];
        symbols[j] = symbols[i];
        symbols[i] = tmp;
      }
    }
  }
  return symbols;
}
