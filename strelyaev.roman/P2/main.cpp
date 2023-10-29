#include <iostream>
#include <fstream>

void sMatrix (std::istream & in, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    in >> a[i];
  }
}

void dMatrix (std::istream & in, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    in >> a[i];
  }
}


int main(int argc, char * argv[])
{
  std::fstream input(argv[2]);


  int rows = 0;
  int columns = 0;
  int n = 0;

  input >> rows;
  input >> columns;
  try 
  {
    n = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument &)
  {
    return 3;
  }
  
  if (n == 1)
  {
    int matrix[rows * columns] = {};
    sMatrix(input, matrix, rows*columns); 
    std::cout << matrix[1 * columns + 0];
  }
  else if (n == 2)
  {
    int * matrix = new int[rows*columns];
    dMatrix (input, matrix, rows*columns);
    std::cout << matrix[1 * columns + 0];
    delete [] matrix;
  } 
  else 
  {
    return 2;
  }

}
