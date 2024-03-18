#include "inputShapes.hpp"
#include <stdexcept>
#include <cstring>
#include <inputString.hpp>
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"

void baranov::parseParameters(const char * string, double * parameters, size_t count)
{
  size_t pos = 0;
  for (size_t i = 0; i < count; ++i)
  {
    parameters[i] = std::stod(string, & pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid shape parameters");
  }
}

baranov::Shape * baranov::parseRectangle(const char * string)
{
  double rectParameters[4]{};
  parseParameters(string, rectParameters, 4);
  point_t ldCorner = { rectParameters[0], rectParameters[1] };
  point_t ruCorner = { rectParameters[2], rectParameters[3] };
  return new Rectangle(ldCorner, ruCorner);
}

baranov::Shape * baranov::parseRing(const char * string)
{
  double ringParameters[4]{};
  parseParameters(string, ringParameters, 4);
  point_t center = { ringParameters[0], ringParameters[1] };
  return new Ring(center, ringParameters[2], ringParameters[3]);
}

baranov::Shape * baranov::parseEllipse(const char * string)
{
  double ellipseParameters[4]{};
  parseParameters(string, ellipseParameters, 4);
  point_t center = { ellipseParameters[0], ellipseParameters[1] };
  return new Ellipse(center, ellipseParameters[2], ellipseParameters[3]);
}

void baranov::parseScale(const char * string, point_t & scalePoint, size_t & scaleRatio)
{
  double scaleParameters[3]{};
  size_t pos = 0;
  string += 5;
  for (size_t i = 0; i < 3; ++i)
  {
    try
    {
      scaleParameters[i] = std::stod(string, & pos);
    }
    catch (const std::exception &)
    {
      throw std::runtime_error("Invalid scale parameters");
    }
    string += pos;
  }
  if (*string != '\0' || scaleParameters[2] < 0)
  {
    throw std::runtime_error("Invalid scale parameters");
  }
  scalePoint = { scaleParameters[0], scaleParameters[1] };
  scaleRatio = scaleParameters[2];
}

baranov::Shape * baranov::parseShape(const char * string)
{
  const size_t shapeCount = 3;
  const char * shapeNames[] = { "RECTANGLE", "RING", "ELLIPSE" };
  for (size_t i = 0; i < shapeCount; ++i)
  {
    size_t nameSize = std::strlen(shapeNames[i]);
    if (std::strlen(string) <= nameSize)
    {
      continue;
    }
    if (std::strncmp(shapeNames[i], string, nameSize) == 0)
    {
      string += nameSize;
      if (i == 0)
      {
        return parseRectangle(string);
      }
      else if (i == 1)
      {
        return parseRing(string);
      }
      else if (i == 2)
      {
        return parseEllipse(string);
      }
    }
  }
  throw std::invalid_argument("Invalid shape name");
}

void baranov::freeShapes(Shape ** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
}

void baranov::inputShapes(std::istream & input, Shape ** shapes, size_t & count, point_t & scalePoint, size_t & scaleRatio)
{
  char * string = nullptr;
  while (true)
  {
    try
    {
      size_t stringSize = 20;
      string = inputString(input, stringSize);
      if (std::strncmp(string, "SCALE", 5) == 0)
      {
        parseScale(string, scalePoint, scaleRatio);
        delete[] string;
        return;
      }
      shapes[count] = parseShape(string);
      ++count;
      delete[] string;
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << '\n';
      delete[] string;
    }
    catch (const std::logic_error &)
    {
    }
    catch (const std::range_error &)
    {
      freeShapes(shapes, count);
      throw;
    }
    catch (const std::exception &)
    {
      delete[] string;
      freeShapes(shapes, count);
      throw;
    }
  }
}

