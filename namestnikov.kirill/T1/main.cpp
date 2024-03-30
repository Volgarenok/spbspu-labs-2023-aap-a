#include <iostream>
#include "circle.hpp"
#include "complexquad.hpp"
#include "rectangle.hpp"
#include "input_output_shapes.hpp"
#include "geometric_functions.hpp"

int main()
{
  using namespace namestnikov;
  Shape ** shapes = nullptr;
  size_t count = 0;
  try
  {
    shapes = inputShapes(std::cin, count);
    std::cout << std::fixed;
    std::cout.precision(1);
    outputShapes(std::cout, shapes, count);
    std::cout << "\n";
    point_t scalePoint = {0.0, 0.0};
    double scaleCoefficient = 0.0;
    std::cin >> scalePoint.x >> scalePoint.y >> scaleCoefficient;
    if (!std::cin)
    {
      throw std::invalid_argument("Error in input");
      return 1;
    }
    if (scaleCoefficient < 0)
    {
      throw std::invalid_argument("Scaling coefficient must be greater than zero");
    }
    for (size_t i = 0; i < count; ++i)
    {
      unsafeIsoScale(shapes[i], scalePoint, scaleCoefficient);
    }
    outputShapes(std::cout, shapes, count);
    std::cout << "\n";
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    deleteShapes(shapes, count);
    return 1;
  }
  deleteShapes(shapes, count);
}
