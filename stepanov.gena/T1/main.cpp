#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "square.hpp"
#include "input_output_shapes.hpp"
#include "isoScale.hpp"

int main()
{
  using namespace stepanov;
  Shape ** shapes = nullptr;
  size_t size_shapes = 0;
  point_t center = {0.0, 0.0};
  double ratio = 0.0;
  try
  {
    shapes = inputShapes(std::cin, size_shapes);
    outputShapes(std::cout, shapes, size_shapes);
    std::cin >> center.x >> center.y >> ratio;
    if (!std::cin || size_shapes == 0)
    {
      deleteShapes(shapes, size_shapes);
      throw std::invalid_argument("Wrong input scale");
    }
    if (ratio > 0)
    {
      isoScale(shapes, center, ratio, size_shapes);
      outputShapes(std::cout, shapes, size_shapes);
    }
    else
    {
      deleteShapes(shapes, size_shapes);
      throw std::invalid_argument("Ratio must be positive");

    }
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Error with memory allocation\n";
    return 1;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what();
    return 1;
  }
  deleteShapes(shapes, size_shapes);
  return 0;
}

