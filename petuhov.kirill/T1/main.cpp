#include <iostream>
#include <string>
#include <cmath>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "regular.hpp"

int main()
{
  petuhov::Shape *shapes[1000] = {};
  size_t shapeCount = 0;
  std::string command;
  bool errorFlag = false;

  while (std::cin >> command && command != "SCALE")
  {
    try
    {
      if (command == "RECTANGLE")
      {
        float x1 = 0;
        float y1 = 0;
        float x2 = 0;
        float y2 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        float centerX = (x1 + x2) / 2;
        float centerY = (y1 + y2) / 2;
        float width = x1 - x2;
        float height = y1 - y2;
        shapes[shapeCount++] = new petuhov::Rectangle({centerX, centerY}, width, height);
      }
      else if (command == "CIRCLE")
      {
        float x = 0;
        float y = 0;
        float radius = 0;
        std::cin >> x >> y >> radius;
        if (radius <= 0)
        {
          throw std::invalid_argument("Invalid radius for CIRCLE.");
        }
        shapes[shapeCount++] = new petuhov::Circle({x, y}, radius);
      }
      else if (command == "REGULAR")
      {
        float x = 0;
        float y = 0;
        float radius = 0;
        int vertexCount;
        std::cin >> x >> y >> radius >> vertexCount;
        if (radius <= 0 || vertexCount <= 2)
        {
          throw std::invalid_argument("Invalid parameters for REGULAR.");
        }
        shapes[shapeCount++] = new petuhov::Regular({x, y}, radius, vertexCount);
      }
    }
    catch (const std::invalid_argument &e)
    {
      errorFlag = true;
    }
  }

  if (command == "SCALE")
  {
    float scale_factor = 0;
    petuhov::point_t scale_center = {0, 0};
    std::cin >> scale_center.x >> scale_center.y;
    std::cin >> scale_factor;
    for (size_t i = 0; i < shapeCount; i++)
    {
      try
      {
        std::cout << std::fixed;
        std::cout.precision(1);
        petuhov::point_t lower_left {
          shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2,
          shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2
        };
        petuhov::point_t upper_right {
          shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2,
          shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2
        };
        std::cout << shapes[i]->getArea() << " " << lower_left.x << " " << lower_left.y << " " << upper_right.x << " " << upper_right.y << "\n";
        shapes[i]->scale(scale_center, scale_factor);
        lower_left = {
          shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2,
          shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2
        };
        upper_right = {
          shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2,
          shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2
        };
        std::cout << shapes[i]->getArea() << " " << lower_left.x << " " << lower_left.y << " " << upper_right.x << " " << upper_right.y << "\n";
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "Error scaling shape: " << e.what() << std::endl;
        errorFlag = true;
      }
    }

    if (errorFlag)
    {
      std::cerr << "Errors were found in the description of some shapes." << std::endl;
    }
  }
  else
  {
    std::cerr << "SCALE command is missing or invalid." << std::endl;
    return 1;
  }

  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }

  return 0;
}
