#include "inputShapesSource.hpp"

#include <cstring>
#include <string>
#include <cctype>

#include "rectangle.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include "inputString.hpp"

namespace zhalilov
{
  Shape *inputRectangle(const char string[])
  {
    double coords[4] = {};
    size_t delta = 0;
    size_t nameLen = 9;
    const char *newStr = string + nameLen;
    for (size_t i = 0; i < 4; i++)
    {
      coords[i] = std::stod(newStr, &delta);
      newStr += delta;
    }
    if (*newStr != '\0')
    {
      throw std::invalid_argument("too many args to describe rectangle");
    }
    point_t leftCorner = { coords[0], coords[1] };
    point_t rightCorner = { coords[2], coords[3] };
    return new Rectangle(leftCorner, rightCorner);
  }

  Shape *inputCircle(const char string[])
  {
    double nums[3] = {};
    size_t delta = 0;
    size_t nameLen = 6;
    const char *newStr = string + nameLen;
    for (size_t i = 0; i < 3; i++)
    {
      nums[i] = std::stod(newStr, &delta);
      newStr += delta;
    }
    if (*newStr != '\0')
    {
      throw std::invalid_argument("too many args to describe circle");
    }
    point_t center = { nums[0], nums[1] };
    double radius = nums[2];
    return new Circle(center, radius);
  }

  Shape *inputPolygon(const char string[])
  {
    size_t size = 10;
    size_t length = 0;
    double *coords = new double[10];
    size_t nameLen = 7;
    const char *newStr = string + nameLen;
    size_t i = 0;
    size_t delta = 0;
    while (*newStr != '\0')
    {
      coords[i] = std::stod(newStr, &delta);
      newStr += delta;
      if (i + 1 == size)
      {
        double *newCoords = nullptr;
        try
        {
          newCoords = new double[size + 4]{};
          for (size_t j = 0; j < size; j++)
          {
            newCoords[j] = coords[j];
          }
          delete[] coords;
          coords = newCoords;
          size += 4;
        }
        catch (const std::bad_alloc &e)
        {
          delete[] coords;
          throw;
        }
      }
      i++;
    }
    length = i;
    if (length % 2 != 0)
    {
      delete[] coords;
      throw std::invalid_argument("incorrect num of args to describe polygon");
    }
    point_t *points = new point_t[length / 2];
    for (size_t j = 0; j < length; j += 2)
    {
      points[j / 2] = { coords[j], coords[j + 1] };
    }
    delete[] coords;
    try
    {
      Shape *shape = new Polygon(points, length / 2);
      return shape;
    }
    catch (const std::invalid_argument &e)
    {
      delete[] points;
      throw;
    }
  }

  shapeInputFunc identifyShape(const char string[])
  {
    const char *names[] = {"RECTANGLE", "CIRCLE", "POLYGON"};
    shapeInputFunc functions[3];
    functions[0] = inputRectangle;
    functions[1] = inputCircle;
    functions[2] = inputPolygon;
    size_t namesSize = 3;
    for (size_t i = 0; i < namesSize; i++)
    {
      size_t nameLen = strlen(names[i]);
      if (strncmp(names[i], string, nameLen) == 0)
      {
        return functions[i];
      }
    }
    return nullptr;
  }

  bool inputScale(point_t &point, double &ratio, const char string[])
  {
    char name[] = "SCALE";
    size_t nameLen = 5;
    if ((strncmp(name, string, nameLen) == 0)
      && (isspace(string[nameLen])))
    {
      const char *newStr = string + nameLen;
      size_t delta = 0;
      double x = std::stod(newStr, &delta);
      newStr += delta;
      double y = std::stod(newStr, &delta);
      newStr += delta;
      double inputedRatio = std::stod(newStr, &delta);

      point = { x, y };
      ratio = inputedRatio;
      return true;
    }
    return false;
  }

  Shape **increaseLength(Shape **shapes, size_t size, size_t delta)
  {
    Shape **newShapes = new Shape*[size + delta]{};
    for (size_t i = 0; i < size; i++)
    {
      newShapes[i] = shapes[i];
    }
    return newShapes;
  }
}

void zhalilov::freeMemory(Shape **shapes, size_t size, const char string[])
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
  delete[] string;
}

zhalilov::Shape **zhalilov::inputShapesSource(point_t &point, double &ratio, size_t &length, size_t &size, std::istream &input)
{
  size_t shapeIndex = 0;
  size = 10;
  Shape **shapes = new Shape*[10]{};
  char *string = nullptr;
  while (true)
  {
    try
    {
      string = inputString(input);
    }
    catch (const std::bad_alloc &e)
    {
      freeMemory(shapes, size, string);
      throw;
    }
    catch (const std::invalid_argument &e)
    {
      freeMemory(shapes, size, string);
      throw;
    }

    try
    {
      shapeInputFunc inputFunc = identifyShape(string);
      if (inputFunc)
      {
        if (shapeIndex == size)
        {
          Shape **newShapes = increaseLength(shapes, size, 5);
          delete[] shapes;
          shapes = newShapes;
        }
        shapes[shapeIndex] = inputFunc(string);
        shapeIndex++;
      }
    }
    catch (const std::invalid_argument &e)
    {
      shapes[shapeIndex] = nullptr;
      shapeIndex++;
    }
    catch (const std::bad_alloc &e)
    {
      freeMemory(shapes, size, string);
      throw;
    }

    if (inputScale(point, ratio, string))
    {
      delete[] string;
      length = shapeIndex;
      return shapes;
    }
    delete[] string;
    string = nullptr;
  }
}
