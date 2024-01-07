#include "inputshape.hpp"
#include "displayoutput.hpp"
#include "scale.hpp"

int main()
{
  using namespace marishin;
  Shape** myShapes = nullptr;
  size_t numberOfShapes = 0;
  point_t center = { 0, 0 };
  double scalingFactor = 0;

  try
  {
    myShapes = inputShape(std::cin, numberOfShapes);
    std::cin >> center.x >> center.y >> scalingFactor;

    outputShapesInfo(std::cout, numberOfShapes, myShapes);
    for (size_t i = 0; i < numberOfShapes; ++i)
    {
      scale(myShapes[i], center, scalingFactor);
    }
    outputShapesInfo(std::cout, numberOfShapes, myShapes);

    for (size_t i = 0; i < numberOfShapes; ++i)
    {
      delete myShapes[i];
    }
    delete[] myShapes;
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << "\n";
    for (size_t i = 0; i < numberOfShapes; ++i)
    {
      delete myShapes[i];
    }
    delete[] myShapes;
    return 1;
  }
}
