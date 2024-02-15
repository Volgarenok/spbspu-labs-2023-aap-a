#include <iostream>
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
  bool badShape = false;
  bool scaleCommandFound = false;
  while(std::cin >> input)
  {
    try
    {
      if (input == "RECTANGLE")
      {
        point_t p1, p2;
        std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
        if(!std::cin || p1.x >= p2.x || p1.y >= p2.y)
        {
          badShape = true;
        }
        composite.addShape(new Rectangle({p1.x, p1.y}, {p2.x, p2.y}));
      }
      else if (input == "CONCAVE")
      {
        double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (!std::cin)
        {
          badShape = true;
        }
        composite.addShape(new Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }));
      }
      else if (input == "PARALLELOGRAM")
      {
        double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (!std::cin)
        {
          badShape = true;
        }
        composite.addShape(new Parallelogram(x1, x2, x3, y1, y2, y3));
      }
      else if(input == "SCALE")
      {
        scaleCommandFound = true;
        double centerX = 0.0, centerY = 0.0, scaleCoefficient = 0.0;
        std::cin >> centerX >> centerY >> scaleCoefficient;
        if (std::cin && scaleCoefficient <= 0)
        {
          std::cerr << "Error: Invalid scale command or scale coefficient\n";
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
          std::cout << shape->getArea() << " "
          << frameRect.pos.x - frameRect.width / 2 << " "
          << frameRect.pos.y - frameRect.height / 2 << " "
          << frameRect.pos.x + frameRect.width / 2 << " "
          << frameRect.pos.y + frameRect.height / 2 << "\n";
        }
      }
      else if (badShape)
      {
        std::cerr << "Bad shape!" << '\n';
        return 0;
      }
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << '\n';
      return 1;
    }
    if (!scaleCommandFound && shapesAdded)
    {
      std::cerr << "Error: Scaling command not found\n";
      return 1;
    }
  }
}
