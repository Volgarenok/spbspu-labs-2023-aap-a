#include <stdexcept>
#include <fstream>

long long int readFromFileLLI (std::ifstream & inputFile)
{
  long long int num = 0;
  inputFile >> num;

  if (!inputFile)
  {
    throw std::logic_error("Reading error: can't read from file");
  }
  else if (inputFile.peek() == EOF)
  {
    inputFile.close();
    throw std::logic_error("Reading error: file is end\n");
  }

  return num;
}
