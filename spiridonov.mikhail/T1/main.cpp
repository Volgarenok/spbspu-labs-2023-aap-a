#include <iostream>
#include <string>
#include "baseTypes.hp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "compositeShape.hpp"
#include "concave.hpp"
#include "parallelogram.hpp"

int main()
{
  using namespace spiridonov;

  CompositeShape composite;

  std::string input;
  while (std::cin >> input)
  {
    if (input == "SCALE")
    {
      double centerX = 0.0, centerY = 0.0, scaleCoefficient = 0.0;
      std::cin >> centerX >> centerY >> scaleCoefficient;

      if (std::cin.fail())
      {
        std::cerr << "Error: Invalid scale parameters\n";
        return 1;
      }

      std::cout << "Before scaling:\n";
      for (size_t i = 0; i < composite.getShapesCount(); ++i)
      {
        Shape* shape = composite.getShape(i);
        std::cout << shape->getArea() << " " << shape->getFrameRect().pos.x - shape->getFrameRect().width / 2
          << " " << shape->getFrameRect().pos.y - shape->getFrameRect().height / 2
          << " " << shape->getFrameRect().pos.x + shape->getFrameRect().width / 2
          << " " << shape->getFrameRect().pos.y + shape->getFrameRect().height / 2 << "\n";
      }

      composite.scale(scaleCoefficient);

      std::cout << "After scaling:\n";
      for (size_t i = 0; i < composite.getShapesCount(); ++i)
      {
        Shape* shape = composite.getShape(i);
        std::cout << shape->getArea() << " " << shape->getFrameRect().pos.x - shape->getFrameRect().width / 2
          << " " << shape->getFrameRect().pos.y - shape->getFrameRect().height / 2
          << " " << shape->getFrameRect().pos.x + shape->getFrameRect().width / 2
          << " " << shape->getFrameRect().pos.y + shape->getFrameRect().height / 2 << "\n";
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
    
  return 0;
}

