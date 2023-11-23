#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <fstream>
#include <cstddef>
#include <exception>

namespace zakozhurnikova
{
  int rightArguments(int argc, const char** argv);
  void writeToFile(std::ofstream& out, int *matrix, size_t rows, size_t cols);
}


#endif
