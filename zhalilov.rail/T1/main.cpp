#include <iostream>

#include "inputShapesSource.hpp"
#include "outputShapesSource.hpp"
#include "isoScale.hpp"

int main()
{
  using namespace zhalilov;
  Shape **shapes = nullptr;
  point_t point = { 0.0, 0.0 };
  double ratio = 0.0;
  size_t length = 0;
  size_t size = 0;
  try
  {
    shapes = inputShapesSource(point, ratio, length, size, std::cin);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "An error has occured: " << e.what();
    return 1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "An error has occured: " << e.what();
    return 1;
  }

  if (length == 0)
  {
    std::cerr << "An error has occured: nothing to scale\n";
    delete[] shapes;
    return 1;
  }

  for (size_t i = 0; i < length; i++)
  {
    if (!shapes[i])
    {
      std::cerr << "Error: some shapes have incorrect source\n";
      break;
    }
  }

  try
  {
    outputShapesSource(shapes, length, std::cout);
    for (size_t i = 0; i < length; i++)
    {
      if (shapes[i])
      {
        isoScale(shapes[i], point, ratio);
      }
    }
    outputShapesSource(shapes, length, std::cout);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "An error has occured: " << e.what();
    freeMemory(shapes, size, nullptr);
    return 1;
  }

  freeMemory(shapes, size, nullptr);
}
