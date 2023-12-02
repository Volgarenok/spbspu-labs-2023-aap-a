#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <fstream>
#include <cstddef>
#include <exception>
#include <string>

namespace zakozhurnikova
{
  int checkArguments(int argc, const char **const argv);
  void writeToFile(std::ofstream& out, int *matrix, size_t rows, size_t cols);
}
#endif
