#include <iostream>
#include <fstream>
#include <exception>

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
    if(!(in >> a[i]))
    {
      delete [] a;
    }
  }
}

void checkArgs(int argc, char * argv[], int n, std::fstream & in)
{
  if (argc != 4) 
  {
    throw (std::invalid_argument("Must be 3 arguments: task, input_file, output_file"));
  }
  if ((n < 1) || (n > 2))
  {
    throw (std::invalid_argument("first arguments out of range"));
  }
  if (!in)
  {
    throw (std::logic_error("Unable to read input file"));
  }

}


int main(int argc, char * argv[])
{
  std::fstream input(argv[2]);

  int n = 0;
  try 
  {
    n = std::stoll(argv[1]);
    checkArgs(argc, argv, n, input);
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
  
  int rows = 0;
  int columns = 0;
  input >> rows;
  input >> columns;

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
    return 1;
  }

}
