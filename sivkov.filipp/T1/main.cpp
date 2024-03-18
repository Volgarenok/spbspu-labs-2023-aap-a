#include <iostream>
#include "concave.hpp"
#include "complexquad.hpp"
#include "inputShape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "othersFun.hpp"
#include "output.hpp"

int main()
{
  using namespace sivkov;
  Shape** shapes = nullptr;
  size_t count = 0;
  try
  {
    shapes = inputShapes(std::cin, count);
    if (count == 0)
    {
      throw std::runtime_error("No shapes entered before scaling");
    }
    double k = 0;
    point_t center = { 0, 0 };
    std::cin >> center.x >> center.y >> k;
    if (!std::cin)
    {
      throw std::runtime_error("Invalid input for center coordinates and scaling factor");
    }
    std::cout << std::fixed;
    std::cout.precision(1);
    output(std::cout, shapes, count);
    std::cout << '\n';
    for (size_t i = 0; i < count; ++i)
    {
      doScale(shapes[i], center, k);
    }
    output(std::cout, shapes, count);
    std::cout << '\n';
    deleteMemory(shapes, count);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    if (shapes != nullptr)
    {
      deleteMemory(shapes, count);
    }
    return 1;
  }
  return 0;
}
