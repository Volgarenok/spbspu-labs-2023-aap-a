#include <iostream>
#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include "data_process.hpp"
#include "input.hpp"
#include "output.hpp"

int main()
{
  using namespace ishmuratov;
  Shape * shapes[1000]{};
  point_t position = { 0, 0 };
  double factor = 0;
  bool invalidShape = false;
  size_t count = 0;
  try
  {
    inputShape(std::cin, shapes, count);
  }
  catch (const std::invalid_argument & e)
  {
    invalidShape = true;
  }
  catch (const std::exception & e)
  {
    freeMemory(shapes, count);
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  try
  {
    std::cin >> position.x >> position.y >> factor;
    if (!std::cin)
    {
      throw std::runtime_error("Bad input!");
    }
    outputShape(std::cout, shapes, count);
    std::cout << "\n";
    for (size_t i = 0; i < count; ++i)
    {
      scaleShapes(shapes[i], position, factor);
    }
    outputShape(std::cout, shapes, count);
    std::cout << "\n";
  }
  catch (const std::exception & e)
  {
    freeMemory(shapes, count);
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  if (invalidShape)
  {
    freeMemory(shapes, count);
    std::cerr << "Invalid shape!\n";
    return 0;
  }
  freeMemory(shapes, count);
  return 0;
}
