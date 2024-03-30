#include <iostream>
#include "inputOutputShapes.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "isoScale.hpp"

int main()
{
  using namespace skuratov;

  Shape** shapes = nullptr;
  size_t count = 0;
  try
  {
    shapes = inputShapes(std::cin, count);
    if (count == 0)
    {
      throw std::runtime_error("No shapes");
    }
    double k = 0;
    point_t center = { 0, 0 };
    std::cin >> center.x >> center.y >> k;
    if (!std::cin)
    {
      throw std::runtime_error("Invalid input");
    }
    std::cout << std::fixed;
    std::cout.precision(1);
    outputShapes(std::cout, shapes, count);
    std::cout << '\n';
    for (size_t i = 0; i < count; ++i)
    {
      isoScale(shapes[i], center, k);
    }
    outputShapes(std::cout, shapes, count);
    std::cout << '\n';
    clearingShapes(shapes, count);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception caught: " << e.what() << '\n';
    if (shapes != nullptr)
    {
      clearingShapes(shapes, count);
    }
    return 1;
  }
  return 0;
}
