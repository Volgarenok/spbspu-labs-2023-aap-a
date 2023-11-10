#include "makestaticmatrix.h"

int gladyshev::goStaticMatrix(std::fstream& input, int matrix[100][100], size_t& cols, size_t& rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (!input.eof())
      {
        if (!input)
        {
          std::cerr << "Bad matrix\n";
          return 2;
        }
      }
      else
      {
        std::cerr << "Lack of data\n";
        return 2;
      }
      input >> matrix[i][j];
    }
  }
  return 2;
}
