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
      // TODO: throw
    }


  }
  catch (...)
  {
    // TODO: clean shapes
  }



}

