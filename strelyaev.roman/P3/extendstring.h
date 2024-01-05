#ifndef EXTENDSTRING_H
#define EXTENDSTRING_H
#include <cstddef>
#include <cctype>
#include <iostream>
namespace strelyaev
{
  char * extendString(char *, size_t, std::istream &);
  int checkRepDgt(char *);
}
#endif
