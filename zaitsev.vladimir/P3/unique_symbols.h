#ifndef UNIQUE_SYMBOLS_H
#define UNIQUE_SYMBOLS_H
#include <cstddef>

namespace zaitsev
{
  char* uniqueChars(const char* str1, const char* str2);
  int isCharInStr(const char* str, char c);
  void addUnique(const char* basic_str, const char* comp_str, char** res_str, size_t* capacity, size_t* size);
}
#endif
