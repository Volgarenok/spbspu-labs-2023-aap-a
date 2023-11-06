#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>

void  checkArgs(int argc,int n)
{
  if (argc != 4)
  {
    throw (std::invalid_argument("Must be 3 arguments: task, input_file, output_file"));
  }
  if ((n < 1) || (n > 2))
  {
    throw (std::invalid_argument("first argument out of range"));
  }
}

void sMatrix (std::istream & in, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    if(!(in >> a[i]))
    {
      throw (std::logic_error("Unable to create matrix"));
    }
  }
}

void dMatrix (std::istream & in, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    if(!(in >> a[i]))
    {
      delete [] a;
      throw (std::logic_error("Unable to create matrix"));
    }
  }
}

void matrixSubtraction(int * original, int * reverse, int n)
{
  for (int i = 0; i < n; i++)
  {
    original[i] -= reverse[i];
  }
}

void clockwise(int * a, int rows, int columns)
{
  int num = 1;
  for (int delta = 0; delta < std::max(rows - 2, 1); delta++)
  {
    for (int i = (rows-1)*columns - delta*(columns-1); i > delta*(columns+1); i-=columns)
    {
      a[i] = num++;
    }
    for (int i  = 0 + delta*(columns+1); i < columns + delta*(columns-1); i+=1)
    {
      a[i] = num++;
    }
    --num;
    for (int i  = (columns-1) + delta*(columns-1); i < rows*columns - delta*(columns+1) - 1; i+=columns)
    {
      a[i] = num++;
    }
    for (int i  = rows*columns - 1 - delta*(columns+1); i > (rows-1) * columns - delta*(columns-1); i-=1)
    {
      a[i] = num++;
    }
  }
}

int main(int argc, char * argv[])
{
  int rows = 0;
  int columns = 0;
  int n = 0;
  try
  {
    n = std::stoll(argv[1]);
    checkArgs(argc, n);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }

  std::fstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Unable to read input file";
    return 2;
  }

  std::fstream output(argv[3]);
   if (!(output))
  {
    std::cerr << "Unable to read output file";
  }

  input >> rows;
  input >> columns;

  if (n == 1)
  {
    try
    {
      int matrix[rows * columns] = {};
      sMatrix(input, matrix, rows*columns);
      int clock_matrix[rows*columns];
      clockwise(clock_matrix, rows, columns);
      matrixSubtraction(matrix, clock_matrix, rows*columns);
      for (int i = 0; i < columns*rows; i++)
      {
        output << matrix[i] << " ";
      }
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
  else if (n == 2)
  {
    try
    {
      int * matrix = new int[rows*columns];
      dMatrix (input, matrix, rows*columns);
      int clock_matrix[rows*columns];
      clockwise(clock_matrix, rows, columns);
      matrixSubtraction(matrix, clock_matrix, rows*columns);
      for (int i = 0; i < columns*rows; i++)
      {
        output << matrix[i] << " ";
      }
      delete [] matrix;
    }
    catch(const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
}
