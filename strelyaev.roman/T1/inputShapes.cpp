#include "inputShapes.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

void strelyaev::createPoints(const size_t num_points, double* coords_array, point_t* points)
{
  for (size_t i = 0; i < num_points; ++i)
  {
    size_t index = i * 2;
    points[i] = {coords_array[index], coords_array[index + 1]};
  }
}

strelyaev::Shape* strelyaev::inputRectangle(const char string[])
{
  const char* coords_string = string + 10;
  double coords_array[4]{};
  size_t pos = 0;
  for (size_t i = 0; i < 4; ++i)
  {
    coords_array[i] = std::stod(coords_string, std::addressof(pos));
    coords_string += pos;
  }
  if (*coords_string != '\0')
  {
    throw std::invalid_argument("Invalid RECTANGLE arguments");
  }
  constexpr size_t num_points = 2;
  point_t points[num_points]{};
  createPoints(num_points, coords_array, points);
  return new Rectangle(points[0], points[1]);
}

strelyaev::Shape* strelyaev::inputTriangle(const char string[])
{
  const char* coords_string = string + 9;
  double coords_array[6]{};
  size_t pos = 0;
  for (size_t i = 0; i < 6; ++i)
  {
    coords_array[i] = std::stod(coords_string, std::addressof(pos));
    coords_string += pos;
  }
  if (*coords_string != '\0')
  {
    throw std::invalid_argument("Invalid TRIANGLE arguments");
  }
  constexpr size_t num_points = 3;
  point_t points[num_points]{};
  createPoints(num_points, coords_array, points);
  return new Triangle(points[0], points[1], points[2]);
}

strelyaev::Shape* strelyaev::inputParallelogram(const char string[])
{
  const char* coords_string = string + 14;
  double coords_array[6]{};
  size_t pos = 0;
  for (size_t i = 0; i < 6; ++i)
  {
    coords_array[i] = std::stod(coords_string, std::addressof(pos));
    coords_string += pos;
  }
  if (*coords_string != '\0')
  {
    throw std::invalid_argument("Invalid PARALLELOGRAM arguments");
  }
  constexpr size_t num_points = 3;
  point_t points[num_points]{};
  createPoints(num_points, coords_array, points);
  return new Parallelogram(points[0], points[1], points[2]);
}
