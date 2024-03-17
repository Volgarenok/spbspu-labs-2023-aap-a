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
      kovtun::point_t rectanglePoints[2];
      for (size_t i = 0; i < 2; i++)
      {
        std::cin >> rectanglePoints[i].x >> rectanglePoints[i].y;
      }
      shapes[shapeIndex] = new kovtun::Rectangle();
    }

    if (!std::cin)
    {
      std::cerr << "bad input\n";
      return 1;
    }
  }

}

