#include <iostream>
#include <fstream>
#include <string>

size_t inputArray(std::ifstream & input, int * array, size_t size, size_t sizeToRead)
{
  for (size_t i = 0; i < std::min(size, sizeToRead); ++i)
  {
    input >> array[i];
    if (!input)
    {
      return i;
    }
  }
  return std::min(size, sizeToRead);
}


int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Bad input arguments\n";
    return 1;
  }

  // Чтение первого числа
  int taskNumber = 0;
  try
  {
    taskNumber = std::stoll(argv[1]);
  }
  catch (...)
  {
    std::cerr << "Cannot parse values\n";
    return 1;
  }

  if (taskNumber == 1)
  {
    {
      // Чтение из файла и записть в файл статический массив
      std::ifstream input(argv[2]);
      size_t col = 0;
      size_t row = 0;

      input >> col;
      input >> row;
      if (!input)
      {
        std::cerr << "Cannot parse number of column or rows\n";
        return 2;
      }

      int size = col * row;
      int array[size];
      int number = 0;
      for (int i = 0; i < size; ++i)
      {
        input >> number;
        if (!input)
        {
          std::cerr << "Cannot parse number from file\n";
          return 2;
        }
        array[i] = number;
      }
      // решение задачи
    }
  }
  else if (taskNumber == 2)
  {
    std::ifstream input(argv[2]);

    size_t col = 0;
    size_t row = 0;

    input >> col >> row;

    if (!input)
    {
      std::cerr << "Cannot parse number of column or rows\n";
      return 2;
    }

    int * array = new int[row * col];
    int number = 0;
    size_t numOfElements = 0;
    numOfElements = inputArray(input, array, (row * col), (row * col));
    if (numOfElements != (row * col))
    {
      std::cout << numOfElements << "\n";
      std::cerr << "Cannot parse numbers from file\n";
      delete [] array;
      return 2;
    }
    std::cout << numOfElements;
  }
  else
  {

  }
}
