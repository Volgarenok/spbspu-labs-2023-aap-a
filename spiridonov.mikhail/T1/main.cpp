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
#include "outFile.hpp"

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
          double centerX = 0.0;
          double centerY = 0.0;
          double scaleCoefficient = 0.0;
          std::cin >> centerX >> centerY >> scaleCoefficient;
          size_t count = composite.getShapesCount();
          if (std::cin.fail() || scaleCoefficient <= 0 || count == 0)
          {
            std::cerr << "Error: Invalid scale command, scale coefficient, or no shapes to scale\n";
            return 1;
          }
          std::cout << std::fixed << std::setprecision(1);
          outShapes(std::cout, composite, false, 1, centerX, centerY);
          std::cout << "\n";

          composite.setScaleCoefficient(scaleCoefficient);
          outShapes(std::cout, composite, true, scaleCoefficient, centerX, centerY);
          std::cout << "\n";
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
          double left = 0.0, bottom = 0.0, right = 0.0, top = 0.0;
          std::cin >> left >> bottom >> right >> top;
          if (std::cin.fail() || left >= right || bottom >= top)
          {
            invalidShapeDetected = true;
            shapesAdded = false;
          }
          else
          {
            Rectangle* rectangle = new Rectangle(left, bottom, right, top);
            composite.addShape(rectangle);
          }
        }

        else if (input == "CONCAVE")
        {
          shapesAdded = true;
          double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0;
          std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          double dir1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
          double dir2 = (x3 - x2) * (y4 - y2) - (y3 - y2) * (x4 - x2);
          double dir3 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);

          if (std::cin.fail() || (!(dir1 < 0 && dir2 < 0 && dir3 < 0) && !(dir1 > 0 && dir2 > 0 && dir3 > 0)))
          {
            invalidShapeDetected = true;
            shapesAdded = false;
          }
          Concave* concave = new Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
          composite.addShape(concave);
        }
        else if (input == "PARALLELOGRAM")
        {
          shapesAdded = true;
          double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
          std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
          if (std::cin.fail() || (y1 != y2 && y3 != y2))
          {
            invalidShapeDetected = true;
            shapesAdded = false;
          }
          Parallelogram* parallelogram = new Parallelogram(x1, x2, x3, y1, y2, y3);
          composite.addShape(parallelogram);
        }
        else if (input == "END")
        {
          break;
        }
        else
        {
          invalidShapeDetected = true;
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
    std::cerr << "Invalid shape detected\n";
    return 0;
  }
  if (!scaleCommandFound && shapesAdded)
  {
    std::cerr << "Error: Scaling command not found\n";
    return 1;
  }
  return 0;
}
