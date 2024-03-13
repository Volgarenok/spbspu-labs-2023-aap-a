#include "input.hpp"
#include <iostream>

void ishmuratov::inputShape(std::istream& input, Shape ** shapeArray, size_t & count)
{
  std::string shapeName = "";
  size_t new_count = 0;
  bool invalidShape = false;
  while ((input >> shapeName) && (shapeName != "SCALE"))
  {
    try
    {
      Shape * newShape = initShape(shapeName, input);
      shapeArray[new_count++] = newShape;
    }
    catch (const std::invalid_argument & e)
    {
      invalidShape = true;
    }
  }
  count = new_count;
  if (invalidShape)
  {
    throw std::invalid_argument("Invalid Shape!");
  }
  if (count == 0)
  {
    throw std::runtime_error("Not enough data!");
  }
}

void ishmuratov::freeMemory(Shape ** shapeArray, size_t & count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapeArray[i];
  }
}

void ishmuratov::inputPoint(std::istream & input, double * pointArray, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    input >> pointArray[i];
  }
}

ishmuratov::Shape * ishmuratov::initShape(const std::string & shapeName, std::istream & input)
{
  const char * shapeNames[4] = {"RECTANGLE", "TRIANGLE", "DIAMOND", "CONCAVE"};
  double pA[8]{};
  if (shapeName == shapeNames[0])
  {
    inputPoint(input, pA, 4);
    return new Rectangle({ pA[0], pA[1] }, { pA[2], pA[3] });
  }
  else if (shapeName == shapeNames[1])
  {
    inputPoint(input, pA, 6);
    return new Triangle({ pA[0], pA[1] }, { pA[2], pA[3] }, { pA[4], pA[5] });
  }
  else if (shapeName == shapeNames[2])
  {
    inputPoint(input, pA, 6);
    return new Diamond({ pA[0], pA[1] }, { pA[2], pA[3] }, { pA[4], pA[5] });
  }
  else if (shapeName == shapeNames[3])
  {
    inputPoint(input, pA, 8);
    return new Concave({ pA[0], pA[1] }, { pA[2], pA[3] }, { pA[4], pA[5] }, { pA[6], pA[7] });
  }
  throw std::invalid_argument("Invalid Shape!");
}

