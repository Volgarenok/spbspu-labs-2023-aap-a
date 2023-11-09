#include "makestaticmatrix.h"

bool gladyshev::goStaticMatrix(std::fstream& input, int matrix[100][100], size_t& cols, size_t& rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (!input)
      {
        return 0;
      }
      input >> matrix[i][j];
    }
  }
  return 1;
}
