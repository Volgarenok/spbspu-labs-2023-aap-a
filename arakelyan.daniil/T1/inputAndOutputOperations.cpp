#include "inputAndOutputOperations.hpp"

#include <stdexcept>

void arakelyan::inputScaleParam(const char *string, point_t &point, double &k)
{
  size_t wordLen = 5;
  string += wordLen;
  double arrayOfScaleData[3] = {};
  for (size_t i = 0; i < 3; i++)
  {
    while ((*string == ' ') || (*string == '\t'))
    {
      ++string;
    }
    char * endPtr;
    arrayOfScaleData[i] = std::strtod(string, & endPtr);

    string = endPtr;
  }

  point.x = arrayOfScaleData[0];
  point.y = arrayOfScaleData[1];
  k = arrayOfScaleData[2];
}

void arakelyan::shapeOutput(std::ostream &output, const Shape *const *shapes, const size_t shapesCount)
{
  output << std::fixed;
  output.precision(1);
  double totalArea = 0;
  for (size_t i = 0; i < shapesCount; i++)
  {
    totalArea += shapes[i]->getArea();
  }
  output << totalArea;
  for (size_t i = 0; i < shapesCount; i++)
  {
    rectangle_t rectCurrShape = shapes[i]->getFrameRect();
    double leftDownX = rectCurrShape.pos.x - (rectCurrShape.width / 2.0);
    double leftDownY = rectCurrShape.pos.y - (rectCurrShape.height / 2.0);
    double rigtUpX = rectCurrShape.pos.x + (rectCurrShape.width / 2.0);
    double rightUpY = rectCurrShape.pos.y + (rectCurrShape.height / 2.0);
    output << " " << leftDownX << " " << leftDownY << " " << rigtUpX << " " << rightUpY;
  }
  output << "\n";
}
