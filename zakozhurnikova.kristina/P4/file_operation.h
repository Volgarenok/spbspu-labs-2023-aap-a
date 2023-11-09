#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <fstream>
#include <cstddef>

namespace zakozhurnikova
{
  int rightArguments(int argc, char** argv);
  void inputMatrix(std::ifstream& input, double* size, size_t rows, size_t cols);
}
