#include <iostream>
#include <string>

#include "base_types.h"
#include "shape.h"
#include "rectangle.h"
#include "utils.h"

int main()
{
  kovtun::Shape* shapes[100] = {};
  size_t shapesCount = 0;
  try
  {
    shapesCount = kovtun::parseShapes(std::cin, shapes);
    kovtun::point_t scaleCenter = { 0.0, 0.0 };
    double scaleRatio = 0.0;
    std::cin >> scaleCenter.x >> scaleCenter.y >> scaleRatio;
    if (scaleRatio <= 0.0)
    {
      std::cerr << "scaling ratio must be positive\n";
      return 1;
    }

    if (shapesCount == 0)
    {
      std::cerr << "nothing to scale\n";
      return 2;
    }

    kovtun::showResult(std::cout, shapes, shapesCount);
    for (size_t i = 0; i < shapesCount; i++)
    {
      if (!shapes[i])
      {
        continue;
      }

      kovtun::isotropicScale(shapes[i], scaleCenter, scaleRatio);
    }
    kovtun::showResult(std::cout, shapes, shapesCount);
  }
  catch (...)
  {
    kovtun::removeShapes(shapes, shapesCount);
    std::cerr << "unexpected error occurred\n";
    return 3;
  }

  kovtun::removeShapes(shapes, shapesCount);

  return 0;
}

