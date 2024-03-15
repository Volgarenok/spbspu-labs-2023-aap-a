#include "inputShapes.hpp"
#include "Rectangle.hpp"
#include <string>
#include <stdexcept>
#include <stdexcept>

void shabalin::creatingPoints(const size_t numberOfPoints, double *coordsOfArray, point_t *points)
{
  for (size_t i = 0; i < numberOfPoints; ++i)
  {
    size_t index = i * 2;
    points[i] = {coordsOfArray[index], coordsOfArray[index + 1]};
  }
}

shabalin::Shape *shabalin::inputOfRectangle(const char str[])
{
  const char *coordsOfString = str + 10;
  double coordsOfArray[4]{};
  size_t position = 0;
  for (size_t i = 0; i < 4; ++i)
  {
    coordsOfArray[i] = std::stod(coordsOfArray, std::addressof(position));
    coordsOfString += position;
  }
  if (*coordsOfArray != '\0')
  {
    throw std::invalid_argument("Invalid arguments for Rectangle");
  }
  constexpr size_t numberOfPoints = 2;
  point_t points[numberOfPoints]{};
  creatingPoints(numberOfPoints, coordsOfArray, points);
  return new Rectangle(points[0], points[1]);
}
