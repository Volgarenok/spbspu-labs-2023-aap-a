#include "utils.hpp"

size_t kovtun::parseShapes(std::istream & in, Shape ** shapes)
{
  std::string instruction = "";
  size_t counter = 0;
  while (in >> instruction && instruction != "SCALE")
  {
    if (instruction == "RECTANGLE")
    {
      kovtun::point_t rectanglePoints[2];
      for (size_t i = 0; i < 2; i++)
      {
        in >> rectanglePoints[i].x >> rectanglePoints[i].y;
      }

      if (rectanglePoints[0].x >= rectanglePoints[1].x || rectanglePoints[0].y >= rectanglePoints[1].y)
      {
        std::cerr << "incorrect shape options: " << instruction << "\n";
        continue;
      }

      shapes[counter] = new kovtun::Rectangle(rectanglePoints[0], rectanglePoints[1]);
    }
    else if (instruction == "ELLIPSE")
    {
      kovtun::point_t center = { 0.0, 0.0 };
      double verticalRadius = 0.0;
      double horizontalRadius = 0.0;
      std::cin >> center.x >> center.y >> verticalRadius >> horizontalRadius;

      if (verticalRadius <= 0.0 || horizontalRadius <= 0.0)
      {
        std::cerr << "incorrect shape options: " << instruction << "\n";
        continue;
      }

      shapes[counter] = new kovtun::Ellipse(center, verticalRadius, horizontalRadius);
    }
    else if (instruction == "CIRCLE")
    {
      kovtun::point_t center = { 0.0, 0.0 };
      double radius = 0.0;
      std::cin >> center.x >> center.y >> radius;

      if (radius <= 0.0)
      {
        std::cerr << "incorrect shape options: " << instruction << "\n";
        continue;
      }

      shapes[counter] = new kovtun::Circle(center, radius);
    }
    else if (instruction == "RING")
    {
      kovtun::point_t center = { 0.0, 0.0 };
      double outerRadius = 0.0;
      double innerRadius = 0.0;
      std::cin >> center.x >> center.y >> outerRadius >> innerRadius;

      if (outerRadius <= innerRadius || outerRadius <= 0.0 || innerRadius <= 0.0)
      {
        std::cerr << "incorrect shape options: " << instruction << "\n";
        continue;
      }

      shapes[counter] = new kovtun::Ring(center, outerRadius, innerRadius);
    }
    else
    {
      std::cerr << "unsupported shape\n";
      continue;
    }

    if (!std::cin)
    {
      std::cerr << "bad input\n";
      throw;
    }

    counter++;
  }

  if (counter == 0)
  {
    std::cerr << "nothing to scale\n";
    throw;
  }

  return counter;
}

void kovtun::showResult(std::ostream &out, kovtun::Shape ** shapes, size_t shapesCount)
{
  out.precision(1);
  out << std::fixed;

  double totalArea = 0.0;
  for (size_t i = 0; i < shapesCount; i++)
  {
    if (!shapes[i])
    {
      continue;
    }

    totalArea += shapes[i]->getArea();
  }
  out << totalArea;
  for (size_t i = 0; i < shapesCount; i++)
  {
    if (!shapes[i])
    {
      continue;
    }

    kovtun::rectangle_t rect = shapes[i]->getFrameRect();
    kovtun::point_t leftBottomCorner = { rect.pos.x - rect.width / 2.0, rect.pos.y - rect.height / 2.0 };
    kovtun::point_t rightTopCorner = { rect.pos.x + rect.width / 2.0, rect.pos.y + rect.height / 2.0 };
    out << " " << leftBottomCorner.x << " " << leftBottomCorner.y << " " << rightTopCorner.x << " " << rightTopCorner.y;
  }

  out << "\n";
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

void kovtun::removeShapes(kovtun::Shape ** shapes, size_t shapesCount)
{
  for (size_t i = 0; i < shapesCount; i++)
  {
    if (!shapes[i])
    {
      continue;
    }

    delete shapes[i];
  }
}

