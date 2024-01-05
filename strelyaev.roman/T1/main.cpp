#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "inputShapes.hpp"

using shapeFunction = Shape * (*)(const char string[]);

Shape * getShape(const char string[])
{
  const char * space_index = strchr(string, ' ');
  for (int i = 0; i < 13; i++)
  {
    if (string[i] == *space_index)
    {
      if (i == 9)
      {
        return inputRectangle(string);
      }
      if (i == 8)
      {
        return inputTriangle(string);
      }
      if (i == 13)
      {
        return inputParallelogram(string);
      }
    }
  }
  return 0;
}

void isotrScale(Shape * shape, const point_t point, const double k)
{
  point_t start_pos = shape->getFrameRect().pos_;
  shape->move(point);
  shape->scale(k);
  double x = (point.x_ - start_pos.x_) * k;
  double y = (point.y_ - start_pos.y_) * k;
  shape->move(2);
}

int main ()
{
  std::cin >> std::noskipws;
  char * string = inputString(std::cin);
  std::cin >> std::skipws;
  //Shape * r1 = inputTriangle(string);
  Shape * shapes[10] = {};
  shapes[0] = getShape(string);
  std::cout << shapes[0]->getArea();
}
