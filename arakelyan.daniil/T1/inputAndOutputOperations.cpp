#include <stdexcept>
#include "base-types.hpp"
#include "inputAndOutputOperations.hpp"
#include "shape-creation.hpp"
#include "shape.hpp"


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

char * arakelyan::inputString(std::istream &input)
{
  size_t arrSize = 10;

  size_t i = 0;
  char sym = 0;

  char * string = nullptr;
  string = new char[arrSize];
  if (string == nullptr)
  {
    throw std::logic_error("Cannot allocate memory for string!");
  }

  input >> std::noskipws;
  while (input >> sym)
  {
    if (!input)
    {
      delete [] string;
      throw std::logic_error("Input error!");
    }

    if (i == (arrSize - 1))
    {
      arrSize *= 2;

      char * tempBuffer = nullptr;

      tempBuffer = new char[arrSize];
      if (tempBuffer == nullptr)
      {
        delete [] string;
        throw std::bad_alloc();
      }

      for (size_t j = 0; j < i; j++)
      {
        tempBuffer[j] = string[j];
      }

      delete [] string;

      string = tempBuffer;
    }


    string[i] = sym;
    if (sym == '\n' && i == 0)
    {
      continue;
    }
    else if (sym == '\n' && i != 0)
    {
      break;
    }
    i++;
  }
  string[i] = '\0';
  if (*string == EOF)
  {
    delete [] string;
    throw std::logic_error("EOF here!");
  }
  input >> std::skipws;
  return string;
}

void arakelyan::shapeOutput(std::ostream &output, arakelyan::Shape **shapes, const size_t shapesCount)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapesCount; i++)
  {
    totalArea += shapes[i]->getArea();
  }
  for (size_t i = 0; i < shapesCount; i++)
  {
    rectangle_t rectCurrShape = shapes[i]->getFrameRect();
    double leftDownX = rectCurrShape.pos.x - (rectCurrShape.width / 2.0);
    double leftDownY = rectCurrShape.pos.y - (rectCurrShape.height / 2.0);
    double rigtUpX = rectCurrShape.pos.x + (rectCurrShape.width / 2.0);
    double rightUpY = rectCurrShape.pos.y + (rectCurrShape.height / 2.0);
    output << totalArea << " " << leftDownX << " " << leftDownY << " " << rigtUpX << " " << rightUpY << "\n";
  }
}