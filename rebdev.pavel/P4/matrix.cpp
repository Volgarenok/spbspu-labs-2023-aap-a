#include "matrix.hpp"
#include <stdexcept>
#include <limits>
#include <iostream>

rebdev::matrix::matrix():
  colums_(0),
  rows_(0),
  arrayOfElements_(nullptr)
{}

rebdev::matrix::matrix(int arrayMode, std::ifstream & inputFile):
  colums_(0),
  rows_(0),
  arrayOfElements_(nullptr)
{
  //Проверка, на корректность/наличие первых двух чисел в файле
  inputFile >> rows_ >> colums_;
  if (!inputFile)
  {
    throw std::invalid_argument("Error: in reading the number of rows or columns\n");
  }
  if (rows_ > (std::numeric_limits< size_t >::max()/colums_))
  {
    throw std::overflow_error("Error: there are too many elements in the matrix\n");
  }
  
  //Создание массива
  try
  {
   if (arrayMode == 1)
    {
      long long int newArrayOfElements[10000];
      std::cout << (sizeof(newArrayOfElements) / sizeof(long long int)) << '\n';
      *arrayOfElements_ = *newArrayOfElements;
      std::cout << (sizeof(arrayOfElements_) / sizeof(long long int)) << '\n';
    }
    else if (arrayMode == 2)
    {
      arrayOfElements_ = new long long int[rows_ * colums_];
    }
    //Заполнение массива
    fillingTheMatrix();
  }
  catch (const std::exception & e)
  {
    delete[] arrayOfElements_;
  }
}

rebdev::matrix::~matrix()
{
  if(arrayOfElements_ != nullptr)
  {
   //delete[] arrayOfElements_;
  }
}

size_t rebdev::matrix::localMax()
{
  size_t numberOfLocalMax = 0;
  
  for (size_t i = 0; i < (colums_ * rows_); ++i)
  {
    bool isLocalMax = 1;

    for (int columIndex = -1; columIndex <= 1; ++columIndex)
    {
      for (int rowIndex = -1; rowIndex <= 1; ++rowIndex)
      {
        if(!isNumberOfElementIsCorrect(numberOfLocalMax, columIndex, rowIndex))
        {
          if ((arrayOfElements_[i] <= arrayOfElements_[i + rowIndex + colums_ * columIndex]) && ((columIndex != 0) || (rowIndex != 0)))
          {
            isLocalMax = 0;
            columIndex = 2;
            rowIndex = 2;
            break;
          }
        }
      }
    }
    numberOfLocalMax += isLocalMax;
  }

  return numberOfLocalMax;
}

void rebdev::matrix::fillingTheMatrix()
{
  for (size_t i = 0; i < (colums_ * rows_); ++i)
  {
    inputFile_ >> arrayOfElements_[i];
    if (!inputFile_)
    {
      throw std::logic_error("can't read number from file!\n");
    }
  }
}

bool rebdev::matrix::isNumberOfElementIsCorrect(size_t itemOfNumber, int columIndex, int rowIndex)
{
  if ((itemOfNumber + rowIndex + colums_ * columIndex) >= 0)
  {
    if ((itemOfNumber + rowIndex + colums_ * columIndex) < (rows_ * colums_))
    {
      if (!(((itemOfNumber % columIndex) == 1) && (rowIndex ==-1)))
      {
        if (!(((itemOfNumber % columIndex) == 0) && (rowIndex ==1)))
        {
          return 1;
        }
      }
    }
  }
  return 0;
}
