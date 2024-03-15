#include "inputShapes.hpp"
#include <stdexcept>
#include <cctype>
#include <cstring>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "parametersLogic.hpp"

grechishnikov::Shape* grechishnikov::inputShape(const char* str)
{
  if (str == nullptr)
  {
    throw std::logic_error("String wasn't given");
  }
  const size_t legalNameCount = 3;
  const char* legalName[] = { "RECTANGLE", "TRIANGLE", "POLYGON" };
  Shape* (*correspondingFunctions[])(const point_t* points, size_t size) = {
    inputRectangle,
    inputTriangle,
    inputPolygon
  };

  const char* name = nullptr;
  const double* values = nullptr;
  const point_t* points = nullptr;
  size_t size = 0;

  try
  {
    name = parseName(str);
    for (size_t i = 0; i < legalNameCount; i++)
    {
      if (std::strcmp(legalName[i], name) == 0)
      {
        size_t pos = 0;
        for (size_t i = 0; str[i] != ' '; i++)
        {
          pos++;
        }
        values = parseValues(str + pos, size);
        points = makePairs(values, size);

        Shape* returnShape = (*correspondingFunctions[i])(points, size / 2);

        delete[] name;
        delete[] values;
        delete[] points;
        return returnShape;
      }
    }
  }
  catch (const std::exception& e)
  {
    delete[] name;
    delete[] values;
    delete[] points;
    throw;
  }

  delete[] name;
  throw std::logic_error("Unknown name");
}

grechishnikov::Shape* grechishnikov::inputRectangle(const point_t* points, size_t size)
{
  if (size != 2)
  {
    throw std::invalid_argument("Invalid parameters (Wrong number of  arguments for rectangle)");
  }
  return new Rectangle(points[0], points[1]);
}

grechishnikov::Shape* grechishnikov::inputTriangle(const point_t* points, size_t size)
{
  if (size != 3)
  {
    throw std::invalid_argument("Invalid parameters (Wrong number of  arguments for triangle)");
  }
  return new Triangle(points[0], points[1], points[2]);
}

grechishnikov::Shape* grechishnikov::inputPolygon(const point_t* points, size_t size)
{
  return new Polygon(points, size);
}

void grechishnikov::freeShapes(const Shape* const* shapes, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
}

const char* grechishnikov::parseName(const char* str)
{
  if (str == nullptr)
  {
    return nullptr;
  }
  char* name = new char[20] { '0' };
  size_t i = 0;
  for (i = 0; str[i] != ' ' && str[i] != '\0'; i++)
  {
    if (std::isalpha(str[i]))
    {
      name[i] = str[i];
    }
    else
    {
      delete[] name;
      throw std::logic_error("Incorrect name input");
    }
  }
  name[i] = '\0';
  return name;
}
