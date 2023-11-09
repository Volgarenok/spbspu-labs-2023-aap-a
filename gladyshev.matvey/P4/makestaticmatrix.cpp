#include "makestaticmatrix.h"

void gladyshev::goStaticMatrix(std::fstream& input, int matrix[100][100], size_t& cols, size_t& rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (!input)
      {
        std::cerr << "Can not read a matrix\n";
        exit(1);
      }
      input >> matrix[i][j];
    }
  }
}
