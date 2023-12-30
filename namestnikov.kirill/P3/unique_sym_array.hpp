#ifndef UNIQUE_SYM_ARRAY_HPP
#define UNIQUE_SYM_ARRAY_HPP
#include <cstddef>

namespace namestnikov
{
  void fillUniqueSymArray(const char * str1, const char * str2, char * result, size_t & resultIndex);
  bool isSymbolInString(const char * string, char sym);
  char * getUniqueSymArray(const char * str1, const char * str2, size_t firstSize, size_t secondSize);
}

#endif

