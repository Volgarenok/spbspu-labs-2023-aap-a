#include "utilities.hpp"

Shape* readShape()
{
  std::string type;
  std::cin >> type;

  if (type == "RECTANGLE")
  {
    float x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    float width = x2 - x1;
    float height = y2 - y1;

    float center_x = x1 + width / 2;
    float center_y = y1 + width / 2;

    return new Rectangle({center_x, center_y}, width, height);
  }
  else
  {
    std::cerr << "Invalid type of shape\n";
    return nullptr;
  }
}

void printShapeInfo(const Shape & shape)
{
  std::cout << shape.getArea() << " ";
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << frameRect.pos.x - frameRect.width / 2 << " "
            << frameRect.pos.y - frameRect.height / 2 << " "
            << frameRect.pos.x + frameRect.width / 2 << " "
            << frameRect.pos.y + frameRect.height / 2 << " ";
  std::cout << "\n";
}
