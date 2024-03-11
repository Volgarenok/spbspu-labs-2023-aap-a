#include <iostream>
#include <string>
#include <cmath>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  petuhov::Shape * shapes[1000] = {};
  size_t shapeCount = 0;
  std::string command;

  while (std::cin >> command && command != "SCALE")
  {
    if (command == "RECTANGLE")
    {
      float x1, y1, x2, y2 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2;
      float centerX = (x1 + x2) / 2;
      float centerY = (y1 + y2) / 2;
      float width = std::abs(x1 - x2);
      float height = std::abs(y1 - y2);
      shapes[shapeCount++] = new petuhov::Rectangle({centerX, centerY}, width, height);
    }
  }
}
