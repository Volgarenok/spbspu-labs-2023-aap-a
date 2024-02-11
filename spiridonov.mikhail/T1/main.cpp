#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
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

  std::string input;
  while (std::cin >> input)
  {
    if (!input.empty())
    {
      try
      {
        if (input == "SCALE")
        {
          double centerX = 0.0, centerY = 0.0, scaleCoefficient = 0.0;
          std::cin >> centerX >> centerY >> scaleCoefficient;

          if (std::cin.fail() || scaleCoefficient < 0)
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
        else if (input == "RECTANGLE")
        {
          double width = 0.0, height = 0.0, x = 0.0, y = 0.0;
          std::cin >> width >> height >> x >> y;

          if (std::cin.fail())
          {
            std::cerr << "Error: Invalid rectangle parameters\n";
            return 1;
          }

          composite.addShape(new Rectangle(width, height, x, y));
        }
        else if (input == "CONCAVE")
        {
          double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0;
          std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

          if (std::cin.fail())
          {
            std::cerr << "Error: Invalid concave parameters\n";
            return 1;
          }

          composite.addShape(new Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }));
        }
        else if (input == "PARALLELOGRAM")
        {
          double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
          std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

          if (std::cin.fail())
          {
            std::cerr << "Error: Invalid parallelogram parameters\n";
            return 1;
          }

          composite.addShape(new Parallelogram(x1, x2, x3, y1, y2, y3));

        }
        else if (input == "END")
        {
          break;
        }
        else
        {
          std::cerr << "Error: Unknown command\n";

          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
      }
    }
  }

  return 0;
}
