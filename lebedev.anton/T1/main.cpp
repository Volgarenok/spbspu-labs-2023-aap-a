#include <iostream>
#include <iomanip>
#include "input_output.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "complexquad.hpp"
#include "iso_scale.hpp"

int main()
{
  using namespace lebedev;
  Shape ** shapes = nullptr;
  size_t shapes_count = 0;
  point_t point = {0, 0};
  double ratio = 0.0;
  try
  {
    shapes = inputShapes(std::cin, shapes_count);
    std::cout << std::setprecision(1) << std::fixed;
    outputShapes(std::cout, shapes, shapes_count);
    std::cout << '\n';
    std::cin >> point.x >> point.y >> ratio;
    if (!std::cin)
    {
      throw std::invalid_argument("Error: wrong input in scale");
    }
    if (ratio <= 0)
    {
      throw std::invalid_argument("Error: scaling ratio must be greater than zero");
    }
    for (size_t i = 0; i < shapes_count; i++)
    {
      isoScale(shapes[i], point, ratio);
    }
    outputShapes(std::cout, shapes, shapes_count);
    std::cout << '\n';
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Error with memory allocation\n";
    return 1;
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << '\n';
    clearShapes(shapes, shapes_count);
    return 1;
  }
  clearShapes(shapes, shapes_count);
  return 0;
}
