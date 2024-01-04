#ifndef INPUT_H
#define INPUT_H
#include <cstddef>
#include <istream>

namespace zaitsev
{
  char* readStr(std::istream& input);
  void resizeStr(char** str, size_t old_size, size_t new_size);
}
#endif
