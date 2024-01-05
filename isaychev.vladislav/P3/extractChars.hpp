#ifndef EXTRACTCHARS_HPP
#define EXTRACTCHARS_HPP

#include <cstddef>

namespace isaychev
{
  void extractChars(const char * str_base, const char * str_sec, char * wk_str);
  size_t checkForSameElem(const char * str1, const char * str2, size_t arrayIndex);
}

#endif
