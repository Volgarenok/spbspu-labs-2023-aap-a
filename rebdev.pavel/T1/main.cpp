#include <iostream>
#include <string>
#include "shape.hpp"
#include "concave.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "figureInputFunction.hpp"
#include "outputShapes.hpp"

int main()
{
  std::string figureName;

  rebdev::Shape * shapes[1000] = {};

  size_t numOfShape = 0;
  bool isScale = 0, figureError = 0;

  while (std::getline(std::cin, figureName, ' '))
  {
    if (figureName.find('\n') == 0)
    {
      figureName.erase(0, 1);
    }

    if (figureName.find("SCALE") != std::string::npos)
    {
      rebdev::point_t isoPoint = {0.0, 0.0};
      double k = 0;
      std::cin >> isoPoint.x >> isoPoint.y >> k;

      if (!std::cin)
      {
        break;
      }

      std::cout << std::fixed;
      std::cout.precision(1);
      rebdev::printShapes(shapes, numOfShape, std::cout);
      std::cout << '\n';
      try
      {
        rebdev::isoScale(shapes, numOfShape, isoPoint, k);
      }
      catch (const std::logic_error & e)
      {
        break;
      }
      isScale = 1;
      break;
    }
    else
    {
      try
      {
        shapes[numOfShape] = rebdev::newFigure(std::cin, figureName);
        numOfShape += (shapes[numOfShape] != nullptr);
      }
      catch (const std::exception & e)
      {
        figureError = 1;
      }
    }

    figureName.clear();
  }

  if (figureError)
  {
    std::cerr << "Some figure is incorrect!\n";
  }
  if (!isScale || (numOfShape == 0))
  {
    std::cerr << "Programm end without scale!\n";
    rebdev::deleteShapes(shapes, numOfShape);
    return 1;
  }

  rebdev::printShapes(shapes, numOfShape, std::cout);
  std::cout << '\n';

  rebdev::deleteShapes(shapes, numOfShape);

  return 0;
}
