#ifndef STRINGMANIPULATIONS_HPP
#define STRINGMANIPULATIONS_HPP

#include <cstddef>

namespace isaychev
{
  bool checkString(const char * string, const char * strForCheck);
  size_t countWSpaces(const char * str);
  void skipParameter(char * str);
  void parseParams(char * str, size_t numOfParameters, double * parameters);
}

#endif
