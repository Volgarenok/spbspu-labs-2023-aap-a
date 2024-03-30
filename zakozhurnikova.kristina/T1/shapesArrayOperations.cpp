#include "shapesArrayOperations.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <inputOperations.hpp>
#include "rectangle.hpp"
#include "square.hpp"
#include "diamond.hpp"
#include "complexquad.hpp"

void readArray(double* array, size_t size, const char* string, size_t pos)
{
  for (size_t i = 0; i < size; ++i)
  {
    array[i] = std::stod(string, &pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }
}

bool areSame(const char* s1, const char* s2)
{
  return std::strncmp(s1, s2, std::strlen(s2)) == 0;
}

zakozhurnikova::Shape* readRectangle(const char* string)
{
  const size_t RECT_WORD_LEN = 9;
  constexpr size_t ARRAY_LEN = 4;
  double rectData[ARRAY_LEN]{};
  size_t pos = 0;
  string += RECT_WORD_LEN;
  readArray(rectData, ARRAY_LEN, string, pos);
  using point_t = zakozhurnikova::point_t;
  point_t downLeft = { rectData[0], rectData[1] };
  point_t upRight = { rectData[2], rectData[3] };
  return new zakozhurnikova::Rectangle(downLeft, upRight);
}

zakozhurnikova::Shape* readSquare(const char* string)
{
  const size_t SQUARE_WORD_LEN = 6;
  constexpr size_t ARRAY_LEN = 3;
  double squareData[ARRAY_LEN]{};
  size_t pos = 0;
  string += SQUARE_WORD_LEN;
  readArray(squareData, ARRAY_LEN, string, pos);
  zakozhurnikova::point_t downLeft = { squareData[0], squareData[1] };
  double length = squareData[2];

  return new zakozhurnikova::Square(downLeft, length);
}

zakozhurnikova::Shape* readDiamond(const char* string)
{
  const size_t SQUARE_WORD_LEN = 7;
  constexpr size_t ARRAY_LEN = 6;
  double diamondData[ARRAY_LEN]{};
  size_t pos = 0;
  string += SQUARE_WORD_LEN;
  readArray(diamondData, ARRAY_LEN, string, pos);
  using point_t = zakozhurnikova::point_t;
  point_t pointOne = { diamondData[0], diamondData[1] };
  point_t pointTwo = { diamondData[2], diamondData[3] };
  point_t center = { diamondData[4], diamondData[5] };

  return new zakozhurnikova::Diamond(pointOne, pointTwo, center);
}

zakozhurnikova::Shape* readComplexquad(const char* string)
{
  const size_t COMPLEXQUAD_WORD_LEN = 11;
  constexpr size_t ARRAY_LEN = 8;
  double complexquadData[ARRAY_LEN]{};
  size_t pos = 0;
  string += COMPLEXQUAD_WORD_LEN;
  readArray(complexquadData, ARRAY_LEN, string, pos);
  using point_t = zakozhurnikova::point_t;
  point_t pointOne = { complexquadData[0], complexquadData[1] };
  point_t pointTwo = { complexquadData[2], complexquadData[3] };
  point_t pointThree = { complexquadData[4], complexquadData[5] };
  point_t pointFour = { complexquadData[6], complexquadData[7] };

  return new zakozhurnikova::Complexquad{pointOne, pointTwo, pointThree, pointFour};
}

zakozhurnikova::Shape* zakozhurnikova::readShape(const char* string)
{
  if (string && areSame(string, "RECTANGLE"))
  {
    return readRectangle(string);
  }
  else if (string && areSame(string, "SQUARE"))
  {
    return readSquare(string);
  }
  else if (string && areSame(string, "DIAMOND"))
  {
    return readDiamond(string);
  }
  else if (string && areSame(string, "COMPLEXQUAD"))
  {
    return readComplexquad(string);
  }
  else
  {
    throw std::invalid_argument("Invalid shape name");
  }
}

void zakozhurnikova::readScale(const char* string, zakozhurnikova::point_t& scalePoint, double& k)
{
  constexpr size_t SCALE_PARAM_COUNT = 3;
  const size_t SCALE_WORD_LEN = 5;
  double scaleData[SCALE_PARAM_COUNT]{};
  size_t pos = 0;
  string += SCALE_WORD_LEN;
  readArray(scaleData, SCALE_PARAM_COUNT, string, pos);
  scalePoint = { scaleData[0], scaleData[1] };
  k = scaleData[2];
}

void zakozhurnikova::freeShapesArray(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
}

void zakozhurnikova::inputShapesArray(std::istream& in, Shape** shapes, size_t& size, point_t& scalePoint, double& k)
{
  char* string = nullptr;
  while (true)
  {
    try
    {
      size_t stringSize = 20;
      string = zakozhurnikova::readString(in, stringSize);
      shapes[size] = zakozhurnikova::readShape(string);
      ++size;
      delete[] string;
    }
    catch (const std::invalid_argument& e)
    {
      if (areSame(string, "SCALE"))
      {
        break;
      }
      delete[] string;
      std::cerr << e.what() << '\n';
    }
    catch (const std::logic_error& e)
    {
    }
  }
  readScale(string, scalePoint, k);
  delete[] string;
  return;
}
