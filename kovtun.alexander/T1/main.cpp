#include <iostream>
#include <string>

#include "base_types.h"
#include "shape.h"
#include "rectangle.h"

int main()
{
  std::string instruction = "";
  kovtun::Shape ** shapes = new kovtun::Shape *[100]();

  for (size_t shapeIndex = 0; instruction != "SCALE"; shapeIndex++)
  {
    std::cin >> instruction;
    if (instruction == "RECTANGLE")
    {
      // uninitialized?
      kovtun::point_t rectanglePoints[2];
      for (size_t i = 0; i < 2; i++)
      {
        std::cin >> rectanglePoints[i].x >> rectanglePoints[i].y;
      }
      shapes[shapeIndex] = new kovtun::Rectangle(rectanglePoints[0], rectanglePoints[1]);
    }

    // ?
    if (!std::cin)
    {
      std::cerr << "bad input\n";
      return 1;
    }
  }

  shapes[0]->scale(4);
  std::cout << "center x: " << shapes[0]->getFrameRect().pos.x << " y: " << shapes[0]->getFrameRect().pos.y << '\n';
  std::cout << "width: " << shapes[0]->getFrameRect().width << '\n';
  std::cout << "height: " << shapes[0]->getFrameRect().height << '\n';
  std::cout << "area: " << shapes[0]->getArea() << '\n';
}

