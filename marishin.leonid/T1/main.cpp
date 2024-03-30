#include <iostream>
#include "ring.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "inputshape.hpp"
#include "displayoutput.hpp"
#include "scale.hpp"

int main()
{
  using namespace marishin;
  Shape** myShapes = nullptr;
  size_t numberOfShapes = 0;
  point_t center = {0, 0};
  double scalingFactor = 0.0;

  try
  {
    myShapes = inputShape(std::cin, numberOfShapes);
    std::cout << std::fixed;
    std::cout.precision(1);
    outputShapesInfo(std::cout, myShapes, numberOfShapes);
    std::cout << "\n";
    std::cin >> center.x >> center.y >> scalingFactor;

    if (!std::cin)
    {
      throw std::invalid_argument("incorrect input");
    }
    if (scalingFactor < 0)
    {
      throw std::invalid_argument("the coefficient must be positive");
    }
    for (size_t i = 0; i < numberOfShapes; i++)
    {
      isoScale(myShapes[i], center, scalingFactor);
    }
    outputShapesInfo(std::cout, myShapes, numberOfShapes);
    std::cout << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "memory allocation error";
    return 1;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    cleanupShapes(myShapes, numberOfShapes);
    return 1;
  }
  cleanupShapes(myShapes, numberOfShapes);
}
