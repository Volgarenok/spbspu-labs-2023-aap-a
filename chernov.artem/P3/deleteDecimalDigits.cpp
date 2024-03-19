#include "deleteDecimalDigits.hpp"
#include <cctype>
#include <cstddef>

char* chernov::removeDecimalDigits(char* input, char* stringWithDecimalDigitsRemoved, size_t sizeOfInput)
{
  size_t j = 0;
  for (size_t i = 0; (input[i] != '\0') && (i < sizeOfInput); i++)
  {
    if (!std::isdigit(input[i]))
    {
      stringWithDecimalDigitsRemoved[j] = input[i];
      j++;
    }
  }

  stringWithDecimalDigitsRemoved[j] = '\0';
  return stringWithDecimalDigitsRemoved;
}
