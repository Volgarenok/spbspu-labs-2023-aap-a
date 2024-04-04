#include "input.hpp"

#include <string>

#include "rectangle.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "regular.hpp"

namespace vyzhanov
{
  Shape* createRectangle(const double* nums, size_t length)
  {
    if (length != 4)
    {
      throw std::invalid_argument("incorrect rect src's num of args");
    }
    point_t leftCorner = { nums[0], nums[1] };
    point_t rightCorner = { nums[2], nums[3] };
    return new Rectangle(leftCorner, rightCorner);
  }

  Shape* createSquare(const double* nums, size_t length)
  {
    if (length != 3)
    {
      throw std::invalid_argument("incorrect count of args");
    }
    point_t LeftCorner = { nums[0], nums[1] };
    double len = nums[2];
    return new Square(LeftCorner, len);
  }

  Shape* createTriangle(const double* nums, size_t length)
  {
    if (length != 6)
    {
      throw std::invalid_argument("incorrect count of args");
    }
    point_t a = { nums[0], nums[1] };
    point_t b = { nums[2], nums[3] };
    point_t c = { nums[4], nums[5] };
    return new Triangle(a, b, c);
  }

  Shape* createRegular(const double* nums, size_t length)
  {
    if (length != 6)
    {
      throw std::invalid_argument("incorrect count of args");
    }
    point_t a = { nums[0], nums[1] };
    point_t b = { nums[2], nums[3] };
    point_t c = { nums[4], nums[5] };
    return new Regular(a, b, c);
  }

  double* shapePoints(size_t& length, std::istream& input)
  {
    size_t size = 6;
    double* nums = new double[size] {};
    double num = 0;
    size_t index = 0;
    while (input >> num)
    {
      nums[index] = num;
      if (index + 1 == size)
      {
        try
        {
          double* newNums = new double[size + 6];
          for (size_t i = 0; i < size; ++i)
          {
            newNums[i] = nums[i];
          }
          delete[] nums;
          nums = newNums;
          size += 5;
        }
        catch (const std::bad_alloc& e)
        {
          delete[] nums;
          throw;
        }
      }
      index++;
    }
    input.clear();
    length = index;
    return nums;
  }
}

void vyzhanov::deleteShapes(Shape* shapes[], size_t length)
{
  for (size_t i = 0; i < length; i++)
  {
    delete shapes[i];
  }
}

void vyzhanov::inputShapes(Shape** shapes, point_t& point, double& ratio, size_t& length, std::istream& input)
{
  size_t index = 0;
  bool hasIncorrectShapes = false;
  std::string name;
  double* nums = nullptr;
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
      using shapeCreatingFunc = Shape * (*)(const double* points, size_t length);
      size_t namesSize = 4;
      const std::string shapeNames[] = { "RECTANGLE", "TRIANGLE", "SQUARE", "REGULAR"};
      shapeCreatingFunc func[4];
      func[0] = createRectangle;
      func[1] = createTriangle;
      func[2] = createSquare;
      func[3] = createRegular;
      for (size_t i = 0; i < namesSize; i++)
      {
        if (shapeNames[i] == name)
        {
          size_t length = 0;
          nums = shapePoints(length, input);
          shapes[index] = func[i](nums, length);
          index++;
          delete[] nums;
        }
      }
    }
    catch (const std::invalid_argument& e)
    {
      hasIncorrectShapes = true;
      delete[] nums;
    }
    catch (const std::exception& e)
    {
      length = index;
      delete[] nums;
      throw;
    }
  }
  input >> point.x >> point.y;
  input >> ratio;
  length = index;
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
