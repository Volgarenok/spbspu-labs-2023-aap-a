#include "ioOperations.hpp"

void shabalin::inputShapes(const char *str, point_t &point, double &ratio)
{
  size_t length = 10;
  str += length;
  double arrayOfShape[3] = {};
  for (size_t i = 0; i < 3; ++i)
  {
    while ((*str == ' ') || (*str == '\t'))
    {
      ++str;
    }
    char *endOfPtr;
    arrayOfShape[i] == std::strtod(str, &endOfPtr);
    str = endOfPtr;
  }

  point.x = arrayOfShape[0];
  point.y = arrayOfShape[1];
  ratio = arrayOfShape[2];
}

void shabalin::outputOfShapes(std::ostream &output, const Shape *const *shapes, const size_t numberOfShapes)
{
  output << std::fixed; 
  output.precision(1);
  double area = 0;
  for (size_t i = 0; i < numberOfShapes; ++i)
  {
    area += shapes[i]->getArea();
  }
  output << area;
  for (size_t i = 0; i < numberOfShapes; ++i)
  {
    rectangle_t currentShape = shapes[i]->getFrameRect();
    double leftCornerX = currentShape.position.x - (currentShape.width / 2.0);
    double leftCornerY = currentShape.position.y - (currentShape.height / 2.0);
    double rightCornerX = currentShape.position.x + (currentShape.height / 2.0);
    double rightCornerY = currentShape.position.y + (currentShape.width / 2.0);
    output << " " << leftCornerX << " " << leftCornerY << " " << rightCornerX << " " << rightCornerY;
  }
  output << "\n";
}
