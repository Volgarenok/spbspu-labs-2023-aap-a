#ifndef DIFLETTERSINTWOSTRINGS_HPP
#define DIFLETTERSINTWOSTRINGS_HPP
#include <cstddef>
namespace arakelyan
{
  void differentLetters(const char *inputArr, const char *defaultArray, char *answer);
  void findAndPasteDiffSymb(const char *array, char *answer, size_t &freePos);
}
#endif
