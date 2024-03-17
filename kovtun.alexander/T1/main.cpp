#include <iostream>
#include <string>

#include "base_types.h"
#include "shape.h"
#include "rectangle.h"

int main()
{
  std::string shapeName = "";
  std::cin >> shapeName;

  kovtun::Shape * shape = nullptr;
  if (shapeName == "RECTANGLE")
  {
    kovtun::point_t rectanglePoints[2];
    for (size_t i = 0; i < 2; i++)
    {
      std::cin >> rectanglePoints[i].x >> rectanglePoints[i].y;
    }

    if (!std::cin)
    {
      std::cerr << "bad input\n";
      return 1;
    }

    shape = new kovtun::Rectangle();
  }
}

