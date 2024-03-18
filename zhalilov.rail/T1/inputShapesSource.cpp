#include "inputShapesSource.hpp"

#include <string>

#include "rectangle.hpp"
#include "circle.hpp"
#include "polygon.hpp"

namespace zhalilov
{
  Shape *createRectangle(const double *nums, size_t length)
  {
    if (length != 4)
    {
      throw std::invalid_argument("incorrect rect src's num of args");
    }
    point_t leftCorner = { nums[0], nums[1] };
    point_t rightCorner = { nums[2], nums[3] };
    return new Rectangle(leftCorner, rightCorner);
  }

  Shape *createCircle(const double *nums, size_t length)
  {
    if (length != 3)
    {
      throw std::invalid_argument("incorrect circle src's num of args");
    }
    point_t center = { nums[0], nums[1] };
    double radius = nums[2];
    return new Circle(center, radius);
  }

  Shape *createPolygon(const double *nums, size_t length)
  {
    if (length % 2 != 0 || length < 6)
    {
      throw std::invalid_argument("incorrect polygon src's nums of args");
    }

    point_t *points = nullptr;
    Shape *polygon = nullptr;
    try
    {
      points = new point_t[length / 2];
      for (size_t i = 0; i < length / 2; i++)
      {
        points[i] = { nums[i * 2], nums[i * 2 + 1] };
      }
      polygon = new Polygon(points, length / 2);
    }
    catch (const std::exception &e)
    {
      delete[] points;
      throw;
    }
    delete[] points;
    return polygon;
  }

  double *getPointsFromStream(size_t &length, std::istream &input)
  {
    size_t size = 3;
    double *nums = new double[size]{};
    double num = 0;
    size_t index = 0;
    while (input >> num)
    {
      if (index + 1 == size)
      {
        try
        {
          double *newNums = new double[size + 4];
          for (size_t i = 0; i < size; i++)
          {
            newNums[i] = nums[i];
          }
          delete[] nums;
          nums = newNums;
          size += 4;
        }
        catch (const std::bad_alloc &e)
        {
          delete[] nums;
          throw;
        }
      }
      nums[index] = num;
      index++;
    }
    input.clear();
    length = index;
    return nums;
  }
}

void zhalilov::freeShapes(Shape *shapes[], size_t length)
{
  for (size_t i = 0; i < length; i++)
  {
    delete shapes[i];
  }
}

void zhalilov::inputShapesSource(Shape **shapes, point_t &point, double &ratio, size_t &length, std::istream &input)
{
  size_t shapeIndex = 0;
  bool hasIncorrectShapes = false;
  std::string name;
  double *nums = nullptr;
  while (name != "SCALE")
  {
    try
    {
      nums = nullptr;
      input >> name;
      if (!input)
      {
        throw std::ios_base::failure("input interrupted");
      }

      using shapeCreatingFunc = Shape *(*)(const double *points, size_t length);
      size_t namesSize = 3;
      const std::string shapeNames[] = {"RECTANGLE", "CIRCLE", "POLYGON"};
      shapeCreatingFunc functions[3];
      functions[0] = createRectangle;
      functions[1] = createCircle;
      functions[2] = createPolygon;
      for (size_t i = 0; i < namesSize; i++)
      {
        if (shapeNames[i] == name)
        {
          size_t length = 0;
          nums = getPointsFromStream(length, input);
          shapes[shapeIndex] = functions[i](nums, length);
          shapeIndex++;
          delete[] nums;
        }
      }
    }
    catch (const std::invalid_argument &e)
    {
      hasIncorrectShapes = true;
      delete[] nums;
    }
    catch (const std::exception &e)
    {
      length = shapeIndex;
      delete[] nums;
      throw;
    }
  }

  input >> point.x >> point.y;
  input >> ratio;
  length = shapeIndex;
  if (ratio <= 0.0)
  {
    throw std::underflow_error("ratio scale should be greater than zero");
  }
  if (hasIncorrectShapes)
  {
    throw std::invalid_argument("some shapes have incorrect source");
  }
  return;
}
