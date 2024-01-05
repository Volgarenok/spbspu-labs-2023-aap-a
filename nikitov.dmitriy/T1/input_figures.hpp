#ifndef INPUT_FIGURES_HPP
#define INPUT_FIGURES_HPP

#include <iostream>
#include <string>

namespace nikitov
{
  std::string* inputFigures(std::istream& input);

  bool enterLine(std::string line, std::istream& input);

  std::string* increaseArray(std::string* figures, std::string* tempFigures, size_t size);
}
#endif
