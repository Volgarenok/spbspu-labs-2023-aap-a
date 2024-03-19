#include <iostream>
#include <string>
#include <cmath>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"
#include "circle.hpp"

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
        double x1 = 0;
        double y1 = 0;
        double x2 = 0;
        double y2 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        double centerX = (x1 + x2) / 2;
        double centerY = (y1 + y2) / 2;
        double width = x2 - x1;
        double height = y2 - y1;
        shapes[shapeCount++] = new petuhov::Rectangle({centerX, centerY}, width, height);
      }
      else if (command == "RING")
      {
        double x = 0;
        double y = 0;
        double innerRadius = 0;
        double outerRadius = 0;
        std::cin >> x >> y >> outerRadius >> innerRadius;
        shapes[shapeCount++] = new petuhov::Ring({x, y}, outerRadius, innerRadius);
      }
      else if (command == "REGULAR")
      {
        double x = 0;
        double y = 0;
        double radius = 0;
        int vertexCount;
        std::cin >> x >> y >> radius >> vertexCount;
        if (radius <= 0 || vertexCount <= 2)
        {
          throw std::invalid_argument("Invalid parameters for REGULAR.");
        }
        shapes[shapeCount++] = new petuhov::Regular({x, y}, radius, vertexCount);
      }
      else if (command == "CIRCLE")
      {
        double x = 0;
        double y = 0;
        double radius = 0;
        std::cin >> x >> y >> radius;
        shapes[shapeCount++] = new petuhov::Circle({x, y}, radius);
      }
    }
    catch (const std::invalid_argument &e)
    {
      errorFlag = true;
    }
  }

  if (command == "SCALE")
  {
    double scale_factor = 0;
    double scale_center_x = 0;
    double scale_center_y = 0;
    std::cin >> scale_center_x >> scale_center_y;
    std::cin >> scale_factor;
    for (size_t i = 0; i < shapeCount; i++)
    {
      try
      {
        std::cout << std::fixed;
        std::cout.precision(1);
        petuhov::point_t lower_left{
            shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2,
            shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2};
        petuhov::point_t upper_right{
            shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2,
            shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2};
        std::cout << shapes[i]->getArea() << " " << lower_left.x << " " << lower_left.y << " " << upper_right.x << " " << upper_right.y << "\n";
        shapes[i]->scale(scale_center_x, scale_center_y, scale_factor);
        lower_left = {
            shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2,
            shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2};
        upper_right = {
            shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2,
            shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2};
        std::cout << shapes[i]->getArea() << " " << lower_left.x << " " << lower_left.y << " " << upper_right.x << " " << upper_right.y << "\n";
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "Error while scaling: " << e.what() << "\n";
        return 2;
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
    return 2;
  }

  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }

  return 0;
}
