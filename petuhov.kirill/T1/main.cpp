#include <iostream>
#include <string>
#include <cmath>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "regular.hpp"

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
    else if (command == "CIRCLE")
    {
      float x, y, radius = 0;
      std::cin >> x >> y >> radius;
      shapes[shapeCount++] = new petuhov::Circle({x, y}, radius);
    }
    else if (command == "REGULAR")
    {
      float x, y, radius = 0;
      int vertexCount = 0;
      std::cin >> x >> y >> radius >> vertexCount;
      shapes[shapeCount++] = new petuhov::Regular({x, y}, radius, vertexCount);
    }
    if (command == "SCALE")
    {
      float scale = 0;
      std::cin >> scale;
      for (size_t i = 0; i < shapeCount; i++)
      {
        shapes[i]->scale(scale);
      }
    }
    else
    {
      std::cerr << "SCALE command is missing or invalid." << std::endl;
      return 1;
    }
  }

  for (size_t i = 0; i < shapeCount; ++i) {
    delete shapes[i];
  }
}
