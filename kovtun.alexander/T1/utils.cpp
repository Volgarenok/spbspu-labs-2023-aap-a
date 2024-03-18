#include "utils.h"

size_t kovtun::parseShapes(std::istream & in, Shape ** shapes)
{
  std::string instruction = "";
  size_t counter = 0;
  for (; instruction != "SCALE"; counter++)
  {
    in >> instruction;
    if (instruction == "RECTANGLE")
    {
      // uninitialized?
      kovtun::point_t rectanglePoints[2];
      for (size_t i = 0; i < 2; i++)
      {
        in >> rectanglePoints[i].x >> rectanglePoints[i].y;
      }
      shapes[counter] = new kovtun::Rectangle(rectanglePoints[0], rectanglePoints[1]);
    }
    else if (instruction == "ELLIPSE")
    {

    }
    else if (instruction == "CIRCLE")
    {

    }
    else if (instruction == "RING")
    {

    }

    // ?
    if (!std::cin)
    {
      std::cerr << "bad input\n";
      // clear shapes
      throw;
    }
  }

  return counter;
}

void kovtun::showResult(std::ostream &out, kovtun::Shape ** shapes, size_t shapesCount)
{
  double totalArea = 0.0;
  for (size_t i = 0; i < shapesCount; i++)
  {
    if (!shapes[i])
    {
      continue;
    }

    totalArea += shapes[i]->getArea();
  }
  out << totalArea << " ";
  for (size_t i = 0; i < shapesCount; i++)
  {
    if (!shapes[i])
    {
      continue;
    }

    kovtun::rectangle_t selfRect = shapes[i]->getFrameRect();
    kovtun::point_t leftBottomCorner = { selfRect.pos.x - selfRect.width / 2.0, selfRect.pos.y - selfRect.height / 2.0 };
    kovtun::point_t rightTopCorner = { selfRect.pos.x + selfRect.width / 2.0, selfRect.pos.y + selfRect.height / 2.0 };
    out << leftBottomCorner.x << " " << leftBottomCorner.y << " " << rightTopCorner.x << " " << rightTopCorner.y << '\n';
  }
}

void kovtun::isotropicScale(kovtun::Shape *shape, const kovtun::point_t & center, double ratio)
{
  point_t oldCenter = shape->getFrameRect().pos;
  shape->move(center);
  shape->scale(ratio);
  double dx = (oldCenter.x - center.x) * ratio;
  double dy = (oldCenter.y - center.y) * ratio;
  shape->move(dx, dy);
}

