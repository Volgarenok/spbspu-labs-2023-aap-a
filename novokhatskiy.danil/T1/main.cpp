#include <iostream>
#include "ring.hpp"
#include "ellipse.hpp"
#include "rectangle.hpp"
#include "inputShapes.hpp"
#include "outputShapes.hpp"
#include "isoScale.hpp"

int main()
{
  using namespace novokhatskiy;
  Shape **shapes = nullptr;
  size_t shapesCount = 0;
  point_t point;
  double ratio = 0.0;
  try
  {
    shapes = inputShapes(std::cin, shapesCount);
    outputShapes(std::cout, shapesCount, shapes);
    std::cin >> point.x >> point.y >> ratio;
    if (!std::cin)
    {
      throw std::invalid_argument("Wrong input\n");
    }
    for (size_t i = 0; i < shapesCount; i++)
    {
      isoScale(shapes[i], point, ratio);
    }
    outputShapes(std::cout, shapesCount, shapes);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Memory error\n";
    return 1;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    for (size_t i = 0; i < shapesCount; i++)
    {
      delete shapes[i];
    }
    delete[] shapes;
    return 1;
  }
  for (size_t i = 0; i < shapesCount; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
  return 0;
}