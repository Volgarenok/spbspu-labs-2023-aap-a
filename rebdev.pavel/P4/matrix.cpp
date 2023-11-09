#include "matrix.hpp"
#include <stdexcept>
#include <limits>
#include <iostream>

rebdev::matrix::matrix():
  rows_(0),
  colums_(0)
{}

rebdev::matrix::matrix(size_t rows, size_t colums):
  rows_(rows),
  colums_(colums)
{}


void rebdev::matrix::filling(std::ifstream & inputFile, long long int * arr)
{
  for (size_t i = 0; i < (colums_ * rows_); ++i)
  {
    inputFile >> arr[i];
    if (!inputFile)
    {
      throw std::logic_error("can't read number from file!\n");
    }
  }
}

size_t rebdev::matrix::localMax(long long int * arr)
{
  size_t numberOfLocalMax = 0;

  for (size_t i = 0; i < (colums_ * rows_); ++i)
  {
    bool isLocalMax = 1;

    for (int columIndex = -1; columIndex <= 1; ++columIndex)
    {
      for (int rowIndex = -1; rowIndex <= 1; ++rowIndex)
      {
        //Проверка, является ли номер элемента корректным
        if(isNumberOfElementIsCorrect(i, columIndex, rowIndex))
        {
          if ((arr[i] <= arr[i + rowIndex + colums_ * columIndex]) && ((columIndex != 0) || (rowIndex != 0)))
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

bool rebdev::matrix::isNumberOfElementIsCorrect(size_t itemOfNumber, int columIndex, int rowIndex)
{
  //проверка верхней границы
  if (((itemOfNumber + rowIndex + colums_ * columIndex) < (rows_ * colums_))
      && (itemOfNumber < (std::numeric_limits< size_t >::max() -1 * (rowIndex + colums_ * columIndex))))
  {
    //проверка нижней границы
    if (itemOfNumber >= (-1 * (rowIndex + colums_ * columIndex)))
    {
      //проверка начала строки
      if (!(((itemOfNumber % colums_) == 0) && (rowIndex == -1)))
      {
        //проверка конца строки
        if (!(((itemOfNumber % colums_) == (colums_ - 1)) && (rowIndex == 1)))
        {
          return 1;
        }
      }
    }
  }
  return 0;
}
