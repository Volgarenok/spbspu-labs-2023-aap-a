#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <fstream>
#include <cstddef>
#include <exception>

namespace zakozhurnikova
{
  int rightArguments(int argc, char** argv);
  void createMatrixDin(int *&matrix, int rows, int cols);
  void freeMatrix(int *&matrix);
  void writeToFileDin(std::ofstream& out, int *matrix, int rows, int cols);
  void writeToFile(std::ofstream& out, int matrix[], int rows, int cols);
}


#endif
