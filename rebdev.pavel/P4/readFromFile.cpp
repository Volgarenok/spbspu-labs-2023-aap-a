#include "readFromFile.hpp"
#include <stdexcept>
#include <fstream>

long long int rebdev::readFromFileLLI(std::ifstream & inputFile)
{
  long long int num = 0;
  inputFile >> num;

  if (!inputFile)
  {
    throw std::logic_error("Reading error: can't read from file");
  }
  else if (!inputFile.is_open())
  {
    throw std::logic_error("Reading error: file is end\n");
  }

  return num;
}
