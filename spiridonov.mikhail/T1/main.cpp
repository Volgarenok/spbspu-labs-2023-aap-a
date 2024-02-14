#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "compositeShape.hpp"
#include "concave.hpp"
#include "parallelogram.hpp"

int main()
{
  using namespace spiridonov;
  CompositeShape composite;
  std::string input = "";
  bool scaleCommandFound = false;
  bool shapesAdded = false;
  bool invalidShapeDetected = false;
  while (std::cin >> input)
  {
    if (!input.empty())
    {
      try
      {
        if (input == "SCALE")
        {
          scaleCommandFound = true;
          double centerX = 0.0, centerY = 0.0, scaleCoefficient = 0.0;
          std::cin >> centerX >> centerY >> scaleCoefficient;
          if (std::cin.fail() || scaleCoefficient <= 0)
          {
            std::cerr << "Error: Invalid scale command or scale coefficient\n";
            return 1;
          }
          if (composite.getShapesCount() == 0)
          {
            std::cerr << "Error: Nothing to scale\n";
            return 1;
          }
          std::cout << std::fixed << std::setprecision(1);
          for (size_t i = 0; i < composite.getShapesCount(); ++i)
          {
            Shape* shape = composite.getShape(i);
            rectangle_t frameRect = shape->getFrameRect();
            std::cout << shape->getArea() << " "
              << frameRect.pos.x - frameRect.width / 2 << " "
              << frameRect.pos.y - frameRect.height / 2 << " "
              << frameRect.pos.x + frameRect.width / 2 << " "
              << frameRect.pos.y + frameRect.height / 2 << "\n";
          }
          composite.scale(scaleCoefficient);
          for (size_t i = 0; i < composite.getShapesCount(); ++i)
          {
            Shape* shape = composite.getShape(i);
            rectangle_t frameRect = shape->getFrameRect();
            std::cout << shape->getArea() << " ";
            std::cout << std::setprecision(1) << " " << std::round((frameRect.pos.x - (frameRect.width / 2)) * 10) / 10;
            std::cout << std::setprecision(1) << " " << std::round((frameRect.pos.y - (frameRect.height / 2)) * 10) / 10;
            std::cout << std::setprecision(1) << " " << std::round((frameRect.pos.x + (frameRect.width / 2)) * 10) / 10;
            std::cout << std::setprecision(1) << " " << std::round((frameRect.pos.y + (frameRect.height / 2)) * 10) / 10 << "\n";
          }
        }
        else if (input == "MOVE")
        {
          double dx = 0.0, dy = 0.0;
          std::cin >> dx >> dy;
          if (std::cin.fail())
          {
            std::cerr << "Error: Invalid move parameters\n";
            return 1;
          }
          composite.move(dx, dy);
        }
        else if (input == "RECTANGLE")
        {
          shapesAdded = true;
          point_t p1 = {0, 0};
          point_t p2 = {0, 0};
          std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
          if (std::cin.fail() || p1.x >= p2.x || p2.y >= p2.y)
          {
            invalidShapeDetected = true;
            shapesAdded = false;
          }
          composite.addShape(new Rectangle(p1, p2));
        }
        else if (input == "CONCAVE")
        {
          shapesAdded = true;
          double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0;
          std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          if (std::cin.fail())
          {
            std::cerr << "Error: Invalid concave parameters\n";
            shapesAdded = false;
            return 1;
          }
          composite.addShape(new Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }));
        }
        else if (input == "PARALLELOGRAM")
        {
          shapesAdded = true;
          double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
          std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
          if (std::cin.fail())
          {
            std::cerr << "Error: Invalid parallelogram parameters\n";
            shapesAdded = false;
            return 1;
          }
          composite.addShape(new Parallelogram(x1, x2, x3, y1, y2, y3));
        }
        else if (input == "END")
        {
          break;
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
      }
    }
  }
  if (invalidShapeDetected)
  {
    std::cout << "Invalid shape detected\n";
    return 1;
  }
  if (!scaleCommandFound && shapesAdded)
  {
    std::cerr << "Error: Scaling command not found\n";
    return 1;
  }
  return 0;
}
