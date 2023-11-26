#include <fstream>

#include "readTheArray.h"
#include "matrix.h"

namespace skuratov
{
  void readMatrixSizeFromFile(size_t& width, size_t& height, const std::string& fileName)
  {
    std::ifstream is(fileName);
    is >> width >> height;
    if (!is)
    {
      throw std::runtime_error("Can't read matrix size");
    }
  }
  void readMatrixFromFile(int* mat, size_t matrixArea, const std::string& fileName)
  {
    size_t width = 0;
    size_t height = 0;
    std::ifstream is(fileName);
    is >> width >> height;
    readTheArray(is, matrixArea, mat);
    if (!is)
    {
      throw std::runtime_error("Can't read matrix from the file");
    }
  }
  void writeMatrixToFile(const int* mat, size_t width, size_t height, const std::string& fileName)
  {
    std::ofstream os(fileName);
    os << width << " " << height;
    const size_t matrixArea = width * height;
    for (size_t i = 0; i < matrixArea; ++i)
    {
      os << " " << mat[i];
    }
    if (!os)
    {
      throw std::runtime_error("Can't write matrix to the file");
    }
  }
}
