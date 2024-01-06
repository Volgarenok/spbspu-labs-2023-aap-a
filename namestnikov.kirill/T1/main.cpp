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
    outputShapes(std::cout, count, shapes);
    point_t scalePoint;
    double scaleCoefficient = 0.0;
    std::cin >> scalePoint.x >> scalePoint.y >> scaleCoefficient;
    if (!std::cin)
    {
      throw std::invalid_argument("Error in input\n");
      return 1;
    }
    for (size_t i = 0; i < count; ++i)
    {
      try
      {
        isoScale(shapes[i], scalePoint, scaleCoefficient);
      }
      catch (...)
      {
        std::cerr << "Coefficient isn't right\n";
        return 1;
      }
    }
    outputShapes(std::cout, count, shapes);
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    deleteShapes(shapes, count);
    return 1;
  }
  deleteShapes(shapes, count);
}
