#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>


int main (int argc, char * argv[])
{
  //проверка кол-ва аргументов передаваем. при вызове программы
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task; name of input file; name of output file\n";
    return 1;
  }

  //проверка первого аргумента
  char * endOfParse = nullptr;
  long firstArgument = std::strtoll(argv[1],&endOfParse,10);
  if (firstArgument == 0 && endOfParse == argv[1])
  {
    std::cerr << "Cannot parse the first argument!\n";
    return 1;
  }

  if ((firstArgument < 1) || (firstArgument > 2))
  {
    std::cerr << "Number of tusk must be 1 or 2\n";
    return 1;
  }

  if (firstArgument == 1)
  {
    //файл ввода
    std::ifstream input(argv[2]);
    if (!input.is_open())
    {
      std::cerr << "Cannot open the input file\n";
      return 2;
    }

    int rows = 0;
    int cols = 0;
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Cannot read input file\n";
      return 2;
    }


    //считываю изначальную матрицу из входного файла
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        input >> matrix[i][j];
      }
    }

    input.close();

    //создаю и инициализирую сглаженную матрицу на основе имеющейся
    double smoothedMatrix[rows][cols];
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        double sum = 0.0;
        int count = 0;

        for (int x = i - 1; x <= i + 1; x++)
        {
          for (int y = j - 1; y <= j + 1; y++)
          {
            if ((x >= 0 && y >= 0) && (x < rows && y < cols) && (x != i || y != j))
            {
              sum += matrix[x][y];
              count++;
            }
          }
        }
        smoothedMatrix[i][j] = sum / count;
      }
    }

   std::cout << "smoothedMatrix\n";
    for(int i = 0; i < rows; ++i)
    {
      std::cout << "[";
      for(int j = 0; j < cols; ++j)
      {
        std::cout << " " << smoothedMatrix[i][j] << " ";
      }
      std::cout << "]\n";
    }

    //файл вывода
    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "Cannot open the input file\n";
      return 2;
    }

    for (int i = 0; i < rows; ++i)
    {
      output << "|";
      for (int j = 0; j < cols; ++j)
      {
        output << std::fixed << std::setprecision(1) <<" " << smoothedMatrix[i][j] << " ";
      }
      output << "|\n";
    }
  }

  return 0;
}
