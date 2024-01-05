#include "figureInputFunction.hpp"
#include <math>

bool rebdev::isRectangle(point_t * pointsArr)
{
  if ((pointsArr[0].x_ > pointsArr[1].x_) && (pointsArr[0].y_ > pointsArr[1].y_))
  {
    pointsArr[0].x_ += pointsArr[1].x_;
    pointsArr[1].x_ = pointsArr[0].x_ - pointsArr[1].x_;
    pointsArr[0].x_ -= pointsArr[1].x_;

    pointsArr[0].y_ += pointsArr[1].y_;
    pointsArr[1].y_ = pointsArr[0].y_ - pointsArr[1].y_;
    pointsArr[0].y_ -= pointsArr[1].y_;
  }
  else if (!((pointsArr[0].x_ < pointsArr[1].x_) && (pointsArr[0].y_ < pointsArr[1].y_)))
  {
    return 0;
  }
  return 1;
};

bool rebdev::isConcave(point_t * pointsArr)
{
  for (int i = 0; i < 4; ++i)
  {
    if (isTriangle(pointArr[i], pointArr[(i + 1) % 4], pointArr[(i + 2) % 4]))
    {
      double arr[3];
      /*
      Проверка пренадлежит ли точка треугольнику:
      (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
      (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
      (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
      знаки должны быть одинаковы
      */
      for (int j = 0; j < 3; ++j)
      {
        arr[j] = (pointArr[(i + j) % 4].x_ - pointArr[(i + 3) % 4].x_)
          * (pointArr[(i + (j + 1) % 3) % 4].y_ - pointArr[(i + j) % 4].y_);
        arr[j] -= (pointArr[(i + (j + 1) % 3) % 4].x_ - pointArr[(i + j) % 4].x_)
          * (pointArr[(i + j) % 4].y_ - pointArr[(i + 3) % 4].y_);
      }

      bool identicalSigns = ((arr[0] > 0) && (arr[1] > 0) && (arr[2] > 0));
      identicalSigns = (identicalSigns || ((arr[0] < 0) && (arr[1] < 0) && (arr[2] < 0)));

      if (identicalSigns)
      {
        point_t newPointArr[4] = {pointArr[i], pointArr[(i + 1) % 4], pointArr[(i + 2) % 4], pointArr[(i + 3) % 4]};
        for (int i = 0; i < 4; ++i)
        {
          pointArr[i] = newPointArr[i];
        }
        return 1;
      }
    }
  }
  return 0;
};

bool rebdev::isPolygon(const point_t * pointsArr, const size_t size)
{
  if (size < 3)
  {
    return 0;
  }
  for (size_t i = 0; i < (size - 1); ++i)
  {
    for (size_t j = (i + 1); j < size; ++j)
    {
      if ((pointsArr[i].x_ == pointsArr[j].x_) && (pointsArr[i].y_ == pointsArr[j].y_))
      {
        return 0;
      }
    }
  }
  return 1;
};

bool rebdev::isTriangle(const point_t f, const point_t s, const point_t t)
{
    return (((t.x_ - f.x_) / (s.x_ - f.x_)) != ((t.y_ - f.y_) / (s.y_ - f.y_)));
};

bool rebdev::isNameCorrect(std::istream input, const int nameSize, const char * name)
{
char sym = 0;
  for (int i = 1; i < nameSize; ++i)
  {
    input >> sym;
    if (sym != name[i])
    {
      return 1;
    }
  }

  return 0;
};

bool rebdev::ipnutVertexs(std::istream input, point_t * vertexsArr, size_t & numOfVertexs)
{
  char sym = 0;
  size_t numOfVertexs_ = 0;
  bool afterPoint = 0;
  bool xy = 0;
  int afterPointNum = 1;
  double numNow = 0;

  vertexsArr = new point_t[1]{point_t{0.0, 0.0}};
  input >> std::noskipws;
  while (sym != '\n')
  {
    input >> sym;
    if (sym == '.')
    {
      afterPoint = 1;
    }
    else if (sym == ' ' && !((xy == 0) && (numOfVertexs_ == 0)))
    {
      afterPoint = 0;
      afterPointNum = 1;

      if (xy = 0)
      {
        newArrOfVertexs(vertexsArr, numOfVertexs_);
        vertexsArr[numOfVertexs_].x_ = numNow;
      }
      else
      {
        vertexsArr[numOfVertexs_].y_ = numNow;
        numOfVertexs_ += 1;
      }

      xy != xy;
      numNow = 0;
    }

    if (afterPoint)
    {
      numNow += (atof(sym - '0')) * pow(0.1, afterPointNum);
      afterPointNum += 1;
    }
    else
    {
      numNow *= 10;
      numNow += atof(sym - '0');
    }
  }
  input >> std::skipws;

  if (numOfVertexs != 0)
  {
    return (numOfVertexs == numOfVertexs_);
  }

  numOfVertexs = numOfVertexs_;
  return 1;
};

bool rebdev::figureIsCorrect(const point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber)
{
  if (figureNumber == 0)
  {
    return isRectangle(vertexsArr);
  }
  else  if (figureNumber == 1)
  {
    return isConcave(vertexsArr);
  }
  else  if (figureNumber == 2)
  {
    return isPolygon(vertexsArr, numOfVertexs);
  }
  return 0;
};

rebdev::Shape * rebdev::newFigure(const point_t * vertexsArr, const size_t numOfVertexs, const int figureNumber)
{
  if (figureNumber == 0)
  {
    return *Rectangle(vertexsArr[0], vertexsArr[1]);
  }
  else  if (figureNumber == 1)
  {
    return *Concave(vertexsArr);
  }
  else  if (figureNumber == 2)
  {
    return *Polygon(vertexsArr, numOfVertexs);
  }
};

void rebdev::newArrOfVertexs(point_t * vertexsArr, const size_t numOfVertexs)
{
  point_t newVertexsArr = new point_t[numOfVertexs + 1];

  for (size_t i = 0; i < numOfVertexs; ++i)
  {
    newVertexsArr[i] = vertexsArr[i];
  }

  delete[] vertexsArr;
  vertexsArr = newVertexsArr;
  newVertexsArr = nullptr;
  vertexsArr[numOfVertexs] = point_t{0.0, 0.0};
};
