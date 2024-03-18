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
      // TODO: throw?
    }

    if (shapesCount == 0)
    {
      // TODO: throw?
    }

    double totalArea = 0.0;
    for (size_t i = 0; i < shapesCount; i++)
    {
      if (!shapes[i])
      {
        continue;
      }

      totalArea += shapes[i]->getArea();
    }
    std::cout << totalArea << " ";
    for (size_t i = 0; i < shapesCount; i++)
    {
      if (!shapes[i])
      {
        continue;
      }

      kovtun::rectangle_t selfRect = shapes[i]->getFrameRect();
      kovtun::point_t leftBottomCorner = { selfRect.pos.x - selfRect.width / 2.0, selfRect.pos.y - selfRect.height / 2.0 };
      kovtun::point_t rightTopCorner = { selfRect.pos.x + selfRect.width / 2.0, selfRect.pos.y + selfRect.height / 2.0 };
      std::cout << leftBottomCorner.x << " " << leftBottomCorner.y << " " << rightTopCorner.x << " " << rightTopCorner.y << '\n';
    }

    for (size_t i = 0; i < shapesCount; i++)
    {
      if (!shapes[i])
      {
        continue;
      }

      kovtun::isotropicScale(shapes[i], scaleCenter, scaleRatio);
    }

    totalArea = 0.0;
    for (size_t i = 0; i < shapesCount; i++)
    {
      if (!shapes[i])
      {
        continue;
      }

      totalArea += shapes[i]->getArea();
    }
    std::cout << totalArea << " ";
    for (size_t i = 0; i < shapesCount; i++)
    {
      if (!shapes[i])
      {
        continue;
      }

      kovtun::rectangle_t selfRect = shapes[i]->getFrameRect();
      kovtun::point_t leftBottomCorner = { selfRect.pos.x - selfRect.width / 2.0, selfRect.pos.y - selfRect.height / 2.0 };
      kovtun::point_t rightTopCorner = { selfRect.pos.x + selfRect.width / 2.0, selfRect.pos.y + selfRect.height / 2.0 };
      std::cout << leftBottomCorner.x << " " << leftBottomCorner.y << " " << rightTopCorner.x << " " << rightTopCorner.y << '\n';
    }

  }
  catch (...)
  {
    // TODO: clean shapes
  }



}

